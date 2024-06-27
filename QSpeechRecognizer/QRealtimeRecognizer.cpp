#include "QRealtimeRecognizer.h"

QRealtimeRecognizer::QRealtimeRecognizer(QObject *parent)
    : QObject{parent}

{}



bool QRealtimeRecognizer::InitRecognizer(int32_t num_threads ,QString method)
{
    sherpa_ncnn::RecognizerConfig config;
    //初始化默认配置
    SetDefaultConfigurations(config);
    //初始化模型
    config.model_config.tokens = "/path/to/tokens.txt";
    config.model_config.encoder_param = "/path/to/encoder_jit_trace-pnnx.ncnn.param";
    config.model_config.encoder_bin = "/path/to/encoder_jit_trace-pnnx.ncnn.bin";
    config.model_config.decoder_param = "/path/to/decoder_jit_trace-pnnx.ncnn.param";
    config.model_config.decoder_bin = "/path/to/decoder_jit_trace-pnnx.ncnn.bin";
    config.model_config.joiner_param = "/path/to/joiner_jit_trace-pnnx.ncnn.param";
    config.model_config.joiner_bin = "/path/to/joiner_jit_trace-pnnx.ncnn.bin";
    if (num_threads > 0) {
        config.model_config.encoder_opt.num_threads = num_threads;
        config.model_config.decoder_opt.num_threads = num_threads;
        config.model_config.joiner_opt.num_threads = num_threads;
    }
    if (method != "greedy_search" && method != "modified_beam_search") {
        qDebug() << "Invalid SHERPA_NCNN_METHOD" << method;
        return false;
    }
    config.decoder_config.method = method.toStdString();
    recognizer=std::make_unique<sherpa_ncnn::Recognizer>(config);
    stream=recognizer->CreateStream();
    return true;
}

QString QRealtimeRecognizer::BuildRecognizer(QByteArray & bytes)
{

    if(bytes.isEmpty())return QString();
    // 确保data的大小是4的倍数
    if (bytes.size() % sizeof(float) != 0) {
        // 处理错误，例如抛出异常或返回空向量
        return QString();
    }
    std::vector<float> floatVector;
    QDataStream data_stream(bytes);
    data_stream.setByteOrder(QDataStream::LittleEndian);
    while (!data_stream.atEnd()) {
        qint16 sample;
        data_stream >> sample;
        floatVector.push_back(sample);
    }
    std::string last_text;

    //开始推理
  //  auto begin = std::chrono::steady_clock::now();
   // Q_UNUSED(begin);
    if (1) {
        stream->AcceptWaveform(expected_sampling_rate, floatVector.data(),floatVector.size());
        // std::vector<float> tail_paddings(static_cast<int>(0.3 * expected_sampling_rate));  // 0.3 seconds at 16 kHz sample rate
        //  stream->AcceptWaveform(expected_sampling_rate, tail_paddings.data(),tail_paddings.size());
        stream->InputFinished();
        while (recognizer->IsReady(stream.get())) {
            recognizer->DecodeStream(stream.get());
        }
        bool is_endpoint = recognizer->IsEndpoint(stream.get());
        auto text = recognizer->GetResult(stream.get()).text;


        if (!text.empty() && last_text!=text) {
            last_text = text;
            std::transform(text.begin(), text.end(), text.begin(),
                           [](auto c) {
                               return std::tolower(c);
            });

        }
        if (is_endpoint) {
            emit finishRecognizer();
            if (!text.empty()) {
                (segment_index)++;
            }
            recognizer->Reset(stream.get());
        }
    }

    return  QString::fromStdString(last_text);
}


void QRealtimeRecognizer::SetDefaultConfigurations(sherpa_ncnn::RecognizerConfig &config) {
    int32_t num_threads = 4;
    config.model_config.encoder_opt.num_threads = num_threads;
    config.model_config.decoder_opt.num_threads = num_threads;
    config.model_config.joiner_opt.num_threads = num_threads;

    config.enable_endpoint = true;
    config.endpoint_config.rule1.min_trailing_silence = 2.4;
    config.endpoint_config.rule2.min_trailing_silence = 1.2;
    config.endpoint_config.rule3.min_utterance_length = 300;

    const float expected_sampling_rate = 16000;
    config.feat_config.sampling_rate = expected_sampling_rate;
    config.feat_config.feature_dim = 80;
}




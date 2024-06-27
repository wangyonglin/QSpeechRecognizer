#include "QKeywordSpotter.h"

QKeywordSpotter::QKeywordSpotter(QObject *parent)
    : QObject{parent}
{}

bool QKeywordSpotter::InitKeywordSpotter(int32_t num_threads ,QString method)
{
    Q_UNUSED(num_threads);Q_UNUSED(method);
    display =std::make_unique<sherpa_onnx::Display>(50);
    sherpa_onnx::KeywordSpotterConfig config= createKeywordSpotter();
    expected_sampling_rate=16000;
    kws= std::make_unique<sherpa_onnx::KeywordSpotter>(config);
    kws_stream=kws->CreateStream();
    return true;
}

void QKeywordSpotter::BuildRecognizer(QByteArray & bytes)
{
    if(bytes.isEmpty())return;
    // 确保data的大小是4的倍数
    if (bytes.size() % sizeof(float) != 0) {
        // 处理错误，例如抛出异常或返回空向量
        return;
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
    //auto begin = std::chrono::steady_clock::now();
    if (1) {
        kws_stream->AcceptWaveform(expected_sampling_rate, floatVector.data(),floatVector.size());
        // std::vector<float> tail_paddings(static_cast<int>(0.3 * expected_sampling_rate));  // 0.3 seconds at 16 kHz sample rate
        //  stream->AcceptWaveform(expected_sampling_rate, tail_paddings.data(),tail_paddings.size());
     //   kws_stream->InputFinished();
        while (kws->IsReady(kws_stream.get())) {
            kws->DecodeStream(kws_stream.get());
        }
        auto keyword = kws->GetResult(kws_stream.get()).keyword;
        if (!keyword.empty()) {
            emit finishRecognizer(segment_index,QString::fromStdString(keyword));
            segment_index += 1;
        }
    }



}
sherpa_onnx::KeywordSpotterConfig QKeywordSpotter:: createKeywordSpotter() {
    std::string keyword_spotter_path="/home/wangyonglin/QTestExamples/sherpa-onnx-kws-zipformer-wenetspeech-3.3M-2024-01-01";
    sherpa_onnx::FeatureExtractorConfig feat_config;
    feat_config.sampling_rate=16000;
    feat_config.feature_dim=80;
    sherpa_onnx::OnlineModelConfig model_config;
    model_config.transducer.encoder=keyword_spotter_path+"/encoder-epoch-12-avg-2-chunk-16-left-64.onnx";
    model_config.transducer.decoder=keyword_spotter_path+"/decoder-epoch-12-avg-2-chunk-16-left-64.onnx";
    model_config.transducer.joiner=keyword_spotter_path+"/joiner-epoch-12-avg-2-chunk-16-left-64.onnx";
    model_config.tokens=keyword_spotter_path+"/tokens.txt";
    model_config.num_threads=4;
    model_config.provider="cpu";
    model_config.debug=1;
    int32_t max_active_paths = 4;
    int32_t num_trailing_blanks = 1;
    float keywords_score = 1.0;
    float keywords_threshold = 0.25;
    const std::string &keywords_file=keyword_spotter_path+"/keywords.txt";
    sherpa_onnx::KeywordSpotterConfig config(feat_config,
                                             model_config,
                                             max_active_paths,
                                             num_trailing_blanks,
                                             keywords_score,
                                             keywords_threshold,
                                             keywords_file);

    return config;
}


# Ubuntu QT 语音识别

```
[ASR]
channel_count=1
sample_rate=16000
sample_size=16
speaker_play=off

[SHERPA_ONNX]
sampling_rate=16000
feature_dim=80
encoder="/home/wangyonglin/QSpeechRecognizer/models/sherpa-onnx-kws-zipformer-wenetspeech-3.3M-2024-01-01/encoder-epoch-12-avg-2-chunk-16-left-64.onnx"
decoder="/home/wangyonglin/QSpeechRecognizer/models/sherpa-onnx-kws-zipformer-wenetspeech-3.3M-2024-01-01/decoder-epoch-12-avg-2-chunk-16-left-64.onnx"
joiner="/home/wangyonglin/QSpeechRecognizer/models/sherpa-onnx-kws-zipformer-wenetspeech-3.3M-2024-01-01/joiner-epoch-12-avg-2-chunk-16-left-64.onnx"
tokens="/home/wangyonglin/QSpeechRecognizer/models/sherpa-onnx-kws-zipformer-wenetspeech-3.3M-2024-01-01/tokens.txt"
keywords="/home/wangyonglin/QSpeechRecognizer/models/sherpa-onnx-kws-zipformer-wenetspeech-3.3M-2024-01-01/keywords.txt"
num_threads=4
provider="cpu"
debug=0
start=on

[SHERPA_NCNN]
sampling_rate=16000
feature_dim=80
rule1_min_trailing_silence=2.4
rule2_min_trailing_silence=1.2
rule3_min_utterance_length=300
tokens = "/home/wangyonglin/QSpeechRecognizer/models/sherpa-ncnn-2022-09-30/tokens.txt"
encoder_param = "/home/wangyonglin/QSpeechRecognizer/models/sherpa-ncnn-2022-09-30/encoder_jit_trace-pnnx.ncnn.param"
encoder_bin = "/home/wangyonglin/QSpeechRecognizer/models/sherpa-ncnn-2022-09-30/encoder_jit_trace-pnnx.ncnn.bin"
decoder_param = "/home/wangyonglin/QSpeechRecognizer/models/sherpa-ncnn-2022-09-30/decoder_jit_trace-pnnx.ncnn.param"
decoder_bin = "/home/wangyonglin/QSpeechRecognizer/models/sherpa-ncnn-2022-09-30/decoder_jit_trace-pnnx.ncnn.bin"
joiner_param = "/home/wangyonglin/QSpeechRecognizer/models/sherpa-ncnn-2022-09-30/joiner_jit_trace-pnnx.ncnn.param"
joiner_bin = "/home/wangyonglin/QSpeechRecognizer/models/sherpa-ncnn-2022-09-30/joiner_jit_trace-pnnx.ncnn.bin"
#greedy_search or modified_beam_search
method ="modified_beam_search"
num_threads=4

```
### git remote add origin https://github.com/wangyonglin/QSpeechRecognizer.git

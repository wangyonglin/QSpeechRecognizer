
SHERPA_ONNX_BOOT_PATH = $$PWD/vendor/sherpa-onnx
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/_deps
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/_deps/simple-sentencepiece-src
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/_deps/kaldi_decoder-src
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/_deps/openfst-src/src/include
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/build/_deps/kaldifst-src
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/_deps/kaldifst-src
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/_deps/onnxruntime-src/include
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/_deps/eigen-src
INCLUDEPATH += $$SHERPA_ONNX_BOOT_PATH/build/_deps/kaldi_native_fbank-src
#QMAKE_RPATHDIR += $$SHERPA_ONNX_BUILD_PATH/_deps/onnxruntime-src/lib

SHERPA_NCNN_BOOT_PATH = $$PWD/vendor/sherpa-ncnn
INCLUDEPATH += $$SHERPA_NCNN_BOOT_PATH
INCLUDEPATH += $$SHERPA_NCNN_BOOT_PATH/build/_deps
INCLUDEPATH += $$SHERPA_NCNN_BOOT_PATH/build/_deps/ncnn-src/src
INCLUDEPATH += $$SHERPA_NCNN_BOOT_PATH/build/_deps/ncnn-build/src/

SOURCES +=  $$SHERPA_NCNN_BOOT_PATH/build/_deps/ncnn-src/src/mat.cpp \
    $$PWD/ASRSettings.cpp \
    $$PWD/QASRPlayer.cpp
SOURCES +=  $$SHERPA_NCNN_BOOT_PATH/build/_deps/ncnn-src/src/net.cpp

LIBS +=  $$SHERPA_NCNN_BOOT_PATH/build/lib/libncnn.a
LIBS +=  $$SHERPA_NCNN_BOOT_PATH/build/lib/libsherpa-ncnn-c-api.a
LIBS +=  $$SHERPA_NCNN_BOOT_PATH/build/lib/libsherpa-ncnn-core.a
LIBS +=  $$SHERPA_NCNN_BOOT_PATH/build/lib/libkaldi-native-fbank-core.a
LIBS +=  $$SHERPA_NCNN_BOOT_PATH/build/lib/libsherpa-ncnn-portaudio_static.a
LIBS  += -Wall -lpthread  -lgomp -lcblas

LIBS  += \
    $$SHERPA_ONNX_BOOT_PATH/build/_deps/onnxruntime-src/lib/libonnxruntime.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libcargs.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libsherpa-onnx-fst.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libespeak-ng.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libsherpa-onnx-fstfar.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libkaldi-decoder-core.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libsherpa-onnx-kaldifst-core.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libkaldi-native-fbank-core.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libsherpa-onnx-portaudio_static.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libpiper_phonemize.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libssentencepiece_core.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libsherpa-onnx-c-api.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libucd.a \
    $$SHERPA_ONNX_BOOT_PATH/build/lib/libsherpa-onnx-core.a




HEADERS += \
    $$PWD/ASRFrameName.h \
    $$PWD/ASRFrameText.h \
    $$PWD/ASRMicrophone.h \
    $$PWD/ASRSettings.h \
    $$PWD/ASRSpeaker.h \
    $$PWD/ASRThreader.h \
    $$PWD/QASRPlayer.h \
    $$PWD/QThreader.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/decodable-ctc.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/decodable-itf.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/eigen.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/faster-decoder.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/hash-list-inl.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/hash-list.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/kaldi-math.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/lattice-faster-decoder.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/lattice-simple-decoder.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/log.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/simple-decoder.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/stl-utils.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/feature-fbank.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/feature-functions.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/feature-mfcc.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/feature-window.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/kaldi-math.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/log.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/mel-computations.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/online-feature.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/rfft.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/whisper-feature.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/simple-sentencepiece-src/ssentencepiece/csrc/darts.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/simple-sentencepiece-src/ssentencepiece/csrc/ssentencepiece.h \
    $$PWD/vendor/sherpa-onnx/build/_deps/simple-sentencepiece-src/ssentencepiece/csrc/threadpool.h

SOURCES += \
    $$PWD/ASRFrameName.cpp \
    $$PWD/ASRFrameText.cpp \
    $$PWD/ASRMicrophone.cpp \
    $$PWD/ASRSpeaker.cpp \
    $$PWD/ASRThreader.cpp \
    $$PWD/QThreader.cpp \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/decodable-ctc.cc \
    # $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/eigen-test.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/eigen.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/faster-decoder.cc \
    # $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/hash-list-test.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/lattice-faster-decoder.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/lattice-simple-decoder.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_decoder-src/kaldi-decoder/csrc/simple-decoder.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/feature-fbank.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/feature-functions.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/feature-mfcc.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/feature-window.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/fftsg.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/kaldi-math.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/log.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/mel-computations.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/online-feature.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/rfft.cc \
    # $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/test-log.cc \
    # $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/test-online-fbank.cc \
    # $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/test-online-feature.cc \
    # $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/test-rfft.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/kaldi_native_fbank-src/kaldi-native-fbank/csrc/whisper-feature.cc \
    $$PWD/vendor/sherpa-onnx/build/_deps/simple-sentencepiece-src/ssentencepiece/csrc/ssentencepiece.cc \
    # $$PWD/vendor/sherpa-onnx/build/_deps/simple-sentencepiece-src/ssentencepiece/csrc/ssentencepiece_test.cc


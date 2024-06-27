#ifndef QKEYWORDSPOTTER_H
#define QKEYWORDSPOTTER_H



#include <QObject>
#include <QDebug>
#include <QDataStream>
#include "sherpa-onnx/csrc/display.h"
#include "sherpa-onnx/csrc/keyword-spotter.h"

class QKeywordSpotter : public QObject
{
    Q_OBJECT
public:


    explicit QKeywordSpotter(QObject *parent = nullptr);

    void BuildRecognizer(QByteArray & bytes);
    bool InitKeywordSpotter(int32_t num_threads=4, QString method="greedy_search");
signals:
    void finishRecognizer(qint32 id,const QString & name);
private:
    int32_t segment_index=0;
    int32_t expected_sampling_rate=16000;
    std::unique_ptr<sherpa_onnx::KeywordSpotter> kws;
    std::unique_ptr<sherpa_onnx::OnlineStream> kws_stream;
    std::unique_ptr<sherpa_onnx::Display> display;
    sherpa_onnx::KeywordSpotterConfig createKeywordSpotter();


};

#endif // QKEYWORDSPOTTER_H

#ifndef QREALTIMERECOGNIZER_H
#define QREALTIMERECOGNIZER_H

#include "sherpa-ncnn/csrc/display.h"
#include "sherpa-ncnn/csrc/recognizer.h"


#include <QObject>
#include <QDebug>
#include <QDataStream>
#include <QBuffer>
#include <QResizeEvent>




class QRealtimeRecognizer : public QObject
{
    Q_OBJECT
public:
    explicit QRealtimeRecognizer(QObject *parent = nullptr);
    bool InitRecognizer(int32_t num_threads=4, QString method="greedy_search");
    QString BuildRecognizer(QByteArray &bytes);

private:

    qint32 segment_index = 0;
    float expected_sampling_rate = 16000;
    std::unique_ptr<sherpa_ncnn::Recognizer> recognizer;
    std::unique_ptr<sherpa_ncnn::Stream> stream;
    void SetDefaultConfigurations(sherpa_ncnn::RecognizerConfig &config);
signals:
    void onTalkText(qint32 segment_index,const QString& last_text);
    void finishRecognizer();
};

#endif // QREALTIMERECOGNIZER_H

#ifndef QSPEAKER_H
#define QSPEAKER_H
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QFile>

#include <QAudio>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QIODevice>
#include <QAudioFormat>
#include <QAudioInput>
#include <QBuffer>
#include <QByteArray>
#include <QIODevice>
#include <QVector>
#include <QDataStream>
#include <QObject>
#include <QObject>

class QSpeaker : public QObject
{
    Q_OBJECT
public:
    explicit QSpeaker(QObject *parent = nullptr);

    bool InitSpeaker(int sampleRate=16000,int channelCount=1,int sampleSize=16);
    qint64 PlaySpeaker(QByteArray &bytes);

private:
    QAudioFormat qAudioFormat;
    QAudioOutput *out;
    QIODevice *audioIO;
    QTimer *audioPlayTimer;
    QThread *timerTHread;
};

#endif // QSPEAKER_H

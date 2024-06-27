#ifndef QMICROPHONE_H
#define QMICROPHONE_H

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

class QMicrophone : public QObject
{
    Q_OBJECT
public:
    explicit QMicrophone(QObject *parent = nullptr);
    ~QMicrophone();
    bool InitMicrophone(int sampleRate=16000, int channelCount=1, int sampleSize=16);
    QByteArray ReadAll();
    QAudioFormat format;



signals:
    void ReadRecording(QByteArray & bytes);
private: /*   QT audio capture  */
    QAudioInput* audioInput;
    QIODevice *qIODevice;
    QFile file; 			// 可以输出到文件，咱不用，直接播

};

#endif // QMICROPHONE_H

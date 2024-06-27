#include "QSpeaker.h"

QSpeaker::QSpeaker(QObject *parent)
    : QObject{parent}
{}
bool QSpeaker::InitSpeaker(int sampleRate,int channelCount,int sampleSize)
{
    qAudioFormat.setSampleRate(sampleRate);
    qAudioFormat.setChannelCount(channelCount);
    qAudioFormat.setSampleSize(sampleSize);
    qAudioFormat.setCodec("audio/pcm");
    qAudioFormat.setByteOrder(QAudioFormat::LittleEndian);
    qAudioFormat.setSampleType(QAudioFormat::SignedInt);

    out = new QAudioOutput(qAudioFormat,this);
    if (!out) {
        return false;
    }

    audioIO = out->start();
    return true;
}


qint64 QSpeaker::PlaySpeaker(QByteArray &bytes){
    if(bytes.isEmpty())return -1;
    if(audioIO){
       return audioIO->write((const char*)bytes.data(),bytes.size());
    }
    return -1;
}

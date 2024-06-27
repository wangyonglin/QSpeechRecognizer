#include "QSpeechThreader.h"


QSpeechThreader::QSpeechThreader(QObject *parent)
    : QThreader{parent},
    qMicrophone(new QMicrophone(parent)),
    qKeywordSpotter(new QKeywordSpotter(parent)),
    qSpeaker(new QSpeaker(parent)),
    qRealtimeRecognizer(new QRealtimeRecognizer(parent))

{
    connect(qKeywordSpotter,&QKeywordSpotter::finishRecognizer,[=](qint32 id,const QString & name){
        bRealtimeRecognizer=true;
        qDebug()  <<"id:"<< id << "name:" <<name;
    });


    connect(qRealtimeRecognizer,&QRealtimeRecognizer::finishRecognizer,[=](){
        bRealtimeRecognizer=false;
        listText.clear();
        qDebug() << "finishRealtimeRecognizer";
        emit finishRecognizer();
    });
}

void QSpeechThreader::InitVoiceAssistant(const QSize &size)
{
    qMicrophone->InitMicrophone();
    qKeywordSpotter->InitKeywordSpotter(4,"greedy_search");
    qRealtimeRecognizer->InitRecognizer();
    qSpeaker->InitSpeaker();
}

void QSpeechThreader::loopStart(QThreader::Priority pri)
{
    QThreader::loopStart(pri);
}

void QSpeechThreader::loopStop()
{
    QThreader::loopStop();
}

void QSpeechThreader::loopRunnable()
{
    QByteArray bytes= qMicrophone->ReadAll();
    if(bKeywordSpotter){
        qKeywordSpotter->BuildRecognizer(bytes);
        if(bRealtimeRecognizer){
           QString buffer = qRealtimeRecognizer->BuildRecognizer(bytes);
            if(!buffer.isEmpty()){
               listText.clear();
               listText.append(buffer);
               emit updateRecognizer();
            }
        }
    }
    // if(bSpeaker){
    //     qSpeaker->PlaySpeaker(bytes);
    // }
}


void QSpeechThreader::SetPlaySpeaker(bool bSpeaker)
{
    this->bSpeaker=bSpeaker;
}


void QSpeechThreader::SetKeywordSpotter(bool bKeywordSpotter)
{
    this->bKeywordSpotter=bKeywordSpotter;
}






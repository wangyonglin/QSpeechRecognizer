#ifndef QSPEECHTHREADER_H
#define QSPEECHTHREADER_H

#include <QObject>
#include "QMicrophone.h"
#include "QThreader.h"
#include "QSpeaker.h"
#include "QKeywordSpotter.h"
#include "QRealtimeRecognizer.h"


class QSpeechThreader : public QThreader
{
    Q_OBJECT
public:
    explicit QSpeechThreader(QObject *parent = nullptr);
    void InitVoiceAssistant(const QSize &size);
    virtual void loopStart(Priority pri = InheritPriority);
    virtual void loopStop();
    void SetPlaySpeaker(bool bspeaker=false);
    void SetKeywordSpotter(bool bKeywordSpotter);
    QVector<QString> listText;
private:

    bool bSpeaker=false;
    bool bRealtimeRecognizer=false;
    bool bKeywordSpotter=false;
    QMicrophone *qMicrophone=nullptr;
    QKeywordSpotter *qKeywordSpotter=nullptr;
    QRealtimeRecognizer *qRealtimeRecognizer=nullptr;
    QSpeaker *qSpeaker=nullptr;


private:
    virtual void loopRunnable();
signals:
    void finishRecognizer();
    void updateRecognizer();
};

#endif // QSPEECHTHREADER_H

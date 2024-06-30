#include "KylinSettings.h"

KylinSettings::KylinSettings(QObject *parent)
    : QSettings("/home/wangyonglin/QSpeechRecognizer/conf/kylin.conf", QSettings::IniFormat,parent)
{
    qDebug() << QCoreApplication::applicationDirPath();
}

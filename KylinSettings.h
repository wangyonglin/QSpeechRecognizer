#ifndef KYLINSETTINGS_H
#define KYLINSETTINGS_H

#include <QtCore/QCoreApplication>
#include <QObject>
#include <QSettings>
#include <QDebug>

class KylinSettings : public QSettings
{
    Q_OBJECT
public:
    explicit KylinSettings(QObject *parent = nullptr);

signals:
};

#endif // KYLINSETTINGS_H

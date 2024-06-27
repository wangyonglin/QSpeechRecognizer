#ifndef QSPEECHRECOGNIZER_H
#define QSPEECHRECOGNIZER_H

#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QPainterPath>
#include "QSpeechRecognizer/QSpeechThreader.h"

class QHBoxLayout;
class QLabel;
class QTimer;
class QSpeechRecognizer : public QWidget
{
    Q_OBJECT
public:
    explicit QSpeechRecognizer(QWidget *parent = nullptr);
    ~QSpeechRecognizer();



private:
    int strokeWidth;
    QColor strokeColor;
    int     textSize;//显示字体大小
    QColor  textColor;//字体颜色

    QSpeechThreader *qSpeechThreader;
    QString str;
    QTimer timer;
    QString GetTextByWidth(const QFontMetrics &fm, const QString &text, int width);
    QStringList GetTextLinesByRectSize(const QFontMetrics &fm, const QString &text, const QSize &size);
    void PaintStrokeText(QPainter *painter, const QRect &rect, const QString &text, const QFont &font, int strokeWidth = 2, const QColor &strokeColor = QColor(0xffffff), const QTextOption &option = QTextOption());
protected:
    virtual void paintEvent(QPaintEvent *event) override;

private slots:
    void hideTextLabel();
    void showTextLabel();
};

#endif // QSPEECHRECOGNIZER_H

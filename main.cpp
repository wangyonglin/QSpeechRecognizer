#include "MainWidget.h"

#include <QApplication>
#include <QApplication>
#include <QTextEdit>
#include <QTextCursor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    // QTextEdit edit;
    // edit.show();
    // QTextDocument *doc = edit.document();
    // QTextCursor cursor(doc);
    // cursor.beginEditBlock(); // 开始编辑块

    // // 模拟打字效果，每次插入一个字符
    // for (const QString &word : QStringList({"H", "e", "l", "l", "o", " ", "W", "o", "r", "l", "d", "!"})) {
    //     cursor.insertText(word); // 插入字符
    //     cursor.movePosition(QTextCursor::End); // 移动到文本末尾
    //     edit.setTextCursor(cursor); // 更新文本光标位置
    //     QCoreApplication::processEvents(QEventLoop::AllEvents, 100); // 刷新界面，实现打字效果
    // }

   // cursor.endEditBlock(); // 结束编辑块
    return a.exec();
}

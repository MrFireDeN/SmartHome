#ifndef CUSTOMTEXTBROWSER_H
#define CUSTOMTEXTBROWSER_H

#include <QTextBrowser>
#include <QMouseEvent>

class CustomTextBrowser : public QTextBrowser {
    Q_OBJECT
public:
    using QTextBrowser::QTextBrowser; // Использование конструктора базового класса

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            emit clicked();
        }
        QTextBrowser::mousePressEvent(event);
    }

signals:
    void clicked();
};

#endif // CUSTOMTEXTBROWSER_H

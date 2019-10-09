#ifndef SHAKEWINDOW_H
#define SHAKEWINDOW_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class ShakeWindow;
}

class ShakeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShakeWindow(QWidget *parent = 0);
    ~ShakeWindow();

    void SetInterval(int value);
    void SetSpace(int space);
    void SetDuration(int duration);
    void ShakeOnce();

private:
    Ui::ShakeWindow *ui;

    QTimer *shakeTimer;

    int shakeSpace;
    int shakeCount;
    int shakeLoop;
    int shakeDuration;

private slots:
    void ShakeShakeShake();
};

#endif // SHAKEWINDOW_H

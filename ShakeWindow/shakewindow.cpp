#include "shakewindow.h"
#include "ui_shakewindow.h"

ShakeWindow::ShakeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShakeWindow),
    shakeTimer(new QTimer(this)),
    shakeSpace(5),
    shakeCount(0),
    shakeLoop(3),
    shakeDuration(10)
{
    ui->setupUi(this);

    connect(shakeTimer, SIGNAL(timeout()),
            this, SLOT(ShakeShakeShake()));
}

ShakeWindow::~ShakeWindow()
{
    delete ui;
}

void ShakeWindow::SetInterval(int value)
{
    shakeTimer->setInterval(value);
}

void ShakeWindow::SetSpace(int space)
{
    shakeSpace = space;
}

void ShakeWindow::SetDuration(int duration)
{
    shakeDuration = duration;
}

void ShakeWindow::ShakeOnce()
{
    shakeTimer->start();
}

void ShakeWindow::ShakeShakeShake()
{
    if(isVisible())
    {
        QPoint curPoint = pos();
        QPoint newPoint;

        switch(shakeCount%4)
        {
        case 0:
            newPoint = QPoint(curPoint.x(), curPoint.y() + shakeSpace);
            break;
        case 1:
            newPoint = QPoint(curPoint.x() + shakeSpace, curPoint.y());
            break;
        case 2:
            newPoint = QPoint(curPoint.x(), curPoint.y() - shakeSpace);
            break;
        case 3:
            newPoint = QPoint(curPoint.x() - shakeSpace, curPoint.y());
            break;
        default:
            break;
        }
        move(newPoint);
        shakeCount++;

        if(shakeCount == shakeDuration)
        {
            shakeCount = 0;
            shakeTimer->stop();
        }
    }
}

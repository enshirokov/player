#include "mybutton.h"
#include <QBitmap>

MyButton::MyButton(QWidget* parent)
    : QPushButton(parent)
{

}

void MyButton::paintEvent(QPaintEvent* event)
{
    this->setFixedSize(50, 50);

    QPixmap pixmap(":/images/images/play.png");
    QPixmap newPixmap = pixmap.scaled(QSize(50,50),  Qt::KeepAspectRatio);

    //this->setMask(newPixmap.mask());
    //this->setIcon(pixmap);

    this->setText("play");
}


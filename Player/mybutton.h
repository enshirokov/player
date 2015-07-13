#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>


class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget* parent = 0);

private:
    void paintEvent(QPaintEvent*);
};

#endif // MYBUTTON_H

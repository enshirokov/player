#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFileInfo>
#include <QMimeData>
#include <QApplication>
#include <QDrag>
#include <QMediaPlaylist>


class MyListWidget : public QListWidget
{
    Q_OBJECT
public:
    MyListWidget(QMediaPlaylist* playlist, QWidget *parent = 0);

    void setNewCurrentItem();

    protected:
        void dragEnterEvent(QDragEnterEvent*);
        void dropEvent(QDropEvent*);
        // new methods:
        void mousePressEvent(QMouseEvent*);
        void mouseMoveEvent(QMouseEvent*);
        void dragMoveEvent(QDragMoveEvent*);

    private:
        QListWidgetItem *newCurrentItem;
        // new members:
        QPoint startPos;
        void startDrag();

        QMediaPlaylist* playlist;
};

#endif // MYLISTWODGET_H

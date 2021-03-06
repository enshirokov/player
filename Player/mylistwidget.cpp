#include "mylistwidget.h"

MyListWidget::MyListWidget(QMediaPlaylist* playlist, QWidget *parent) :
    QListWidget(parent),
    playlist(playlist)
{
    setAcceptDrops(true);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDropIndicatorShown(true);
    //setDragDropMode(QAbstractItemView::InternalMove);
    setAlternatingRowColors(true);
}

void MyListWidget::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls())
        e->acceptProposedAction();
}

void MyListWidget::dropEvent(QDropEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        QList<QUrl> urls = e->mimeData()->urls();
        foreach (QUrl url, urls){
            newCurrentItem = (new QListWidgetItem(url.toLocalFile(), this));
            playlist->addMedia(QMediaContent(url.toLocalFile()));
        }
        e->setDropAction(Qt::CopyAction);
        e->accept();
    }
}

void MyListWidget::setNewCurrentItem()
{
    setCurrentItem(newCurrentItem);
}

// new methods:

void MyListWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        startPos = e->pos();
    QListWidget::mousePressEvent(e);
}

void MyListWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton) {
        int distance = (e->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
            startDrag();
    }
    QListWidget::mouseMoveEvent(e);
}

void MyListWidget::startDrag()
{
    QListWidgetItem *item = currentItem();
       if (item) {
           QFileInfo fi(item->text());
           QUrl url = QUrl::fromLocalFile(fi.absoluteFilePath());
           QMimeData *mimeData = new QMimeData;
           mimeData->setUrls(QList<QUrl>() << url);
           mimeData->setText("Text");

           QDrag *drag = new QDrag(this);
           drag->setMimeData(mimeData);
           drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
       }
}


void MyListWidget::dragMoveEvent(QDragMoveEvent *e)
{
    if (e->mimeData()->hasUrls())
        e->acceptProposedAction();
}


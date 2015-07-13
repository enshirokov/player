#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QRegion>
#include <QBitmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    progressBar = new QProgressBar;
    progressBar->setTextVisible(false);
    //progressBar->setFixedHeight(progressBar->height()*0.02);

    progressBar->setStyleSheet("QProgressBar {border: 0px solid gray; max-height: 4px;} "
                          "QProgressBar::chunk {background: red}");

    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); //Set window to fixed size
    //this->setWindowFlags(Qt::CustomizeWindowHint); //Set window with no title bar
    this->setWindowFlags(Qt::FramelessWindowHint); //Set a frameless window

    this->setStyleSheet("QMainWindow {background-color: white;}"
                        "QListWidget {background-color: white;}"
                        "QPushButton {background-color: white; border-style: solid; border-color: red; border-width: 5px; border-radius: 25px; max-width : 40; max-height : 40; min-width : 40; min-height : 40;}");


    label = new QLabel;
    label->setText("Duration");


    playlist = new QMediaPlaylist;


    //playlist->addMedia(QUrl::fromLocalFile("C:/MagnetPull.mp3"));
    //playlist->addMedia(QUrl::fromLocalFile("C:/MagnetPull.mp3"));
    //playlist->addMedia(QUrl::fromLocalFile("C:/MagnetPull.mp3"));
    //playlist->setCurrentIndex(1);

    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(10);

    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(setPositionSlider(qint64)));


    //QRegion region(QRect(0, 0, 50, 50), QRegion::Ellipse);

    pushButtonPlay = new QPushButton("Play");
    connect(pushButtonPlay, SIGNAL(clicked()), this, SLOT(play()));

    pushButtonStop = new QPushButton("Stop");
    connect(pushButtonStop, SIGNAL(clicked()), this, SLOT(stop()));

    pushButtonPause = new QPushButton("Pause");
    connect(pushButtonPause, SIGNAL(clicked()), this, SLOT(pause()));


    //player->play();

    listWidgetPlaylist = new MyListWidget(playlist);//QListWidget;
    //listWidgetPlaylist->addItem("new");


    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(pushButtonPlay);
    hLayout->addWidget(pushButtonStop);
    hLayout->addWidget(pushButtonPause);


    QVBoxLayout* vLayout = new QVBoxLayout;
    //layout.addWidget(label);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(label);
    vLayout->addWidget(progressBar);
    vLayout->addWidget(listWidgetPlaylist);

    this->centralWidget()->setLayout(vLayout);
    //this->centralWidget()->setStyleSheet("QWidget { background-color: black; }");



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPositionSlider(qint64 t)
{
    QString str = "Duration:" + QTime(0, 0, 0).addMSecs(t).toString("hh:mm:ss");
    //qDebug() << str;

    label->setText(str);

    progressBar->setValue(t);


}

void MainWindow::play()
{
    if(playlist->isEmpty())
        return;


    qint64 t = player->duration();
    QString str = "All time:" + QTime(0, 0, 0).addMSecs(t).toString("hh:mm:ss");

    progressBar->setMinimum(0);
    progressBar->setMaximum(t);
    progressBar->setValue(0);

    player->play();

    qDebug() << str;
}

void MainWindow::stop()
{
    player->stop();

}

void MainWindow::pause()
{
    player->pause();
}


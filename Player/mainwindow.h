#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>

#include "mybutton.h"
#include "mylistwidget.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setPositionSlider(qint64);
    void play();
    void stop();
    void pause();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;

    QProgressBar* progressBar;
    QLabel* label;
    QPushButton* pushButtonPlay;
    QPushButton* pushButtonStop;
    QPushButton* pushButtonPause;
    //QListWidget* listWidgetPlaylist;
    MyListWidget* listWidgetPlaylist;


};

#endif // MAINWINDOW_H

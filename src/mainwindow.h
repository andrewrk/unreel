#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QFileInfo>
#include <QListWidgetItem>
#include <assert.h>

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
    void on_actionQuit_triggered();

    void on_pushButton_clicked();

    void on_videoListView_itemClicked(QListWidgetItem *);

    void handleVideoError(QMediaPlayer::Error);

private:
    Ui::MainWindow *ui;
    QList<QString> *filePaths;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QMediaPlaylist *playlist;
};

#endif // MAINWINDOW_H

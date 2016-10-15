#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QFileInfo>
#include <QListWidgetItem>

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

    void on_videoListView_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QList<QString> *filePaths;
    QMediaPlayer *player;
};

#endif // MAINWINDOW_H

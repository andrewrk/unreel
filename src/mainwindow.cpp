#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filePaths = new QList<QString>();
    player = new QMediaPlayer();
}

MainWindow::~MainWindow()
{
    delete filePaths;
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    //TODO: Filter only video files
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open Video", QString(), "Video Files (*)");
    filePaths->append(fileName);
    ui->videoListView->addItem(QFileInfo(fileName).baseName());
}

void MainWindow::on_videoListView_itemClicked(QListWidgetItem *item)
{

}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filePaths = new QList<QString>();

    player = new QMediaPlayer();
    bool ok = connect(player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(handleVideoError(QMediaPlayer::Error)));

    player->setVideoOutput(ui->videoWidget);
    ui->videoWidget->show();

    assert(ok);
}

MainWindow::~MainWindow()
{
    delete player;
    delete videoWidget;
    delete playlist;
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
        "Open Video", "~/Downloads", "Video Files (*)");
    player->setMedia(QUrl::fromLocalFile(fileName));
    player->play();
    videoWidget->updateGeometry();
    filePaths->append(fileName);
    ui->videoListView->addItem(QFileInfo(fileName).baseName());
}

void MainWindow::on_videoListView_itemClicked(QListWidgetItem *)
{
    int index = ui->videoListView->currentRow();
    player->setMedia(QUrl::fromLocalFile(filePaths->at(index)));
    player->play();
    videoWidget->updateGeometry();
}

void MainWindow::handleVideoError(QMediaPlayer::Error e)
{
    printf("%d\n", e);
}

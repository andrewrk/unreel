#include "mainwindow.h"
#include "ui_mainwindow.h"

struct project {
    QList<QString> filePaths;
    int index;
    qint64 position;
};

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
        "Open Video", QDir::homePath(), "Video Files (*)");
    playVideo(fileName);
    filePaths->append(fileName);
    ui->videoListView->addItem(QFileInfo(fileName).baseName());
}

void MainWindow::on_videoListView_itemClicked(QListWidgetItem *)
{
    int index = ui->videoListView->currentRow();
    playVideo(filePaths->at(index));
}

void MainWindow::handleVideoError(QMediaPlayer::Error e)
{
    printf("%d\n", e);
}

void MainWindow::playVideo(QString path) {
    player->setMedia(QUrl::fromLocalFile(path));
    player->play();
    ui->videoWidget->setAspectRatioMode(Qt::IgnoreAspectRatio);
    ui->videoWidget->setAspectRatioMode(Qt::KeepAspectRatio);
}

void MainWindow::saveProject() {

}

void MainWindow::loadFile() {
    QString projectFilePath = QDir(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation))
            .absoluteFilePath("project.unreel");

    QFile file(projectFilePath);
    if(!file.open(QIODevice::ReadOnly)) {
        return;
    }

    file.close();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(
        ui->stepButton, &QPushButton::clicked,
        &scene, &SortScene::step
    );

    connect(
       ui->togglePlayButton, &QPushButton::clicked,
       this, &MainWindow::togglePlay
    );

    ui->graphicsView->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::togglePlay()
{
    if(scene.isPlaying()){
        scene.pause();
        ui->togglePlayButton->setText("Play");
    }else{
        scene.play();
        ui->togglePlayButton->setText("Pause");
    }
}

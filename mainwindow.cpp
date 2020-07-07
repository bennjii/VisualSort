#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "insertionsortscene.h"
#include "bubblesortscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new BubbleSortScene)
{
    ui->setupUi(this);
    connect(
        ui->stepButton, &QPushButton::clicked,
        this, &MainWindow::step
    );

    connect(
       ui->togglePlayButton, &QPushButton::clicked,
       this, &MainWindow::togglePlay
    );

    connect(
        scene, &SortScene::finished,
        this, &MainWindow::togglePlay
    );

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::step()
{
    scene->step();
}

void MainWindow::togglePlay()
{
    if(scene->isPlaying()){
        scene->pause();
        ui->togglePlayButton->setText("Play");
    }else{
        scene->play();
        ui->togglePlayButton->setText("Pause");
    }
}

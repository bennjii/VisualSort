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
       ui->playButton, &QPushButton::clicked,
       &scene, &SortScene::play
    );

    ui->graphicsView->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


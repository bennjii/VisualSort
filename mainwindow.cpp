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
        scene.get(), &SortScene::finished,
        this, &MainWindow::togglePlay
    );

    connect(
        ui->algoBox, QOverload<int>::of(&QComboBox::activated),
        this, &MainWindow::selectAlgorithm
    );

    ui->graphicsView->setScene(scene.get());
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

void MainWindow::selectAlgorithm(int index)
{
    scene.reset();
    if(index == 0){
        // Bubble Sort
        scene = std::make_unique<BubbleSortScene>();
    }else if(index == 1){
        // Insertion Sort
        scene = std::make_unique<InsertionSortScene>();
    }

    ui->graphicsView->setScene(scene.get());
}

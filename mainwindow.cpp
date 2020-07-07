#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "insertionsortscene.h"
#include "bubblesortscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
       ui->resetButton, &QPushButton::clicked,
       this, &MainWindow::selectAlgorithm
    );

    connect(
        ui->algoBox, QOverload<int>::of(&QComboBox::activated),
        this, &MainWindow::selectAlgorithm
    );

    initiateScene<BubbleSortScene>();

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

template<class T>
void MainWindow::initiateScene()
{
    scene.reset();
    scene = std::make_unique<T>();

    ui->graphicsView->setScene(scene.get());

    connect(
        scene.get(), &SortScene::finished,
        this, &MainWindow::togglePlay
    );
}

void MainWindow::selectAlgorithm(int index)
{
    scene->pause();
    ui->togglePlayButton->setText("Play");

    index = ui->algoBox->currentIndex();

    scene.reset();
    if(index == 0){
        // Bubble Sort
        initiateScene<BubbleSortScene>();
    }else if(index == 1){
        // Insertion Sort
        initiateScene<InsertionSortScene>();
    }

    ui->graphicsView->setScene(scene.get());
}

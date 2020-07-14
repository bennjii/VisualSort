#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sortscene.h"
#include <QMainWindow>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    template<class T>
    void initiateScene();

    static constexpr QColor normal = QColor(255, 209, 217);
    static constexpr QColor completed = QColor(162, 234, 147);
    static constexpr QColor checking = QColor(234, 219, 147);


public slots:
    void togglePlay();
    void step();
    void selectAlgorithm(int index);



private:
    Ui::MainWindow *ui;
    std::unique_ptr<SortScene> scene;
};
#endif // MAINWINDOW_H

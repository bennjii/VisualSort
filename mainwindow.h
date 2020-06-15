#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sortscene.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void togglePlay();

private:
    Ui::MainWindow *ui;
    SortScene scene;
};
#endif // MAINWINDOW_H

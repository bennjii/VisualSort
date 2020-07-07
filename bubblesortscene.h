#ifndef BUBBLESORTSCENE_H
#define BUBBLESORTSCENE_H

#include "sortscene.h"
#include "mainwindow.h"

class BubbleSortScene : public SortScene
{
    Q_OBJECT
public:
    BubbleSortScene();

    void step() override;

private:
    int pos = 0;
    int sortedCount = 0;
};

#endif // BUBBLESORTSCENE_H

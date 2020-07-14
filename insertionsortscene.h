#ifndef INSERTIONSORTSCENE_H
#define INSERTIONSORTSCENE_H

#include "sortscene.h"
#include "mainwindow.h"

class InsertionSortScene : public SortScene
{
    Q_OBJECT
public:
    InsertionSortScene();
    void step() override;

private:
    int pos = 0;
    int sortedCount = 0;
};

#endif // INSERTIONSORTSCENE_H

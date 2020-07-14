#include "bubblesortscene.h"

BubbleSortScene::BubbleSortScene()
{

}

void BubbleSortScene::step() {
    if(sortedCount == getBarCount()){
        setColour(0, MainWindow::completed);
        setColour(1, MainWindow::completed);
        emit finished();
        return;
    }

    if(!compare(pos, pos + 1)){
        swap(pos, pos + 1);

        setColour(pos, MainWindow::checking);
        setColour(pos+1, MainWindow::checking);
    }else{
        if(sortedCount < getBarCount() - 2){
            setColour(pos, MainWindow::normal);
            setColour(pos+1, MainWindow::normal);
        }

        ++pos;
        if(pos >= (getBarCount() - sortedCount) - 1) {
            setColour((getBarCount() - 1) - sortedCount, MainWindow::completed);
            pos = 0;
            ++sortedCount;
        }

        if(sortedCount < getBarCount() - 1){
            setColour(pos, MainWindow::normal);
            setColour(pos+1, MainWindow::normal);
        }

        if(pos >= (getBarCount() - sortedCount) - 1) {
            setColour(getBarCount() - sortedCount, MainWindow::completed);
        }
    }
}

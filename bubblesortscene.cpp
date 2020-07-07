#include "bubblesortscene.h"

BubbleSortScene::BubbleSortScene()
{

}

void BubbleSortScene::step() {
    if(sortedCount == getBarCount()){
        setColour(0, QColor(0,255,0));
        setColour(1, QColor(0,255,0));
        emit finished();
        return;
    }

    if(!compare(pos, pos + 1)){
        swap(pos, pos + 1);

        setColour(pos, QColor(255,255,0));
        setColour(pos+1, QColor(255,255,0));
    }else{
        if(sortedCount < getBarCount() - 2){
            setColour(pos, QColor(255,255,255));
            setColour(pos+1, QColor(255,255,255));
        }

        ++pos;
        if(pos >= (getBarCount() - sortedCount) - 1) {
            setColour((getBarCount() - 1) - sortedCount, QColor(0,255,0));
            pos = 0;
            ++sortedCount;
        }

        if(sortedCount < getBarCount() - 1){
            setColour(pos, QColor(255,255,255));
            setColour(pos+1, QColor(255,255,255));
        }

        if(pos >= (getBarCount() - sortedCount) - 1) {
            setColour(getBarCount() - sortedCount, QColor(0,255,0));
        }
    }
}

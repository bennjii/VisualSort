#include "insertionsortscene.h"

InsertionSortScene::InsertionSortScene()
{

}

void InsertionSortScene::step()
{
    if(sortedCount == getBarCount()){
        emit finished();
        return;
    }

    if(pos == -1 || compare(pos, pos+1)){
        setColour(pos + 1, QColor(0,255,0));

        pos = sortedCount;
        ++sortedCount;
    }else{
        swap(pos, pos+1);
        --pos;
    }
}

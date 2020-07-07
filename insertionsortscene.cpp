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
        pos = sortedCount;
        ++sortedCount;
    }else{
        swap(pos, pos+1);
        --pos;
    }
}


//void InsertionSortScene::renderFrame()
//{
//    if(v[i] == queued)  setColour(0, QColor(8,55,255));
//    else setColour(0, QColor(0,255,0));
//}

#include "sortscene.h"

SortScene::SortScene()
{
    for(int i = 0; i < barCount; i++){
        bars.push_back(
                addRect(i * (barWidth + barGap) , -barWidth * (i + 1), barWidth, barWidth * (i + 1))
        );

    }
}

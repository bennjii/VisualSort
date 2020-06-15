#include "sortscene.h"

#include <QGraphicsRectItem>
#include <algorithm>
#include <random>

SortScene::SortScene()
{
    for(int i = 0; i < barCount; i++){
        bars.push_back(addRect(
            i * (barWidth + barGap),
            -barWidth * (i + 1),
            barWidth,
            barWidth * (i + 1)
        ));
    }

    shuffle();
}

void SortScene::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(bars.begin(), bars.end(), g);

    for(int i = 0; i < bars.size(); i++){
        updatePos(i);
    }
}

void SortScene::updatePos(int i)
{
    auto rect = bars[i]->rect();
    rect.moveLeft(i * (barWidth + barGap));
    bars[i]->setRect(rect);
}

void SortScene::step(){
    if(bars[pos]->rect().height() > bars[pos + 1]->rect().height()){
        swap(pos, pos + 1);
    }

    ++pos;

    if(pos > barCount - 2) {
        pos = 0;
    }

    toggling = !toggling;
}

void SortScene::swap(int first, int second)
{
    std::swap(bars[first], bars[second]);

    updatePos(first);
    updatePos(second);
}

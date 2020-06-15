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
    }else{
        bars[pos]->setBrush(QColor(255,255,255));
        bars[pos + 1]->setBrush(QColor(255,255,255));

        ++pos;
        if(pos >= barCount - 1) {
            pos = 0;
        }

        bars[pos]->setBrush(QColor(255,0,0));
        bars[pos + 1]->setBrush(QColor(255,0,0));
    }
}

void SortScene::swap(int first, int second)
{
    std::swap(bars[first], bars[second]);
    bars[pos]->setBrush(QColor(255,255,0));
    bars[pos + 1]->setBrush(QColor(255,255,0));

    updatePos(first);
    updatePos(second);
}

#include "sortscene.h"

#include <QGraphicsRectItem>
#include <QTimer>
#include <algorithm>
#include <random>

SortScene::SortScene()
{
    connect(
       &timer, &QTimer::timeout,
       this, &SortScene::step
    );

    for(int i = 0; i < barCount - sortedCount; i++){
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
    if(sortedCount == barCount){
        bars[0]->setBrush(QColor(0,255,0));
        bars[1]->setBrush(QColor(0,255,0));
        return;
    }

    if(bars[pos]->rect().height() > bars[pos + 1]->rect().height()){
        swap(pos, pos + 1);
    }else{
        if(sortedCount < barCount - 2){
            bars[pos]->setBrush(QColor(255,255,255));
            bars[pos + 1]->setBrush(QColor(255,255,255));
        }

        ++pos;
        if(pos >= (barCount - sortedCount) - 1) {
            bars[(barCount - 1) - sortedCount]->setBrush(QColor(0,255,0));
            pos = 0;
            ++sortedCount;
        }

        if(sortedCount < barCount - 1){
            bars[pos]->setBrush(QColor(255,0,0));
            bars[pos + 1]->setBrush(QColor(255,0,0));
        }

        if(pos >= (barCount - sortedCount) - 1) {
            bars[(barCount - sortedCount)]->setBrush(QColor(0,255,0));
        }
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

void SortScene::play()
{
    timer.start(delay);
}

void SortScene::stop()
{
    timer.stop();
}

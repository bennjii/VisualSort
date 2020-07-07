#include "sortscene.h"
#include "mainwindow.h"

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
        &MainWindow::togglePlay;
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

void SortScene::setColour(int index, const QColor &colour)
{
    bars[index]->setBrush(colour);
}

void SortScene::setColourRange(int min, int max, const QColor &colour)
{
    for(int i = min; i < max; i++){
        bars[i]->setBrush(colour);
    }
}

bool SortScene::compare(int first, int second)
{
    return bars[first]->rect().height() < bars[second]->rect().height();
}

int SortScene::getBarCount(){
    return barCount;
}

void SortScene::swap(int first, int second)
{
    std::swap(bars[first], bars[second]);

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

void SortScene::pause()
{
    timer.stop();
}

bool SortScene::isPlaying() {
    return timer.isActive();
}

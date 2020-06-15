#ifndef SORTSCENE_H
#define SORTSCENE_H

#include <QGraphicsScene>
#include <QVector>

class SortScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SortScene();

    void shuffle();

private:
    void updatePos(int i);

    QVector<QGraphicsRectItem*> bars;
    int barCount = 10;
    int barWidth = 50;
    int barGap = 5;

};

#endif // SORTSCENE_H

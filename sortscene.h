#ifndef SORTSCENE_H
#define SORTSCENE_H

#include <QGraphicsScene>
#include <QVector>

class SortScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SortScene();

private:
    QVector<QGraphicsRectItem*> bars;
    int barCount = 10;
    int barWidth = 50;
    float barGap = 5;

};

#endif // SORTSCENE_H

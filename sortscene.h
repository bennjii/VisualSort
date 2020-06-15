#ifndef SORTSCENE_H
#define SORTSCENE_H

#include <QGraphicsScene>
#include <QVector>

class SortScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SortScene();

 public slots:
    void step();
    void shuffle();
    void swap(int first, int second);

private:
    void updatePos(int i);

    QVector<QGraphicsRectItem*> bars;
    int barCount = 10;
    int barWidth = 50;
    int barGap = 5;

    int pos = 0;
    bool toggling = false;
};

#endif // SORTSCENE_H

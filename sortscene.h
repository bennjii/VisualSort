#ifndef SORTSCENE_H
#define SORTSCENE_H

#include <QGraphicsScene>
#include <QVector>
#include <QTimer>

class SortScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SortScene();
    bool isPlaying();

 public slots:
    void step();
    void play();
    void stop();
    void pause();

    void shuffle();
    void swap(int first, int second);

private:
    void updatePos(int i);

    QVector<QGraphicsRectItem*> bars;
    int barCount = 10;
    int barWidth = 50;
    int barGap = 5;

    int sortedCount = 0;
    int pos = 0;

    int delay = 100;

    QTimer timer;
};

#endif // SORTSCENE_H

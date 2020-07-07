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
    bool compare(int first, int second);

    int getBarCount();

 public slots:
    virtual void step();
    void play();
    void stop();
    void pause();

    void shuffle();
    void swap(int first, int second);
    void setColour(int i, const QColor &colour);

private:
    void updatePos(int i);

    QVector<QGraphicsRectItem*> bars;
    int barCount = 13;
    int barWidth = 40;
    int barGap = 5;

    int sortedCount = 0;
    int pos = 0;

    int delay = 25;

    QTimer timer;
};

#endif // SORTSCENE_H

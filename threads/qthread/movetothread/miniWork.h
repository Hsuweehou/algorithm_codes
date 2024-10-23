#ifndef MINIWORK1_H
#define MINIWORK1_H

#include <QObject>

class miniWork : public QObject
{
    Q_OBJECT

public:
    miniWork();

    void printFunc();

public slots:
    void doMiniWork();
    void doMiniWork2();
    void doMiniWork3();

signals:
    void testDoMiniWork3();
};

#endif
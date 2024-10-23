#ifndef WORKER_H
#define WORKER_H
 
#include <QThread>
 
class Worker : public QThread
{
public:
    explicit Worker();
    ~Worker();
    void printFunc();

protected:
    void run();
 
 
};
 
#endif // WORKER_H
#include "miniWorker.h"
#include <QDebug>
 
Worker::Worker(){}
Worker::~Worker(){}

void Worker::run()
{
    qDebug()<<"子线程ThreadID: "<<QThread::currentThreadId();
}
 
void Worker::printFunc()
{
    qDebug()<<"子线程成员函数ThreadID: "<<QThread::currentThreadId();
}
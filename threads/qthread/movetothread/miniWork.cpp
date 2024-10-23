#include "miniWork.h"
#include <QDebug>
#include <QThread>

miniWork::miniWork()
{
}


void miniWork::printFunc(){
    qDebug() << "成员函数ThreadID:"<<QThread::currentThreadId();
}

void miniWork::doMiniWork(){
    qDebug() << "doWork ThreadID:"<<QThread::currentThreadId();
}


void miniWork::doMiniWork2()
{
    qDebug() << "doWork2 ThreadID:"<<QThread::currentThreadId();
}
 
void miniWork::doMiniWork3()
{
    qDebug() << "doWork3 ThreadID:"<<QThread::currentThreadId();
}

/*void miniWork::testDoMiniWork3(){
    qDebug() << "主函数ThreadID:"<<QThread::currentThreadId();
}*/
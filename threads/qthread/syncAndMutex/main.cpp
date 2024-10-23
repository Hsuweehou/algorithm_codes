#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "shareValue.h"
#include "qMutex.cpp"
#include "qsemaphore.cpp"

int sharedValue11 = 0;

void qmutex(){

    MyThread thread1;
    MyThread thread2;
 
    thread1.start();
    thread2.start();
 
    thread1.wait();
    thread2.wait();
 
    qDebug() << "Final Shared Value: " << sharedValue11 << "/n";
}

void testQSemaphore(){

    MyThreadSema thread1; // 创建线程对象1
    MyThreadSema thread2; // 创建线程对象2
    MyThreadSema thread3; // 创建线程对象3
 
    thread1.start(); // 启动线程1
    thread2.start(); // 启动线程2
    thread3.start(); // 启动线程3
 
    thread1.wait(); // 等待线程1结束
    thread2.wait(); // 等待线程2结束
    thread3.wait(); // 等待线程3结束

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testQSemaphore();
    //qmutex();
    return a.exec();
}
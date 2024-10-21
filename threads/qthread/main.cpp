#include <iostream>
#include <QDebug>
#include "miniWorker.h"
 
using namespace std;
 
int main()
{   Worker *miniWorker = nullptr;
    miniWorker = new Worker();
 
    miniWorker->start();
 
    qDebug()<<"主线程ThreadID: "<<QThread::currentThreadId();
 
    miniWorker->printFunc();
    std::cout << "enter a num to end:";
    int a;
    while (cin >> a)
    {
        std::cout << a << "finish!" << std::endl;
        break;
    }
 
    return 0;
}

/*
主线程ThreadID:  0x7fb6e0f0d780
子线程成员函数ThreadID:  0x7fb6e0f0d780
子线程ThreadID:  0x7fb6e0f0c700

子线程ThreadID:  0x7f1dbba37700
主线程ThreadID:  0x7f1dbba38780
子线程成员函数ThreadID:  0x7f1dbba38780

主线程ThreadID:  0x7f4ecbc21780
子线程成员函数ThreadID:  0x7f4ecbc21780
子线程ThreadID:  0x7f4ecbc20700
*/
//#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "miniWork.h"
#include <QDebug>
#include <QThread>

int main(int argc, char* argv[]){
    QApplication a(argc, argv);
    miniWork worker;
    QThread thread;

    worker.moveToThread(&thread);
    QObject::connect(&thread, &QThread::started, &worker, &miniWork::doMiniWork);         //第一槽函数
    QObject::connect(&thread, &QThread::started, &worker, &miniWork::doMiniWork2);        //第二槽函数
    QObject::connect(&worker, &miniWork::testDoMiniWork3, &worker, &miniWork::doMiniWork3);
    thread.start();

    worker.printFunc();
    emit worker.testDoMiniWork3();
    /*std::cout << "enter a num to end:" << std::endl;
    int ain;
    while (std::cin >> ain)
    {
        std::cout << ain << "finish!" << std::endl;
        break;
    }*/
 
    return a.exec();
}
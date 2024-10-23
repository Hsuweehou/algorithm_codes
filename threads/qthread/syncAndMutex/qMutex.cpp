#include <QThread>
#include <QDebug>
#include <QMutex>
#include "shareValue.h"
 
// 定义一个线程类
class MyThread : public QThread{

/*
private:
    int sharedValue1 = 0;
*/
public:
    //int finalValue = 0;
    QMutex mutex11;

    /*
    MyThread(int sV){
        sharedValue1 = sV;
    }
    */

    void run() override {
        for(int i = 0; i < 5; i++) {
            //QMutexLocker locker(&mutex11); // 创建 QMutexLocker 对象并传递 QMutex 对象
            //原理与QMutex一致,可以自动释放锁资源，避免忘记解锁而导致的死锁情况
            //mutex11.lock(); // 加锁
            sharedValue11++; // 访问共享资源
            qDebug() << "Thread ID: " << QThread::currentThreadId() << " - Shared Value: " << sharedValue11;
            msleep(1000); // 线程休眠1秒
            //mutex11.unlock(); // 解锁
        }
    }

};
#include <QThread>
#include <QDebug> 
#include <QSemaphore>
 
QSemaphore semaphore11(2); // 定义能够同时访问资源的线程数量为2的信号量
 
class MyThreadSema : public QThread // 定义一个线程类
{
public:
    void run() override {
        if(semaphore11.tryAcquire()) { // 尝试获取信号量
            qDebug() << "Thread ID: " << QThread::currentThreadId() << " - Acquired Semaphore"; // 输出线程ID和已获取信号量消息
            sleep(2); // 线程休眠2秒
            qDebug() << "Thread ID: " << QThread::currentThreadId() << " - Releasing Semaphore"; // 输出线程ID和释放信号量消息
            semaphore11.release(); // 释放信号量
        } else {
            qDebug() << "Thread ID: " << QThread::currentThreadId() << " - Semaphore not acquired"; // 输出线程ID和未获取信号量消息
        }
    }
};

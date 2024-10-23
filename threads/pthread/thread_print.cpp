#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mymutex;
std::condition_variable condit_var;
 int flag = 0;

void printA(){
    std::unique_lock<std::mutex> lk(mymutex);
    int count = 0;
    while(count < 10){
        while (flag != 0)
        {
            condit_var.wait(lk);
        }
        std::cout << "thread 1: a" << std::endl;
        flag = 1;
        condit_var.notify_all();
        count++;
    }
    std::cout << "thread 1 finish " << std::endl;
}

void printB(){
    std::unique_lock<std::mutex> lk(mymutex);
    for(int i = 0;i < 10;i++){
        while(flag != 1)
        {
            condit_var.wait(lk);
        }
        std::cout << "thread 2: b" << std::endl;
        flag = 2;
        condit_var.notify_all();
    }
    std::cout << "thread 2 finish " << std::endl;
}

void printC(){
    std::unique_lock<std::mutex> lk(mymutex);
    for(int i = 0;i < 10;i++){
        while(flag != 2)
        {
            condit_var.wait(lk);
        }
        std::cout << "thread 3: c" << std::endl;
        flag = 0;
        condit_var.notify_all();
    }
    std::cout << "thread 3 finish " << std::endl;
} 

int main(){                                                         
    std::thread thr0(printA);
    std::thread thr1(printB);
    std::thread thr2(printC);
    thr0.join();
    thr1.join();
    thr2.join();
    std::cout << "main thread" << std::endl;
    std::cout << "enter a num to end:";
    int a;
    while (std::cin >> a)
    {
        std::cout << a << "finish!" << std::endl;
        break;
    }
    return 0;
 }
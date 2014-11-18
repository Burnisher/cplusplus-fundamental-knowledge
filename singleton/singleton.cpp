#include <iostream>
#include "MutexLock.h"
#include "Thread.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
using namespace std;

int64_t getUTime();

//DCLP（double-check-locking-pattern）
class Singleton
{
public:
    static Singleton *getInstance()
    {
        //采用double check模式，使得不必每次调用都需要加锁，提高了效率
        if(pInstance_ == NULL)
        {
            mutex_.lock();
            if(pInstance_ == NULL)
            {
                pInstance_ = new Singleton();
            }
            mutex_.unlock();
        }

        cout << "once" << endl;
        return pInstance_;
    }

    void print()
    {
        sleep(2);
        cout << ++count_ << endl;    
    }

private:
    Singleton() { }

    static Singleton *pInstance_;
    static MutexLock mutex_;
    static int count_;
};

Singleton *Singleton::pInstance_ = NULL;
MutexLock Singleton::mutex_;
int Singleton::count_ = 0;

class TestThread : public Thread
{
public:
    void run()
    {
        const int kCount = 2;
        for(int ix = 0; ix != kCount; ++ix)
        {
            Singleton * temp;
            temp = Singleton::getInstance();
            temp->print();
         
        }
    }

};

int main(int argc, const char *argv[])
{
    int64_t startTime = getUTime();

    const int KSize = 25;
    TestThread threads[KSize];
    for(int ix = 0; ix != KSize; ++ix)
    {
        threads[ix].start();
    }

    for(int ix = 0; ix != KSize; ++ix)
    {
        threads[ix].join();
    }

    int64_t endTime = getUTime();

    int64_t diffTime = endTime - startTime;

    cout << "cost : " << diffTime / 1000 << " ms" << endl;

    return 0;

}

int64_t getUTime()
{
    struct timeval tv;
    ::memset(&tv, 0, sizeof tv);
    if(gettimeofday(&tv, NULL) == -1)
    {
        perror("gettimeofday");
        exit(EXIT_FAILURE);
    }

    int64_t current = tv.tv_usec;
    current += tv.tv_sec * 1000 * 1000;
    return current;
}

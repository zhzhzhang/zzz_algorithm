#ifndef _THREAD_H
#define _THREAD_H

#include<deque>
#include<string>
#include<iostream>

using namespace std;

//任务基类
class Task {
protected:
    string taskname;
    int connfd;
public:
    Task() = default;
    Task(string& name) : taskname(name), connfd(NULL) {}
    virtual int Run() = 0;
    void SetConnFd(int data);
    int GetConnFd();
    virtual ~Task() {}
};

//线程池类

class ThreadPool
{
private:
    static deque<Task* > TaskList;
    static bool shutdown;
    int ThreadNum;
    pthread_t *pthread_id;
    static pthread_mutex_t m_pthreadMutex;
    static pthread_cond_t m_pthreadCond;
protected:
    static void* ThreadFunc(void* threadDate);
    static int MoveToFree(pthread_t tid);
    static int MoveToBusy(pthread_t tid);
    int Create();
public:
    ThreadPool(int threadNum = 10);
    int AddTask(Task* task);
    int StopAll();
    int getTaskSize();
};

#endif
#include "Thread.h"
#include <iostream>
#include <stdio.h>

void Task::SetConnFd(int data){
    connfd = data;
}

int Task::GetConnFd(){return connfd;}

deque<Task*> ThreadPool::TaskList;
bool ThreadPool::shutdown = false;

pthread_mutex_t ThreadPool::m_pthreadMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t ThreadPool::m_pthreadCond = PTHREAD_COND_INITIALIZER;

ThreadPool::ThreadPool(int theadNum){
    this->ThreadNum = ThreadNum;
    cout << "l will create" << ThreadNum << " threads" << endl;
    Create();
}

//线程回调函数
void* ThreadPool::ThreadFunc(void* thread_data){
    pthread_t tid = pthread_self();
    while(1){

         pthread_mutex_lock(&m_pthreadMutex);
         while(TaskList.size() == 0 && !shutdown){
             pthread_cond_wait(&m_pthreadCond, &m_pthreadMutex);
         }
         if(shutdown){
             pthread_mutex_unlock(&m_pthreadMutex);
             printf("thread %lu will exit\n", pthread_self());
             pthread_exit(NULL);
         }

         printf("tid %lu run\n", tid);

         Task* task = TaskList.front();
         TaskList.pop_front();
         pthread_mutex_unlock(&m_pthreadMutex);
         task->Run();
    }
    return (void*) 0;
}

int ThreadPool::AddTask(Task *task)
{
    pthread_mutex_lock(&m_pthreadMutex);
    this->TaskList.push_back(task);
    pthread_mutex_unlock(&m_pthreadMutex);
    pthread_cond_signal(&m_pthreadCond);
    return 0;
}

int ThreadPool::Create(){
    pthread_id = 
}
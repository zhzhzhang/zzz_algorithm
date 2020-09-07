#include <thread>
#include <iostream>
#include <chrono>
#include <string>
#include <mutex>
#include <deque>
#include <condition_variable>
using namespace std;

/**
 * 
 * 简单的生产者与消费者问题，使用mutex互斥量加锁
 * 和condition_variable条件变量控制任务队列的访问。
 * 目前只有一个生产者和消费者，可以循环创建多个生产者消费者。
 * 下面会将生产者消费者封装成类实现。
 */

void eattask(deque<string>* task, mutex* m_mutex, condition_variable* m_cond) {
    using namespace std::chrono;
    while(1){
        std::unique_lock<std::mutex> locker(*m_mutex); //将互斥量封装为锁对象，用来做cond参数，否则直接mutex->lock就行了。
        while(task->size() == 0)
            m_cond->wait(locker);//此处使用while而不是if是为了防止虚假唤醒
            //m_cond.wait(locker, [](){ return !q.empty();} ); lambda表达式同样可以。
        this_thread::sleep_for(chrono::milliseconds(500));
        std::cout << "eat task:" << task->front() << std::endl;
        task->pop_front();
        m_mutex->unlock();
        locker.unlock();
    } 
}

void maketask(deque<string>* task, mutex* m_mutex, condition_variable* m_cond) {
    using namespace std::chrono;
    string s = "a";
    int i = 10;
    while(i--){
        s+="3";
        this_thread::sleep_for(chrono::milliseconds(1000));
        m_mutex->lock();
        task->push_back(s);
        m_mutex->unlock();
        m_cond->notify_one();
        std::cout << "add task:" << s << std::endl;
    } 
}


int main() {
    deque<string> task;
    mutex m_mutex;
    condition_variable m_cond;
    std::thread make(maketask,&task,&m_mutex,&m_cond);
    std::thread eat(eattask, &task, &m_mutex,&m_cond);
    make.join();
    eat.join();
    return 0;
}
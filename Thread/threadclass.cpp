#include <thread>
#include <iostream>
#include <chrono>
#include <string>
#include <mutex>
#include <deque>
#include <condition_variable>
#include <vector>
using namespace std;

int remain = 5; //控制5个生产者是否结束，当为0时，消费者退出等待。

/**
 * 生产者类
 * 
 * */
class producer{
    string name;
public:
    thread* prothread;
    producer(const string& Name ) : name(Name), prothread(nullptr){};
    ~producer(){ delete prothread; cout<< name << "销毁" << endl; }
    string getName(){ return name; }
    void produce(deque<string>* task, mutex* m_mutex, condition_variable* m_cond);
    void run(deque<string>* task, mutex* m_mutex, condition_variable* m_cond);
};

void producer::produce(deque<string>* task, mutex* m_mutex, condition_variable* m_cond){
    using namespace std::chrono;
    string s;
    int i = 20;
    while(i--){
        s+="0";
        this_thread::sleep_for(chrono::milliseconds(10));
        m_mutex->lock();
        task->push_back(s);
        std::cout << name << " : " << s << std::endl;
        m_mutex->unlock();
        m_cond->notify_one();
    } 
    m_mutex->lock();
    remain--;
    if(remain == 0) m_cond->notify_all();
    m_mutex->unlock();
}

void producer::run(deque<string>* task, mutex* m_mutex, condition_variable* m_cond){
    prothread = new thread(produce, this, task, m_mutex, m_cond);
}

/**
 * 消费者类
 * 
 * */
class consumer{
    string name;
public:
    thread*  conthread;
    consumer(const string& Name ) : name(Name), conthread(nullptr){};
    ~consumer(){ delete conthread; cout<< name << "销毁" << endl; }
    string getName(){ return name; }
    void consume(deque<string>* task, mutex* m_mutex, condition_variable* m_cond);
    void run(deque<string>* task, mutex* m_mutex, condition_variable* m_cond);
};

void consumer::consume(deque<string>* task, mutex* m_mutex, condition_variable* m_cond){
    using namespace std::chrono;
    while(1){
        std::unique_lock<std::mutex> locker(*m_mutex); 
        while(task->size() == 0 && remain)
            m_cond->wait(locker);
        if(task->size() == 0) break;
        this_thread::sleep_for(chrono::milliseconds(50));
        std::cout << name << " : " << task->front() << std::endl;
        task->pop_front();
        locker.unlock();
    } 
}

void consumer::run(deque<string>* task, mutex* m_mutex, condition_variable* m_cond){
    conthread = new thread(consume, this, task, m_mutex, m_cond);
}


int main() {
    deque<string> task;   //任务队列
    mutex m_mutex;    //互斥量
    condition_variable m_cond;  //条件变量
    vector<producer*> producers;
    vector<consumer*> consumers;
    for(int i = 0; i < 5; i++)   
    {
        string name = "生产者";
        name += '0' + i;
        producers.push_back(new producer(name));
        producers[i]->run(&task, &m_mutex, &m_cond);
    }
    for(int i = 0; i < 10; i++){
        string name = "消费者";
        name += '0' + i;
        consumers.push_back(new consumer(name));
        consumers[i]->run(&task, &m_mutex, &m_cond);
    }
    for(int i = 0; i < 5; i++){
        producers[i]->prothread->join();
    }
    for(int i = 0; i < 10; i++){
        consumers[i]->conthread->join();
    }
    for(int i = 0; i < 5; i++){
        delete producers[i];
    }
    for(int i = 0; i < 10; i++){
        delete consumers[i];
    }
    getchar();
    return 0;
}
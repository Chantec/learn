//
// Created by root on 25-1-8.
//

#pragma once

#include <condition_variable>
#include <queue>
#include <mutex>

template<class T>
class BlockQueue
{
public:
    BlockQueue(int max_capacity=1000);
    ~BlockQueue();
    void clear();

    bool empty();

    bool full();

    void Close();

    size_t size();

    size_t capacity();

    T front();

    T back();

    void push_back(const T &item);

    void push_front(const T &item);

    bool pop(T &item);

    bool pop(T &item, int timeout);

    void flush();

private:
    std::deque<T> queue_;
    size_t capacity_;
    std::mutex mutex_;
    bool is_closed_;
    std::condition_variable condConsumer_;
    std::condition_variable condProducer_;


};

template <class T>
BlockQueue<T>::BlockQueue(int max_capacity):capacity_(max_capacity)
{
    is_closed_ = false;
}

template <class T>
BlockQueue<T>::~BlockQueue()
{
    is_closed_ = true;
}

template <class T>
void BlockQueue<T>::push_back(const T& item)
{
    std::unique_lock<std::mutex> lock(mutex_);
    while (queue_.size() >= capacity_)
    {
        condProducer_.wait(lock);
    }
    queue_.push_back(item);
    condConsumer_.notify_one();
}
template <class T>
void ::BlockQueue<T>::push_front(const T& item)
{
    std::unique_lock<std::mutex> lock(mutex_);
    while (queue_.size() >= capacity_)
    {
        condProducer_.wait(lock);
    }
    queue_.push_front(item);
    condConsumer_.notify_one();
}






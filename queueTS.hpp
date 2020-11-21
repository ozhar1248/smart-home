#ifndef _QUEUETS_
#define _QUEUETS_

#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

namespace ds
{

    template <typename T>
    class QueueTS
    {
    public:
        QueueTS();
        ~QueueTS() = default;
        int enqueue(const shared_ptr<const T>& _ptrT);
        int dequeue(shared_ptr<const T>& _ptrT);
        void stop();
        int size();
    private:
        QueueTS(const QueueTS& _queue);
        QueueTS& operator=(const QueueTS& _queue) {};

        queue<shared_ptr<const T>> m_mainQueue;
        mutex m_mutex;
        condition_variable m_cv;
        bool m_power;
    }; //QueueTS

    /************************************************************************/

    template <typename T>
    QueueTS<T>::QueueTS() :m_power(true)
    {

    }

    template <typename T>
    int QueueTS<T>::enqueue(const shared_ptr<const T>& _ptrT)
    {
        m_mutex.lock();

        if (!m_power)
        {
            return 1;
        }
        m_mainQueue.push(_ptrT);
        m_cv.notify_one();

        m_mutex.unlock();
        return 0;
    }

    template <typename T>
    int QueueTS<T>::dequeue(shared_ptr<const T>& _ptrT)
    {
        unique_lock<mutex> locker(m_mutex);
        while (m_mainQueue.empty())
        {
            m_cv.wait(locker);
            if (!m_power)
            {
                locker.unlock();
                return 1;
            }
        }
        _ptrT = m_mainQueue.front();
        m_mainQueue.pop();
        locker.unlock();
        return 0;
    }

    template <typename T>
    void QueueTS<T>::stop()
    {
        m_mutex.lock();
        m_power = false;
        m_cv.notify_all();
        m_mutex.unlock();
    }

    template <typename T>
    int QueueTS<T>::size()
    {
        m_mutex.lock();
        int size = m_mainQueue.size();
        m_mutex.unlock();
        return size;
    }

} //ds
#endif //_QUEUETS_

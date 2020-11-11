#include "queueTS.hpp"
#include <thread>
#include <memory>
#include <iostream>
#include <Windows.h>
#include <mutex>
#include <vector>

using namespace ds;

struct Int
{
	int n;
	Int(int _n) : n(_n) {};
};

struct AtomicInt
{
	std::mutex mu;
	int n;
	AtomicInt(int _n) : n(_n) {};
	void Increase(QueueTS<Int>& qu)
	{
		mu.lock();
		qu.enqueue(std::shared_ptr<Int>(new Int(n)));
		++n;
		mu.unlock();
	}
};

void enqueue(QueueTS<Int>& qu, AtomicInt& atom)
{
	for (int i = 0; i < 100; ++i)
	{

		atom.Increase(qu);
	}
}

void dequeue(QueueTS<Int>& qu)
{
	std::shared_ptr<const Int> ptrN;
	int curr, prev;
	prev = -1;

	while (true)
	{
		if (qu.dequeue(ptrN) == 1)
		{
			break;
		}
		curr = ptrN->n;
		if (curr <= prev )
		{
			std::cout << "fail" << std::endl;
			return;
		}
		prev = curr;
	}
	std::cout << "pass" << std::endl;
}

int main()
{
	QueueTS<Int> testQueue;
	AtomicInt atom(0);
	std::vector<std::thread> vec;

	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(std::thread(enqueue, std::ref(testQueue), std::ref(atom)));
	}
	std::thread deqThread(dequeue, std::ref(testQueue));

	Sleep(200);

	testQueue.stop();
	for (int i = 0; i < 20; ++i)
	{
		vec[i].join();
	}
	deqThread.join();

	return 0;
}
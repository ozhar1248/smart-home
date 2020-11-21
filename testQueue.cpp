#include "queueTS.hpp"
#include <thread>
#include <memory>
#include <iostream>
#include <Windows.h>
#include <mutex>
#include <vector>

using namespace ds;
using namespace std;

struct Int
{
	int n;
	Int(int _n) : n(_n) {};
};

struct AtomicInt
{
	mutex mu;
	int n;
	AtomicInt(int _n) : n(_n) {};
	void Increase(QueueTS<Int>& qu)
	{
		mu.lock();
		qu.enqueue(shared_ptr<Int>(new Int(n)));
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
	shared_ptr<const Int> ptrN;
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
			cout << "fail" << endl;
			return;
		}
		prev = curr;
	}
	cout << "pass" << endl;
}

int main()
{
	QueueTS<Int> testQueue;
	AtomicInt atom(0);
	vector<thread> vec;

	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(thread(enqueue, ref(testQueue), ref(atom)));
	}
	thread deqThread(dequeue, ref(testQueue));

	Sleep(200);

	testQueue.stop();
	for (int i = 0; i < 20; ++i)
	{
		vec[i].join();
	}
	deqThread.join();

	return 0;
}
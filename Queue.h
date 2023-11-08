#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Queue
{
public:
	T* end;
	T* begin;
	T* arr;
	int size;
public:

	Queue(int n = 2) : size(n)
	{
		arr = new T[size];
		begin = end = arr;
	}
	~Queue()
	{
		delete[] arr;
	}
	int Size()
	{
		return end - begin;
	}
	bool isEmpty()
	{
		return end == begin;
	}
	void Push(T elem)
	{
		const int total = end - begin;
		if (total == size)
		{
			size *= 2;
			T* tmp = new T[size];
			std::copy(begin, end, tmp);
			begin = tmp;
			end = tmp + total;
			delete[] arr;
			arr = tmp;
		}
		*(end++) = elem;
	}
	T Pop()
	{
		size--;
		return *(begin++);
	}
	friend ostream& operator<<(ostream& out, const Queue& q)
	{
		for (auto i = (q.end - q.Size); i < q.end; i++)
			out << *i << " ";
		return out;
	}
};
#include "Queue.h"

int main()
{
	Queue<int> q(10);
	for (int i = 0; i < 10; i++)
	{
		q.Push(i);
	}
	cout << q << endl;
	cout << q.Pop() << endl;
	cout << q;
	return 0;
}
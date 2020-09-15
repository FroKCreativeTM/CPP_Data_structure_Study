#include <iostream>
#include <exception>

#include "ArrayQueue.h"
#include "ListQueue.h"

int main()
{
	ListQueue<int> listQueue;
	listQueue.Enqueue(10);
	listQueue.Enqueue(20);
	listQueue.Enqueue(30);
	listQueue.Enqueue(40);
	listQueue.Enqueue(50);
	listQueue.Enqueue(60);
	listQueue.Enqueue(70);

	try
	{
		while (!listQueue.IsEmpty())
		{
			std::cout << listQueue.Front() << std::endl;
			listQueue.Dequeue();
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
#include <iostream>
#include <queue>

int main()
{
	std::queue<int> stlqueue;
	stlqueue.push(10);
	stlqueue.push(20);
	stlqueue.push(30);
	stlqueue.push(40);
	stlqueue.push(50);

	while (!stlqueue.empty())
	{
		std::cout << stlqueue.front() << std::endl;
		stlqueue.pop();
	}

	return 0;
}
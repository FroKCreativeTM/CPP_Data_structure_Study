#pragma once
#include <iostream>
class printStack
{
public:
	void print_stack(int s[],int N)
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << s[i] << " ";
			if (s[i + 1] == NULL)
			{
				break;
			}
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
};


#include <iostream>
#include <stack>
#include "Stack.h"
#include "printStack.h"
#define N 100	// ������ �ִ� ũ��


int main()
{
	Stack Stack;
	printStack sp;	//C ��Ÿ���� ���� ���
	
	// ������ ������ ���� ���� ����
	int s1[N] = { 10, 20, 30, 40, 50,};
	int top;
	int* p = &top;
	top = 4;

	std::cout << "���� ����" << std::endl;
	std::cout << "top : " << top << std::endl;
	sp.print_stack(s1, N);

	// ���ÿ� 60�� �߰�
	Stack.insertStack(s1, N, p, 60);
	std::cout << "60 �߰� ����" << std::endl;
	std::cout << "top : " << top << std::endl;
	sp.print_stack(s1, N);

	// ���ÿ� 60�� ����
	Stack.deleteStack(s1, N, p);
	std::cout << "60 ���� ����" << std::endl;
	std::cout << "top : " << top << std::endl;
	sp.print_stack(s1, N);


	// ���ÿ� 50�� ����
	Stack.deleteStack(s1, N, p);
	std::cout << "50 ���� ����" << std::endl;
	std::cout << "top : " << top << std::endl;
	sp.print_stack(s1, N);

	//C++ �� <stack> ���
	std::stack<int> s2;
	std::cout << "C++ �� stack�� �̿��� ���ñ���" << std::endl;
	s2.push(11);
	std::cout << s2.top() << " ";
	s2.push(21);
	std::cout << s2.top() << " ";
	s2.push(31);
	std::cout << s2.top() << " ";
	s2.push(41);
	std::cout << s2.top() << " ";
	s2.push(51);
	std::cout << s2.top() << " ";
	std::cout << std::endl;
	std::cout << "top element : " << s2.top() << std::endl;

	std::cout << std::endl;
	std::cout << "push�� �̿��� �߰�" << std::endl;
	s2.push(61);
	std::cout << "top element : " << s2.top() << std::endl;

	std::cout << std::endl;
	std::cout << "pop�� �̿��� ����" << std::endl;
	s2.pop();
	std::cout << "top element : " << s2.top() << std::endl;

	
	return 0;
}
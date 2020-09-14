#include <iostream>
#include <stack>
#include "Stack.h"
#include "printStack.h"
#define N 100	// 스택의 최대 크기


int main()
{
	Stack Stack;
	printStack sp;	//C 스타일의 스택 출력
	
	// 정수형 스택을 위한 변수 정의
	int s1[N] = { 10, 20, 30, 40, 50,};
	int top;
	int* p = &top;
	top = 4;

	std::cout << "현재 스택" << std::endl;
	std::cout << "top : " << top << std::endl;
	sp.print_stack(s1, N);

	// 스택에 60을 추가
	Stack.insertStack(s1, N, p, 60);
	std::cout << "60 추가 스택" << std::endl;
	std::cout << "top : " << top << std::endl;
	sp.print_stack(s1, N);

	// 스택에 60을 제거
	Stack.deleteStack(s1, N, p);
	std::cout << "60 제거 스택" << std::endl;
	std::cout << "top : " << top << std::endl;
	sp.print_stack(s1, N);


	// 스택에 50을 제거
	Stack.deleteStack(s1, N, p);
	std::cout << "50 제거 스택" << std::endl;
	std::cout << "top : " << top << std::endl;
	sp.print_stack(s1, N);

	//C++ 내 <stack> 사용
	std::stack<int> s2;
	std::cout << "C++ 내 stack을 이용한 스택구현" << std::endl;
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
	std::cout << "push를 이용한 추가" << std::endl;
	s2.push(61);
	std::cout << "top element : " << s2.top() << std::endl;

	std::cout << std::endl;
	std::cout << "pop을 이용한 제거" << std::endl;
	s2.pop();
	std::cout << "top element : " << s2.top() << std::endl;

	
	return 0;
}
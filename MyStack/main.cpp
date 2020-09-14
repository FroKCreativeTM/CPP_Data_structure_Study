#include "MyStack.h"

int main()
{
	MyStack<int, 10> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	st.push(70);
	st.push(80);
	st.push(90);
	st.push(100);

	std::cout << st.top() << std::endl;
	st.push(100);

	return 0;
}
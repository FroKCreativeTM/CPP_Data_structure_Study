#include "Stack.h"
#include <iostream>

int Stack::insertStack(int s[], int n, int* top, int x)
{
	if (*top < n - 1)
	{
		*top = *top + 1;
		s[*top] = x;
		return(1);	//추가 성공
	}
	return 0;	//추가 실패
}

int Stack::deleteStack(int s[], int n, int* top)
{
	int temp;
	if (*top != -1)
	{
		temp = s[*top];
		s[*top] = NULL;
		*top = *top - 1;
		return(temp);	//삭제원소 반환
	}
	return 0;	//삭제실패
}

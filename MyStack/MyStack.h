#pragma once

#include <iostream>
#include <exception>

template <typename T, int MAX_SIZE = 100>
class MyStack
{
private : 
	T*		m_Stack;
	int		m_Top;
	int		m_MAX_SIZE;

private : 
	// ������� �͵�
	MyStack(const MyStack& ref) = delete;		// ��������ڸ� ���´�.
	MyStack& operator=(const MyStack& ref) = delete;

public : 
	MyStack() :
		m_Top(-1), m_MAX_SIZE(MAX_SIZE), m_Stack(nullptr) 
	{
		m_Stack = new T[m_MAX_SIZE];
	}

	~MyStack()
	{
		if (m_Stack != nullptr)
		{
			delete[] m_Stack;
		}
		m_Stack = nullptr;
	}

public : 
	void push(const T& _data)
	{
		if ((m_Top + 1) == m_MAX_SIZE)
		{
			std::cout << "Max Stack" << std::endl;
			return;
		}

		m_Stack[++m_Top] = _data;
	}

	void pop()
	{
		// ��������� �ٷ� ������.
		if (isEmpty())
		{
			std::cout << "Stack is empty" << std::endl;
			return;
		}
			

		--m_Top;
	}

	T top() const
	{
		if (isEmpty())
			throw "Empty Stack";

		return m_Stack[m_Top];
	}

	bool isEmpty() const
	{
		return m_Top == -1;
	}

	int GetTopIdx() const { return m_Top; }
	int GetMaxSize() const { return m_MAX_SIZE; }
};


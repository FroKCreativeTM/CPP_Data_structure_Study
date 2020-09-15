#pragma once

#include <iostream>
#include <exception>

template <typename T, int MAX_SIZE = 100>
class ArrayQueue
{
private : 
	T*		m_queueArr;		// ť�� ���Ұ� ����� �迭
	int		m_size;			// ť�� ����� ������ ����
	int		m_maxsize;
	int		m_front;		// �� �տ� �ִ� �ε���
	int		m_rear;			// �� �ڿ� �ִ� �ε���

public :
	ArrayQueue() :
		m_maxsize(MAX_SIZE),
		m_size(0),
		m_front(0),
		m_rear(0)
	{
		m_queueArr = new T[m_maxsize];
	}

	~ArrayQueue()
	{
		if (m_queueArr != nullptr)
		{
			delete[] m_queueArr;
		}
		m_queueArr = nullptr;
	}

public : 
	void enqueue(T _data)
	{
		if (isfull())
		{
			std::cout << "Queue is full" << std::endl;
			return;
		}

		m_queueArr[m_rear] = _data;	// �ϴ� �ڿ� �ִ´�.
		m_rear = (m_rear + 1) % m_maxsize;
		m_size++;
	}

	void dequeue()
	{
		if (isempty())
		{
			std::cout << "Queue is full" << std::endl;
			return;
		}
		m_front = (m_front + 1) % m_maxsize;
		m_size--;
	}


	T front() const 
	{
		if (isempty())
			throw "Queue is empty!";

		return m_queueArr[m_front];
	}

	int size() const
	{
		return m_size;
	}

	bool isempty() const
	{
		return m_size == 0;
	}

	bool isfull() const
	{
		return m_size == m_maxsize;
	}
};



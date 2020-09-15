#pragma once

#include <cassert>

template <typename T>
class QueueNode
{
private : 
	T			m_data;
	QueueNode*	m_pNext;

public : 
	QueueNode() : 
		m_pNext(nullptr)
	{
	}

	~QueueNode() {}

private :
	template <typename T>
	friend class ListQueue;
};

template <typename T>
class ListQueue
{
private : 
	typedef QueueNode<T> NODE;
	typedef QueueNode<T>* PNODE;

private : 
	PNODE m_pHead, m_pTail;
	int m_Size;

public : 
	ListQueue() :
		m_pHead(nullptr), m_pTail(nullptr), m_Size(0)
	{
		m_pHead = new NODE;
		m_pTail = new NODE;

		m_pHead->m_pNext = m_pTail;	// ���� ��������� ��� ��� ������ �ٷ� ���� ����̴�.
		m_pTail->m_pNext = nullptr;	// ���� ��� ������ ����, ����� ť�̴�.
	}

	~ListQueue()
	{
		clear();
	}

private : 
	// �ٸ� public �޼ҵ���� ���� �޼ҵ尡 ���� ���ǵȴ�.
	void clear()
	{
		// assert(!IsEmpty());		// ���� assert ��ũ�� �ȿ� �ִ� ������ ���̸� pass, �����̸� ���α׷� ����!

		if (IsEmpty())
			return;
		
		// �������� ����.
		while (!IsEmpty())
		{
			Dequeue();
		}
	}

public : 
	void Enqueue(T _data)
	{
		PNODE newNode = new NODE;
		newNode->m_data = _data;

		if (IsEmpty())
		{
			newNode->m_pNext = m_pHead->m_pNext;
			m_pHead->m_pNext = newNode;
		}
		else
		{
			// Ŀ�� ���
			PNODE pCurNode = m_pHead->m_pNext;

			// ���� ������ ����.
			while (pCurNode->m_pNext != m_pTail)
			{
				PNODE pNextNode = pCurNode->m_pNext;
				pCurNode = pNextNode;
			}
			// �� �ڿ� �־��ش�.
			newNode->m_pNext = pCurNode->m_pNext;
			pCurNode->m_pNext = newNode;
		}
		m_Size++;
	}

	void Dequeue()
	{
		assert(!IsEmpty());		// ���� assert ��ũ�� �ȿ� �ִ� ������ ���̸� pass, �����̸� ���α׷� ����!

		PNODE delNode = m_pHead->m_pNext;
		m_pHead->m_pNext = delNode->m_pNext;	

		delete delNode;
		m_Size--;
	}

	T Front() const
	{
		assert(!IsEmpty());		// ���� assert ��ũ�� �ȿ� �ִ� ������ ���̸� pass, �����̸� ���α׷� ����!

		return m_pHead->m_pNext->m_data;
	}

	bool IsEmpty() const
	{
		return m_Size == 0;
	}

	int Size() const
	{
		return m_Size;
	}
};
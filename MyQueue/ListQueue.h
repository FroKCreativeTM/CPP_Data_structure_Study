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

		m_pHead->m_pNext = m_pTail;	// 아직 비어있으니 헤드 노드 다음은 바로 꼬리 노드이다.
		m_pTail->m_pNext = nullptr;	// 꼬리 노드 다음은 없는, 비원형 큐이다.
	}

	~ListQueue()
	{
		clear();
	}

private : 
	// 다른 public 메소드들의 헬퍼 메소드가 여기 정의된다.
	void clear()
	{
		// assert(!IsEmpty());		// 만약 assert 매크로 안에 있는 내용이 참이면 pass, 거짓이면 프로그램 종료!

		if (IsEmpty())
			return;
		
		// 빌때까지 뺀다.
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
			// 커서 노드
			PNODE pCurNode = m_pHead->m_pNext;

			// 꼬리 노드까지 가자.
			while (pCurNode->m_pNext != m_pTail)
			{
				PNODE pNextNode = pCurNode->m_pNext;
				pCurNode = pNextNode;
			}
			// 맨 뒤에 넣어준다.
			newNode->m_pNext = pCurNode->m_pNext;
			pCurNode->m_pNext = newNode;
		}
		m_Size++;
	}

	void Dequeue()
	{
		assert(!IsEmpty());		// 만약 assert 매크로 안에 있는 내용이 참이면 pass, 거짓이면 프로그램 종료!

		PNODE delNode = m_pHead->m_pNext;
		m_pHead->m_pNext = delNode->m_pNext;	

		delete delNode;
		m_Size--;
	}

	T Front() const
	{
		assert(!IsEmpty());		// 만약 assert 매크로 안에 있는 내용이 참이면 pass, 거짓이면 프로그램 종료!

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
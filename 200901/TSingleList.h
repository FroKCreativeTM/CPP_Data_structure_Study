#pragma once

#include <cassert>		// ������ ���

template <typename T>
class TSingleListNode
{
private : 
	T m_Data;						// ������
	TSingleListNode* m_pNextNode;	// ���� ����� �ּҰ�

private :
	template <typename T>
	friend class TSingleList;		// friend�� ���ؼ� TSingleList�� TSingleListNode�� private �����ͱ��� ������ ����������.

public : 
	TSingleListNode() :
		m_pNextNode(nullptr) {}
	~TSingleListNode() 
	{
		if (m_pNextNode)
		{
			delete m_pNextNode;
		}
		m_pNextNode = nullptr;
	}
};

template <typename T>
class TSingleList
{
private : 
	typedef TSingleListNode<T> NODE;
	typedef TSingleListNode<T>* PNODE;

private : 
	PNODE m_pHead;				// ���� �տ� �ִ� �Ӹ� ���
	int m_nCurCount;			// ���� �� ���� �����Ͱ� ����Ʈ�� �����ϴ°�

public : 
	// Create
	TSingleList() : 
		m_pHead(nullptr), m_nCurCount(0)
	{
		m_pHead = new NODE;
		m_pHead->m_pNextNode = nullptr;
	}

	// Destroy
	~TSingleList()
	{


		m_nCurCount = 0;
	}

public : 
	// Insert
	void Insert(const T& _data)
	{
		PNODE newNode = new NODE;
		newNode->m_Data = _data;

		// ���� ��� �ִٸ�
		if (m_pHead->m_pNextNode == nullptr)
		{
			m_pHead->m_pNextNode = newNode;
		}
		// ���� �����Ͱ� �ִٸ�
		else
		{
			// ������ ��带 ã�� ��带 ���Ѵ�.
			PNODE lastNode = m_pHead->m_pNextNode;

			// ������ ��带 ã�� ������ 
			while (lastNode->m_pNextNode != nullptr)
			{
				PNODE nextNode = lastNode->m_pNextNode;
				lastNode = nextNode;
			}

			lastNode->m_pNextNode = newNode;
		}
		m_nCurCount++;		// ��尪�� �߰��ȴ�.
	}

	void Delete(int _position)
	{
		// ���� �� ������ Ʋ���ٸ� �ٷ� ���� ó���� �Ѵ�.
		assert(_position <= m_nCurCount);

		PNODE delNode = m_pHead;

		while (_position != 0)
		{
			PNODE delNextNode = delNode->m_pNextNode;
			delNode = delNextNode;
			--_position;
		}

		delete delNode;
	}

	T Retrieve(int _position)
	{
		// ���� �� ������ Ʋ���ٸ� �ٷ� ���� ó���� �Ѵ�.
		assert(_position <= m_nCurCount);

		PNODE findNode = m_pHead;

		while (_position != 0)
		{
			PNODE findNextNode = findNode->m_pNextNode;
			findNode = findNextNode;
			--_position;
		}

		T returnData = findNode->m_Data;
		return returnData;
	}

	bool IsEmpry() const
	{
		return m_nCurCount == 0;
	}

	int GetLength() const
	{
		return m_nCurCount;
	}
};

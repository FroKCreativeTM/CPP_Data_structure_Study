#include <iostream>

// ���ø�ȭ
// �پ��� �ڷ������� ������ �� �ִ� Ŭ���� �� �Լ��� �����ϴ� ������ 
// �̷��� �ڷ������� �������� �� �����ȴ�. (�� ���� �˻縦 �ϸ鼭 �� �ð����� �� ��Ī�� �Ǵ� ����� ���α׷���)
template <typename T>
class CArray
{
private : 
	T* m_Arr;			// TŸ���� �迭(�� ������ �����)
	int m_Count;		// �����Ͱ� �� �� ���Գ�
	int m_MaxCount;		// �����Ͱ� �� ����� ���� �� �ֳ�!

public : 
	void Add(T _elem)
	{

	}

	T Delete()
	{

	}

	int GetCount() const
	{
		return m_Count;
	}

	int GetMaxCount() const
	{
		return m_MaxCount;
	}
};

int main()
{

	return 0;
}
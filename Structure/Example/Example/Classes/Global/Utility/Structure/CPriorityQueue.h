#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"

//! �켱 ���� ť
template <typename T>
class CPriorityQueue {
public:			// public �Լ�

	//! ������ ��ȯ�Ѵ�
	int getCount(void) const;

	//! ���� �߰��Ѵ�
	void enqueueValue(T a_tValue);

	//! ���� �����Ѵ�
	T dequeueValue(void);

public:			// ������

	//! ������
	CPriorityQueue(const int a_nSize = CArrayList<T>::DEF_SIZE);

private:			// private �Լ�

	//! ���� �������Ѵ�
	void reheapUp(int a_nIndex);

	//! ���� �������Ѵ�
	void reheapDown(int a_nIndex);

private:			// private ����

	CArrayList<T> m_oValueList;
};

#include "CPriorityQueue.inl"

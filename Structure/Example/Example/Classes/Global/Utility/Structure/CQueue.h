#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"

//! ť
template <typename T>
class CQueue {
public:			// public �Լ�

	//! ������ ��ȯ�Ѵ�
	int getCount(void) const;

	//! ���� �߰��Ѵ�
	void enqueueValue(T a_tValue);

	//! ���� �����Ѵ�
	T dequeueValue(void);

public:			// ������

	//! ������
	CQueue(const int a_nSize = CArrayList<T>::DEF_SIZE);

private:			// private ����

	CArrayList<T> m_oValueList;
};

#include "CQueue.inl"

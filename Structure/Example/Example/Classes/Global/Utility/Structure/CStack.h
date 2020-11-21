#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"

//! ����
template <typename T>
class CStack {
public:			// public �Լ�

	//! ������ ��ȯ�Ѵ�
	int getCount(void) const;

	//! ���� �߰��Ѵ�
	void pushValue(T a_tValue);

	//! ���� �����Ѵ�
	T popValue(void);

public:			// ������

	//! ������
	CStack(const int a_nSize = CArrayList<T>::DEF_SIZE);

private:			// private ����

	CArrayList<T> m_oValueList;
};

#include "CStack.inl"

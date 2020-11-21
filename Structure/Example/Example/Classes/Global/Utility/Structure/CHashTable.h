#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"
#include "CLinkedList.h"

//! �ؽ� ���̺�
template <typename T>
class CHashTable {
public:

	enum {
		DEF_SIZE = 5
	};

public:			// public �Լ�

	//! ���� ���θ� �˻��Ѵ�
	bool isContains(T a_tValue) const;

	//! ���� �߰��Ѵ�
	void addValue(T a_tValue);

	//! ���� �����Ѵ�
	void removeValue(T a_tValue);

	//! ���̺��� ��ȸ�Ѵ�
	void enumerate(const std::function<void (const CLinkedList<T> &, int)> &a_rCallback) const;

public:			// ������

	//! ������
	CHashTable(const int a_nSize = DEF_SIZE);

private:			// private �Լ�

	//! �ؽ� ���� �����Ѵ�
	int makeHashValue(T a_tValue) const;

private:			// private ����

	CArrayList<CLinkedList<T>> m_oValueList;
};

#include "CHashTable.inl"

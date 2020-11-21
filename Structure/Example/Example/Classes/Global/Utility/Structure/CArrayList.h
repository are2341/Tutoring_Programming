#pragma once

#include "../../Define/KGDefine.h"

//! �迭 ����Ʈ
template <typename T>
class CArrayList {
public:

	enum {
		DEF_SIZE = 5
	};

public:			// operator

	//! operator=
	CArrayList<T> & operator=(const CArrayList<T> &a_rOther);

	//! operator[]
	T & operator[](const int a_nIndex);

	//! operator[]
	T operator[](const int a_nIndex) const;

public:			// public �Լ�

	//! ������ ��ȯ�Ѵ�
	int getCount(void) const;

	//! ���� �߰��Ѵ�
	void addValue(T a_tValue);

	//! ���� �����Ѵ�
	void insertValue(const int a_nIndex, T a_tValue);

	//! ���� �����Ѵ�
	void removeValue(const int a_nIndex);

public:			// ������, �Ҹ���

	//! ������
	CArrayList(const int a_nSize = DEF_SIZE);

	//! ���� ������
	CArrayList(const CArrayList<T> &a_rOther);

	//! �Ҹ���
	virtual ~CArrayList(void);

private:			// private �Լ�

	//! ũ�⸦ �����Ѵ�
	void resize(const int a_nSize);

private:			// private ����

	int m_nSize = 0;
	int m_nCount = 0;

	T *m_ptValues = nullptr;
};

#include "CArrayList.inl"

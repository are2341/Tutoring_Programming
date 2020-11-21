#pragma once

#include "../../Define/KGDefine.h"

//! 배열 리스트
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

public:			// public 함수

	//! 개수를 반환한다
	int getCount(void) const;

	//! 값을 추가한다
	void addValue(T a_tValue);

	//! 값을 삽입한다
	void insertValue(const int a_nIndex, T a_tValue);

	//! 값을 제거한다
	void removeValue(const int a_nIndex);

public:			// 생성자, 소멸자

	//! 생성자
	CArrayList(const int a_nSize = DEF_SIZE);

	//! 복사 생성자
	CArrayList(const CArrayList<T> &a_rOther);

	//! 소멸자
	virtual ~CArrayList(void);

private:			// private 함수

	//! 크기를 변경한다
	void resize(const int a_nSize);

private:			// private 변수

	int m_nSize = 0;
	int m_nCount = 0;

	T *m_ptValues = nullptr;
};

#include "CArrayList.inl"

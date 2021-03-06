#pragma once

#include "../../Define/KGDefine.h"

//! 연결 리스트
template <typename T>
class CLinkedList {
public:

	//! 노드
	struct STNode {
		T m_tValue;
		STNode *m_pstNextNode;
	};

public:			// operator

	//! operator=
	CLinkedList<T> & operator=(const CLinkedList<T> &a_rOther);

	//! operator[]
	T & operator[](const int a_nIndex);

	//! operator[]
	T operator[](const int a_nIndex) const;

public:			// public 함수

	//! 포함 여부를 검사한다
	bool isContains(T a_tValue) const;

	//! 개수를 반환한다
	int getCount(void) const;

	//! 상태를 리셋한다
	void reset(void);

	//! 값을 추가한다
	void addValue(T a_tValue);

	//! 값을 삽입한다
	void insertValue(const int a_nIndex, T a_tValue);

	//! 값을 제거한다
	void removeValue(const int a_nIndex);

	//! 값을 제거한다
	void removeByValue(T a_tValue);

public:			// 생성자, 소멸자

	//! 생성자
	CLinkedList(void);

	//! 복사 생성자
	CLinkedList(const CLinkedList<T> &a_rOther);

	//! 소멸자
	virtual ~CLinkedList(void);

private:			// private 함수

	//! 이전 노드를 반환한다
	STNode * getPrevNode(const int a_nIndex);

	//! 노드를 생성한다
	STNode * createNode(T a_tValue);

private:			// private 변수

	int m_nCount = 0;
	STNode *m_pstHeadNode = nullptr;
};

#include "CLinkedList.inl"

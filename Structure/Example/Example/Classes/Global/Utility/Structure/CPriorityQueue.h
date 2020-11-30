#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"

//! 우선 순위 큐
template <typename T>
class CPriorityQueue {
public:			// public 함수

	//! 개수를 반환한다
	int getCount(void) const;

	//! 값을 추가한다
	void enqueueValue(T a_tValue);

	//! 값을 제거한다
	T dequeueValue(void);

public:			// 생성자

	//! 생성자
	CPriorityQueue(const int a_nSize = CArrayList<T>::DEF_SIZE);

private:			// private 함수

	//! 힙을 재정렬한다
	void reheapUp(int a_nIndex);

	//! 힙을 재정렬한다
	void reheapDown(int a_nIndex);

private:			// private 변수

	CArrayList<T> m_oValueList;
};

#include "CPriorityQueue.inl"

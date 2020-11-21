#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"

//! 큐
template <typename T>
class CQueue {
public:			// public 함수

	//! 개수를 반환한다
	int getCount(void) const;

	//! 값을 추가한다
	void enqueueValue(T a_tValue);

	//! 값을 제거한다
	T dequeueValue(void);

public:			// 생성자

	//! 생성자
	CQueue(const int a_nSize = CArrayList<T>::DEF_SIZE);

private:			// private 변수

	CArrayList<T> m_oValueList;
};

#include "CQueue.inl"

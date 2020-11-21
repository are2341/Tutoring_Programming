#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"

//! 스택
template <typename T>
class CStack {
public:			// public 함수

	//! 개수를 반환한다
	int getCount(void) const;

	//! 값을 추가한다
	void pushValue(T a_tValue);

	//! 값을 제거한다
	T popValue(void);

public:			// 생성자

	//! 생성자
	CStack(const int a_nSize = CArrayList<T>::DEF_SIZE);

private:			// private 변수

	CArrayList<T> m_oValueList;
};

#include "CStack.inl"

#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"
#include "CLinkedList.h"

//! 해시 테이블
template <typename T>
class CHashTable {
public:

	enum {
		DEF_SIZE = 5
	};

public:			// public 함수

	//! 포함 여부를 검사한다
	bool isContains(T a_tValue) const;

	//! 값을 추가한다
	void addValue(T a_tValue);

	//! 값을 제거한다
	void removeValue(T a_tValue);

	//! 테이블을 순회한다
	void enumerate(const std::function<void (const CLinkedList<T> &, int)> &a_rCallback) const;

public:			// 생성자

	//! 생성자
	CHashTable(const int a_nSize = DEF_SIZE);

private:			// private 함수

	//! 해시 값을 생성한다
	int makeHashValue(T a_tValue) const;

private:			// private 변수

	CArrayList<CLinkedList<T>> m_oValueList;
};

#include "CHashTable.inl"

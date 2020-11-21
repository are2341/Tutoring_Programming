#pragma once

#include "../../Define/KGDefine.h"
#include "CLinkedList.h"

namespace GLOBAL {
	//! 해시 테이블
	template <typename T>
	class CHashTable {
	public:

		enum {
			SIZE = 100
		};

	public:			// public 함수

		//! 데이터 포함 여부를 검사한다
		bool IsContains(T a_tValue);

		//! 데이터를 추가한다
		void AddValue(T a_tValue);

		//! 테이블을 순횐한다
		void EnumerateTable(const std::function<void (CLinkedList<T>, int)> &a_rCallback);

	private:			// private 함수

		//! 해시 값을 생성한다
		int MakeHashValue(T a_tValue);

	private:			// private 변수

		CLinkedList<T> m_oTable[SIZE];
	};
}

#include "CHashTable.inl"

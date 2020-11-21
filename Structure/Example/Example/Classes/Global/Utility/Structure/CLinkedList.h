#pragma once

#include "../../Define/KGDefine.h"

namespace GLOBAL {
	template <typename T>
	class CLinkedList {
	public:

		struct STNode {
			T m_tValue;
			STNode *m_pstNextNode;
		};
		
	public:			// operator
		
		//! operator[]
		int operator[](int a_nIndex);
		
		//! operator=
		CLinkedList<T> & operator=(const CLinkedList &a_rOther);
		
	public:			// public

		bool isContains(T a_tValue);
		
		int getCount(void);
		
		T getValue(int a_nIndex);
		
		void addValue(T a_tValue);
		
		void insertValue(int a_nIndex, T a_tValue);
		
		void removeValue(T a_tValue);
		
	public:
		
		CLinkedList(void);
		
		CLinkedList(const CLinkedList &a_rOther);
		
		virtual ~CLinkedList(void);
	
	private:

		STNode * createNode(T a_tValue);
		
	private:
		
		int m_nCount = 0;
		STNode *m_pstHeadNode = nullptr;
	};
}

#include "CLinkedList.inl"

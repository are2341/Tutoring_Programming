#include "CLinkedList.h"

namespace GLOBAL {
	template <typename T>
	inline CLinkedList<T>::CLinkedList(void) {
		m_pstHeadNode = (STNode *)malloc(sizeof(STNode));
		m_pstHeadNode->m_pstNextNode = nullptr;
	}

	template <typename T>
	inline CLinkedList<T>::CLinkedList(const CLinkedList &a_rOther)
	:
	CLinkedList()
	{
		*this = a_rOther;
	}

	template <typename T>
	inline CLinkedList<T>::~CLinkedList(void) {
		auto pstCurNode = m_pstHeadNode;
		
		while(pstCurNode != nullptr) {
			auto pstRemoveNode = pstCurNode;
			pstCurNode = pstCurNode->m_pstNextNode;
			
			free(pstRemoveNode);
		}
	}

	template <typename T>
	inline int CLinkedList<T>::operator[](int a_nIndex) {
		return this->getValue(a_nIndex);
	}

	template <typename T>
	inline CLinkedList<T> & CLinkedList<T>::operator=(const CLinkedList &a_rOther) {
		auto pstCurNode = m_pstHeadNode->m_pstNextNode;
		
		while(pstCurNode != nullptr) {
			auto pstRemoveNode = pstCurNode;
			pstCurNode = pstCurNode->m_pstNextNode;
			
			free(pstRemoveNode);
		}
		
		pstCurNode = a_rOther.m_pstHeadNode->m_pstNextNode;
		
		while(pstCurNode != nullptr) {
			this->addValue(pstCurNode->m_tValue);
			pstCurNode = pstCurNode->m_pstNextNode;
		}
		
		return *this;
	}

	template<typename T>
	inline bool CLinkedList<T>::isContains(T a_tValue) {
		auto pstCurNode = m_pstHeadNode->m_pstNextNode;

		while(pstCurNode != nullptr) {
			if(pstCurNode->m_tValue == a_tValue) {
				return true;
			}

			pstCurNode = pstCurNode->m_pstNextNode;
		}

		return false;
	}

	template <typename T>
	inline int CLinkedList<T>::getCount(void) {
		return m_nCount;
	}

	template <typename T>
	inline T CLinkedList<T>::getValue(int a_nIndex) {
		auto pstCurNode = m_pstHeadNode->m_pstNextNode;
		
		for(int i = 0; i < a_nIndex; ++i) {
			pstCurNode = pstCurNode->m_pstNextNode;
		}
		
		return pstCurNode->m_tValue;
	}

	template <typename T>
	inline void CLinkedList<T>::addValue(T a_tValue) {
		auto pstTailNode = m_pstHeadNode;
		
		while(pstTailNode->m_pstNextNode != nullptr) {
			pstTailNode = pstTailNode->m_pstNextNode;
		}
		
		m_nCount += 1;
		
		auto pstNewNode = this->createNode(a_tValue);
		pstTailNode->m_pstNextNode = pstNewNode;
	}

	template <typename T>
	inline void CLinkedList<T>::insertValue(int a_nIndex, T a_tValue) {
		auto pstCurNode = m_pstHeadNode;
		
		for(int i = 0; i < a_nIndex; ++i) {
			pstCurNode = pstCurNode->m_pstNextNode;
		}
		
		m_nCount += 1;
		
		auto pstNewNode = this->createNode(a_tValue);
		pstNewNode->m_pstNextNode = pstCurNode->m_pstNextNode;
		pstCurNode->m_pstNextNode = pstNewNode;
	}

	template <typename T>
	inline void CLinkedList<T>::removeValue(T a_tValue) {
		auto pstCurNode = m_pstHeadNode;
		
		while(pstCurNode->m_pstNextNode != nullptr &&
			  pstCurNode->m_pstNextNode->m_tValue != a_tValue)
		{
			pstCurNode = pstCurNode->m_pstNextNode;
		}

		if(pstCurNode->m_pstNextNode != nullptr) {
			auto pstRemoveNode = pstCurNode->m_pstNextNode;
			pstCurNode->m_pstNextNode = pstRemoveNode->m_pstNextNode;
			
			m_nCount -= 1;
			free(pstRemoveNode);
		}
	}

	template <typename T>
	inline typename CLinkedList<T>::STNode * CLinkedList<T>::createNode(T a_tValue) {
		STNode *pstNode = (STNode *)malloc(sizeof(STNode));
		pstNode->m_tValue = a_tValue;
		pstNode->m_pstNextNode = nullptr;
		
		return pstNode;
	}
}

#include "CLinkedList.h"

template<typename T>
inline CLinkedList<T>::CLinkedList(void) {
	m_pstHeadNode = (STNode *)malloc(sizeof(STNode));
	m_pstHeadNode->m_pstNextNode = nullptr;
}

template<typename T>
inline CLinkedList<T>::CLinkedList(const CLinkedList<T>& a_rOther)
: CLinkedList()
{
	*this = a_rOther;
}

template<typename T>
inline CLinkedList<T>::~CLinkedList(void) {
	this->reset();
	free(m_pstHeadNode);
}


template<typename T>
inline CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList<T>& a_rOther) {
	this->reset();

	for(int i = 0; i < a_rOther.m_nCount; ++i) {
		this->addValue(a_rOther[i]);
	}

	return *this;
}

template<typename T>
inline T & CLinkedList<T>::operator[](const int a_nIndex) {
	auto pstNode = this->getPrevNode(a_nIndex);
	return pstNode->m_pstNextNode->m_tValue;
}

template<typename T>
inline T CLinkedList<T>::operator[](const int a_nIndex) const {
	return const_cast<CLinkedList<T> &>(*this)[a_nIndex];
}

template<typename T>
inline bool CLinkedList<T>::isContains(T a_tValue) const {
	auto pstCurNode = m_pstHeadNode;

	while(pstCurNode->m_pstNextNode != nullptr &&
		pstCurNode->m_pstNextNode->m_tValue != a_tValue)
	{
		pstCurNode = pstCurNode->m_pstNextNode;
	}

	return pstCurNode->m_pstNextNode != nullptr;
}

template<typename T>
inline int CLinkedList<T>::getCount(void) const {
	return m_nCount;
}

template<typename T>
inline void CLinkedList<T>::reset(void) {
	auto pstCurNode = m_pstHeadNode->m_pstNextNode;

	while(pstCurNode != nullptr) {
		auto pstRemoveNode = pstCurNode;
		pstCurNode = pstCurNode->m_pstNextNode;

		free(pstRemoveNode);
	}

	m_nCount = 0;
}

template<typename T>
inline void CLinkedList<T>::addValue(T a_tValue) {
	auto pstCurNode = m_pstHeadNode;

	while(pstCurNode->m_pstNextNode != nullptr) {
		pstCurNode = pstCurNode->m_pstNextNode;
	}

	auto pstNewNode = this->createNode(a_tValue);
	pstCurNode->m_pstNextNode = pstNewNode;

	m_nCount += 1;
}

template<typename T>
inline void CLinkedList<T>::insertValue(const int a_nIndex, T a_tValue) {
	auto pstNode = this->getPrevNode(a_nIndex);
	auto pstNewNode = this->createNode(a_tValue);

	pstNewNode->m_pstNextNode = pstNode->m_pstNextNode;
	pstNode->m_pstNextNode = pstNewNode;

	m_nCount += 1;
}

template<typename T>
inline void CLinkedList<T>::removeValue(const int a_nIndex) {
	auto pstNode = this->getPrevNode(a_nIndex);
	pstNode->m_pstNextNode = pstNode->m_pstNextNode->m_pstNextNode;

	m_nCount -= 1;
}

template<typename T>
inline void CLinkedList<T>::removeByValue(T a_tValue) {
	auto pstCurNode = m_pstHeadNode;

	while(pstCurNode->m_pstNextNode != nullptr && 
		pstCurNode->m_pstNextNode->m_tValue != a_tValue)
	{
		pstCurNode = pstCurNode->m_pstNextNode;
	}

	if(pstCurNode->m_pstNextNode != nullptr) {
		pstCurNode->m_pstNextNode = pstCurNode->m_pstNextNode->m_pstNextNode;
		m_nCount -= 1;
	}
}

template<typename T>
inline typename CLinkedList<T>::STNode * CLinkedList<T>::getPrevNode(const int a_nIndex) {
	auto pstCurNode = m_pstHeadNode;

	for(int i = 0; i < a_nIndex; ++i) {
		pstCurNode = pstCurNode->m_pstNextNode;
	}

	return pstCurNode;
}

template<typename T>
inline typename CLinkedList<T>::STNode * CLinkedList<T>::createNode(T a_tValue) {
	auto pstNode = (STNode *)malloc(sizeof(STNode));
	pstNode->m_tValue = a_tValue;
	pstNode->m_pstNextNode = nullptr;

	return pstNode;
}

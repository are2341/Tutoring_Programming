#include "CBinarySearchTree.h"

template<typename T>
inline CBinarySearchTree<T>::CBinarySearchTree(void) {
	// Do Nothing
}

template<typename T>
inline CBinarySearchTree<T>::CBinarySearchTree(const CBinarySearchTree<T>& a_rOther) {
	*this = a_rOther;
}

template<typename T>
inline CBinarySearchTree<T>::~CBinarySearchTree(void) {
	this->reset();
}

template<typename T>
inline CBinarySearchTree<T>& CBinarySearchTree<T>::operator=(const CBinarySearchTree<T>& a_rOther) {
	this->reset();

	this->enumerateByPreOrder(a_rOther.m_pstRootNode, [=](STNode *a_pstNode) -> void {
		this->addValue(a_pstNode->m_tValue);
	});

	return *this;
}

template<typename T>
inline bool CBinarySearchTree<T>::isContains(T a_tValue) {
	auto pstCurNode = &m_pstRootNode;

	while(*pstCurNode != nullptr && 
		(*pstCurNode)->m_tValue != a_tValue)
	{
		if(a_tValue < (*pstCurNode)->m_tValue) {
			pstCurNode = &(*pstCurNode)->m_pstLChildNode;
		} else {
			pstCurNode = &(*pstCurNode)->m_pstRChildNode;
		}
	}

	return *pstCurNode != nullptr;
}

template<typename T>
inline void CBinarySearchTree<T>::reset(void) {
	this->enumerateByPostOrder(m_pstRootNode, [=](STNode *a_pstNode) -> void {
		free(a_pstNode);
	});
}

template<typename T>
inline void CBinarySearchTree<T>::addValue(T a_tValue, const std::function<bool (T, T)> &a_rCompare) {
	auto pstCurNode = &m_pstRootNode;

	while(*pstCurNode != nullptr) {
		if(a_rCompare(a_tValue, (*pstCurNode)->m_tValue)) {
			pstCurNode = &(*pstCurNode)->m_pstLChildNode;
		} else {
			pstCurNode = &(*pstCurNode)->m_pstRChildNode;
		}
	}

	auto pstNewNode = this->createNode(a_tValue);
	*pstCurNode = pstNewNode;
}

template<typename T>
inline void CBinarySearchTree<T>::removeValue(T a_tValue) {
	auto pstCurNode = &m_pstRootNode;

	while(*pstCurNode != nullptr && 
		(*pstCurNode)->m_tValue != a_tValue)
	{
		if(a_tValue < (*pstCurNode)->m_tValue) {
			pstCurNode = &(*pstCurNode)->m_pstLChildNode;
		} else {
			pstCurNode = &(*pstCurNode)->m_pstRChildNode;
		}
	}

	if(*pstCurNode != nullptr) {
		auto pstChildNode = pstCurNode;
		
		// 자식이 두 개 일 경우
		if((*pstChildNode)->m_pstLChildNode != nullptr &&
			(*pstChildNode)->m_pstRChildNode != nullptr)
		{
			// 왼쪽 노드에서 후손 노드를 탐색한다
			while((*pstChildNode)->m_pstRChildNode != nullptr) {
				pstChildNode = &(*pstChildNode)->m_pstRChildNode;
			}
		}

		auto pstRemoveNode = *pstChildNode;

		// 제거 할 노드의 왼쪽 자식이 존재 할 경우
		if(pstRemoveNode->m_pstLChildNode != nullptr) {
			*pstChildNode = pstRemoveNode->m_pstLChildNode;
		} else {
			*pstChildNode = pstRemoveNode->m_pstRChildNode;
		}
	}
}

template<typename T>
inline void CBinarySearchTree<T>::enumerate(EOrderType a_eOrderType, const std::function<void(STNode *)>& a_rCallback) {
	switch(a_eOrderType) {
		case EOrderType::PRE: this->enumerateByPreOrder(m_pstRootNode, a_rCallback); break;
		case EOrderType::IN: this->enumerateByInOrder(m_pstRootNode, a_rCallback); break;
		case EOrderType::POST: this->enumerateByPostOrder(m_pstRootNode, a_rCallback); break;
	}
}

template<typename T>
inline typename CBinarySearchTree<T>::STNode * CBinarySearchTree<T>::createNode(T a_tValue) {
	auto pstNode = (STNode *)malloc(sizeof(STNode));
	pstNode->m_tValue = a_tValue;
	pstNode->m_pstLChildNode = nullptr;
	pstNode->m_pstRChildNode = nullptr;

	return pstNode;
}

template<typename T>
inline void CBinarySearchTree<T>::enumerateByPreOrder(STNode *a_pstNode, const std::function<void(STNode *)>& a_rCallback) {
	if(a_pstNode != nullptr) {
		a_rCallback(a_pstNode);

		this->enumerateByPreOrder(a_pstNode->m_pstLChildNode, a_rCallback);
		this->enumerateByPreOrder(a_pstNode->m_pstRChildNode, a_rCallback);
	}
}

template<typename T>
inline void CBinarySearchTree<T>::enumerateByInOrder(STNode *a_pstNode, const std::function<void(STNode *)>& a_rCallback) {
	if(a_pstNode != nullptr) {
		this->enumerateByInOrder(a_pstNode->m_pstLChildNode, a_rCallback);

		a_rCallback(a_pstNode);
		this->enumerateByInOrder(a_pstNode->m_pstRChildNode, a_rCallback);
	}
}

template<typename T>
inline void CBinarySearchTree<T>::enumerateByPostOrder(STNode *a_pstNode, const std::function<void(STNode *)>& a_rCallback) {
	if(a_pstNode != nullptr) {
		this->enumerateByPostOrder(a_pstNode->m_pstLChildNode, a_rCallback);
		this->enumerateByPostOrder(a_pstNode->m_pstRChildNode, a_rCallback);

		a_rCallback(a_pstNode);
	}
}
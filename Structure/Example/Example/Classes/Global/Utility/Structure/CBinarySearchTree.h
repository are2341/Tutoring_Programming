#pragma once

#include "../../Define/KGDefine.h"

//! 이진 탐색 트리
template <typename T>
class CBinarySearchTree {
public:

	//! 순회 타입
	enum class EOrderType {
		NONE = -1,
		PRE,
		IN,
		POST,
		MAX_VALUE
	};

	//! 노드
	struct STNode {
		T m_tValue;

		STNode *m_pstLChildNode;
		STNode *m_pstRChildNode;
	};
	
public:			// operator

	//! operator=
	CBinarySearchTree<T> & operator=(const CBinarySearchTree<T> &a_rOther);

public:			// public 함수

	//! 포함 여부를 검사한다
	bool isContains(T a_tValue);

	//! 상태를 리셋한다
	void reset(void);

	//! 값을 추가한다
	void addValue(T a_tValue, const std::function<bool (T, T)> &a_rCompare);

	//! 값을 제거한다
	void removeValue(T a_tValue);

	//! 순회를 수행한다
	void enumerate(EOrderType a_eOrderType, const std::function<void (STNode *)> &a_rCallback);

public:			// 생성자, 소멸자

	//! 생성자
	CBinarySearchTree(void);

	//! 복사 생성자
	CBinarySearchTree(const CBinarySearchTree<T> &a_rOther);

	//! 소멸자
	~CBinarySearchTree(void);

private:			// private 함수

	//! 노드를 생성한다
	STNode * createNode(T a_tValue);

	//! 전위 순회를 수행한다
	void enumerateByPreOrder(STNode *a_pstNode, const std::function<void (STNode *)> &a_rCallback);

	//! 중위 순회를 수행한다
	void enumerateByInOrder(STNode *a_pstNode, const std::function<void (STNode *)> &a_rCallback);

	//! 후위 순회를 수행한다
	void enumerateByPostOrder(STNode *a_pstNode, const std::function<void (STNode *)> &a_rCallback);

private:			// private 변수

	STNode *m_pstRootNode = nullptr;
};

#include "CBinarySearchTree.inl"

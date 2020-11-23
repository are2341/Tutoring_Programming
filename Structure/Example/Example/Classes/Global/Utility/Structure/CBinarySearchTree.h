#pragma once

#include "../../Define/KGDefine.h"

//! ���� Ž�� Ʈ��
template <typename T>
class CBinarySearchTree {
public:

	//! ��ȸ Ÿ��
	enum class EOrderType {
		NONE = -1,
		PRE,
		IN,
		POST,
		MAX_VALUE
	};

	//! ���
	struct STNode {
		T m_tValue;

		STNode *m_pstLChildNode;
		STNode *m_pstRChildNode;
	};
	
public:			// operator

	//! operator=
	CBinarySearchTree<T> & operator=(const CBinarySearchTree<T> &a_rOther);

public:			// public �Լ�

	//! ���� ���θ� �˻��Ѵ�
	bool isContains(T a_tValue);

	//! ���¸� �����Ѵ�
	void reset(void);

	//! ���� �߰��Ѵ�
	void addValue(T a_tValue, const std::function<bool (T, T)> &a_rCompare);

	//! ���� �����Ѵ�
	void removeValue(T a_tValue);

	//! ��ȸ�� �����Ѵ�
	void enumerate(EOrderType a_eOrderType, const std::function<void (STNode *)> &a_rCallback);

public:			// ������, �Ҹ���

	//! ������
	CBinarySearchTree(void);

	//! ���� ������
	CBinarySearchTree(const CBinarySearchTree<T> &a_rOther);

	//! �Ҹ���
	~CBinarySearchTree(void);

private:			// private �Լ�

	//! ��带 �����Ѵ�
	STNode * createNode(T a_tValue);

	//! ���� ��ȸ�� �����Ѵ�
	void enumerateByPreOrder(STNode *a_pstNode, const std::function<void (STNode *)> &a_rCallback);

	//! ���� ��ȸ�� �����Ѵ�
	void enumerateByInOrder(STNode *a_pstNode, const std::function<void (STNode *)> &a_rCallback);

	//! ���� ��ȸ�� �����Ѵ�
	void enumerateByPostOrder(STNode *a_pstNode, const std::function<void (STNode *)> &a_rCallback);

private:			// private ����

	STNode *m_pstRootNode = nullptr;
};

#include "CBinarySearchTree.inl"

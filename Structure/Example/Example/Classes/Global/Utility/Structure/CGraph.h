#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"
#include "CLinkedList.h"

//! �׷���
template <typename KEY, typename VALUE>
class CGrpah {
public:

	//! ���
	struct STNode {
		KEY m_tKey;
		VALUE m_tValue;
	};

public:			// public �Լ�

	//! ���� ���θ� �˻��Ѵ�
	bool isContains(KEY a_tKey) const;

	//! ���� �߰��Ѵ�
	void addValue(KEY a_tKey, VALUE a_tValue);

	//! ������ �߰��Ѵ�
	void addEdge(KEY a_tFrom, KEY a_tTo);

private:			// private ����

	CArrayList<STNode> m_oNodeList;
	CArrayList<CArrayList<bool>> m_oEdgeMatrix;
};

#include "CGraph.inl"

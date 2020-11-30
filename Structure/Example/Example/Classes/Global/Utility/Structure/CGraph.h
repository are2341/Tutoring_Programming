#pragma once

#include "../../Define/KGDefine.h"
#include "CArrayList.h"
#include "CLinkedList.h"

//! 그래프
template <typename KEY, typename VALUE>
class CGrpah {
public:

	//! 노드
	struct STNode {
		KEY m_tKey;
		VALUE m_tValue;
	};

public:			// public 함수

	//! 포함 여부를 검사한다
	bool isContains(KEY a_tKey) const;

	//! 값을 추가한다
	void addValue(KEY a_tKey, VALUE a_tValue);

	//! 엣지를 추가한다
	void addEdge(KEY a_tFrom, KEY a_tTo);

private:			// private 변수

	CArrayList<STNode> m_oNodeList;
	CArrayList<CArrayList<bool>> m_oEdgeMatrix;
};

#include "CGraph.inl"

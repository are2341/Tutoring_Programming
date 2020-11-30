#include "CGraph.h"

template<typename KEY, typename VALUE>
inline bool CGrpah<KEY, VALUE>::isContains(KEY a_tKey) const {
	for(int i = 0; i < m_oNodeList.getCount(); ++i) {
		if(m_oNodeList[i].m_tKey == a_tKey) {
			return true;
		}
	}

	return false;
}

template<typename KEY, typename VALUE>
inline void CGrpah<KEY, VALUE>::addValue(KEY a_tKey, VALUE a_tValue) {
	if(!this->isContains(a_tKey)) {
		STNode stNode = {
			a_tKey, a_tValue;
		};

		m_oNodeList.addValue(stNode);
	}
}

template<typename KEY, typename VALUE>
inline void CGrpah<KEY, VALUE>::addEdge(KEY a_tFrom, KEY a_tTo) {
	if(this->isContains(a_tFrom) && this->isContains(a_tKey)) {

	}
}

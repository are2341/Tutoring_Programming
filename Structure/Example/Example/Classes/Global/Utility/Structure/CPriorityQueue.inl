#include "CPriorityQueue.h"

template<typename T>
inline CPriorityQueue<T>::CPriorityQueue(const int a_nSize)
:
m_oValueList(a_nSize)
{
	// Do Nothing
}

template<typename T>
inline int CPriorityQueue<T>::getCount(void) const {
	return m_oValueList.getCount();
}

template<typename T>
inline void CPriorityQueue<T>::enqueueValue(T a_tValue) {
	m_oValueList.addValue(a_tValue);
	this->reheapUp(m_oValueList.getCount() - 1);
}

template<typename T>
inline T CPriorityQueue<T>::dequeueValue(void) {
	T tValue = m_oValueList[0];
	int nLastIndex = m_oValueList.getCount() - 1;

	m_oValueList[0] = m_oValueList[nLastIndex];
	this->reheapDown(0);

	m_oValueList.removeValue(nLastIndex);
	return tValue;
}

template<typename T>
inline void CPriorityQueue<T>::reheapUp(int a_nIndex) {
	if(a_nIndex > 0) {
		int nParent = (a_nIndex - 1) / 2;

		if(m_oValueList[nParent] > m_oValueList[a_nIndex]) {
			std::swap(m_oValueList[nParent], m_oValueList[a_nIndex]);
			this->reheapUp(nParent);
		}
	}
}

template<typename T>
inline void CPriorityQueue<T>::reheapDown(int a_nIndex) {
	if(a_nIndex < m_oValueList.getCount() / 2) {
		int nCompare = (a_nIndex * 2) + 1;

		if(nCompare + 1 < m_oValueList.getCount()) {
			int nRChild = nCompare + 1;
			nCompare = (m_oValueList[nCompare] <= m_oValueList[nRChild]) ? nCompare : nRChild;
		}

		if(m_oValueList[nCompare] < m_oValueList[a_nIndex]) {
			std::swap(m_oValueList[nCompare], m_oValueList[a_nIndex]);
			this->reheapDown(nCompare);
		}
	}
}

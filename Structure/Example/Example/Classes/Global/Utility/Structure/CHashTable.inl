#include "CHashTable.h"

template<typename T>
inline CHashTable<T>::CHashTable(const int a_nSize) 
:
m_oValueList(a_nSize)
{
	for(int i = 0; i < a_nSize; ++i) {
		m_oValueList.addValue(CLinkedList<T>());
	}
}

template<typename T>
inline bool CHashTable<T>::isContains(T a_tValue) const {
	int nIndex = this->makeHashValue(a_tValue);
	return m_oValueList[nIndex].isContains(a_tValue);
}

template<typename T>
inline void CHashTable<T>::addValue(T a_tValue) {
	int nIndex = this->makeHashValue(a_tValue);
	m_oValueList[nIndex].addValue(a_tValue);
}

template<typename T>
inline void CHashTable<T>::removeValue(T a_tValue) {
	int nIndex = this->makeHashValue(a_tValue);
	m_oValueList[nIndex].removeByValue(a_tValue);
}

template<typename T>
inline void CHashTable<T>::enumerate(const std::function<void(const CLinkedList<T> &, int)>& a_rCallback) const {
	for(int i = 0; i < m_oValueList.getCount(); ++i) {
		a_rCallback(m_oValueList[i], i);
	}
}

template<typename T>
inline int CHashTable<T>::makeHashValue(T a_tValue) const {
	std::hash<T> oHash;
	return oHash(a_tValue) % m_oValueList.getCount();
}

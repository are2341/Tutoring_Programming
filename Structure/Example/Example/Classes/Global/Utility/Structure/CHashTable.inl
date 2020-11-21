#include "CHashTable.h"

namespace GLOBAL {
	template<typename T>
	inline bool CHashTable<T>::IsContains(T a_tValue) {
		int nHashValue = this->MakeHashValue(a_tValue);
		nHashValue = std::abs(nHashValue);

		return m_oTable[nHashValue % SIZE].isContains(a_tValue);
	}
	template<typename T>
	inline void CHashTable<T>::AddValue(T a_tValue) {
	}
	template<typename T>
	inline void CHashTable<T>::EnumerateTable(const std::function<void(CLinkedList<T>, int)>& a_rCallback) {
	}
	template<typename T>
	inline int CHashTable<T>::MakeHashValue(T a_tValue) {
		return 0;
	}
}

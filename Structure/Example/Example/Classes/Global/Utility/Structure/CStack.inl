#include "CStack.h"

template<typename T>
inline CStack<T>::CStack(const int a_nSize) 
:
m_oValueList(a_nSize)
{
	// Do Nothing
}

template<typename T>
inline int CStack<T>::getCount(void) const {
	return m_oValueList.getCount();
}

template<typename T>
inline void CStack<T>::pushValue(T a_tValue) {
	m_oValueList.addValue(a_tValue);
}

template<typename T>
inline T CStack<T>::popValue(void) {
	int nLastIndex = m_oValueList.getCount() - 1;

	T tValue = m_oValueList[nLastIndex];
	m_oValueList.removeValue(nLastIndex);

	return tValue;
}

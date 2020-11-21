#include "CQueue.h"

template<typename T>
inline CQueue<T>::CQueue(const int a_nSize) 
:
m_oValueList(a_nSize)
{
	// Do Nothing
}

template<typename T>
inline int CQueue<T>::getCount(void) const {
	return m_oValueList.getCount();
}

template<typename T>
inline void CQueue<T>::enqueueValue(T a_tValue) {
	m_oValueList.addValue(a_tValue);
}

template<typename T>
inline T CQueue<T>::dequeueValue(void) {
	T tValue = m_oValueList[0];
	m_oValueList.removeValue(0);

	return tValue;
}

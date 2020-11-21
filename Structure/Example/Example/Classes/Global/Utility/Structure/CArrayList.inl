#include "CArrayList.h"

template<typename T>
inline CArrayList<T>::CArrayList(const int a_nSize) 
:
m_nSize(a_nSize)
{
	m_ptValues = new T[a_nSize];
}

template<typename T>
inline CArrayList<T>::CArrayList(const CArrayList<T>& a_rOther) {
	*this = a_rOther;
}

template<typename T>
inline CArrayList<T>::~CArrayList(void) {
	delete[] m_ptValues;
}

template<typename T>
inline CArrayList<T>& CArrayList<T>::operator=(const CArrayList<T>& a_rOther) {
	if(m_ptValues != nullptr) {
		delete[] m_ptValues;
	}

	m_nSize = a_rOther.m_nSize;
	m_nCount = 0;

	m_ptValues = new T[a_rOther.m_nSize];

	for(int i = 0; i < a_rOther.m_nCount; ++i) {
		this->addValue(a_rOther.m_ptValues[i]);
	}

	return *this;
}

template<typename T>
inline T & CArrayList<T>::operator[](const int a_nIndex) {
	return m_ptValues[a_nIndex];
}

template<typename T>
inline T CArrayList<T>::operator[](const int a_nIndex) const {
	return const_cast<CArrayList<T> &>(*this)[a_nIndex];
}

template<typename T>
inline int CArrayList<T>::getCount(void) const {
	return m_nCount;
}

template<typename T>
inline void CArrayList<T>::addValue(T a_tValue) {
	if(m_nCount >= m_nSize) {
		this->resize(m_nSize * 2);
	}

	m_ptValues[m_nCount++] = a_tValue;
}

template<typename T>
inline void CArrayList<T>::insertValue(const int a_nIndex, T a_tValue) {
	if(m_nCount >= m_nSize) {
		this->resize(m_nSize * 2);
	}

	for(int i = m_nCount; i > a_nIndex; --i) {
		m_ptValues[i] = m_ptValues[i - 1];
	}

	m_nCount += 1;
	m_ptValues[a_nIndex] = a_tValue;
}

template<typename T>
inline void CArrayList<T>::removeValue(const int a_nIndex) {
	for(int i = a_nIndex; i < m_nCount - 1; ++i) {
		m_ptValues[i] = m_ptValues[i + 1];
	}

	m_nCount -= 1;
}

template<typename T>
inline void CArrayList<T>::resize(const int a_nSize) {
	int nNewCount = (a_nSize < m_nCount) ? a_nSize : m_nCount;
	auto ptNewValues = new T[a_nSize];

	for(int i = 0; i < nNewCount; ++i) {
		ptNewValues[i] = m_ptValues[i];
	}

	m_nSize = a_nSize;
	m_nCount = nNewCount;

	delete[] m_ptValues;
	m_ptValues = ptNewValues;
}

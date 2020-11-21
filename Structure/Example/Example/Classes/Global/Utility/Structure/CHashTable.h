#pragma once

#include "../../Define/KGDefine.h"
#include "CLinkedList.h"

namespace GLOBAL {
	//! �ؽ� ���̺�
	template <typename T>
	class CHashTable {
	public:

		enum {
			SIZE = 100
		};

	public:			// public �Լ�

		//! ������ ���� ���θ� �˻��Ѵ�
		bool IsContains(T a_tValue);

		//! �����͸� �߰��Ѵ�
		void AddValue(T a_tValue);

		//! ���̺��� ��Ⱥ�Ѵ�
		void EnumerateTable(const std::function<void (CLinkedList<T>, int)> &a_rCallback);

	private:			// private �Լ�

		//! �ؽ� ���� �����Ѵ�
		int MakeHashValue(T a_tValue);

	private:			// private ����

		CLinkedList<T> m_oTable[SIZE];
	};
}

#include "CHashTable.inl"

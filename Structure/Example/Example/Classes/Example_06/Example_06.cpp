#include "Example_06.h"
#include "../Global/Utility/Structure/CBinarySearchTree.h"

namespace EXAMPLE_06 {
	struct STData {
		int m_nValue;
		float m_fValue;
		std::string m_oString;
	};

	//! ���� Ž�� Ʈ���� �ʱ�ȭ�Ѵ�
	void InitBinarySearchTree(CBinarySearchTree<int> &a_rValueList, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			int nValue = (rand() % 100) + 1;
			a_rValueList.addValue(nValue);
		}
	}

	//! ���� Ž�� Ʈ���� ����Ѵ�
	void PrintBinarySearchTree(CBinarySearchTree<int> a_oValueList, CBinarySearchTree<int>::EOrderType a_eOrderType) {
		a_oValueList.enumerate(a_eOrderType, [=](CBinarySearchTree<int>::STNode *a_pstNode) -> void {
			printf("%d, ", a_pstNode->m_tValue);
		});

		printf("\n");
	}

	void Example_06(const int argc, const char ** args) {
		CBinarySearchTree<int> oValueList;
		InitBinarySearchTree(oValueList, 10);

		printf("===== ���� ��� =====\n");
		PrintBinarySearchTree(oValueList, CBinarySearchTree<int>::EOrderType::IN);
		
		oValueList.removeValue(3);
		oValueList.removeValue(7);

		printf("\n===== ���� �� ��� =====\n");
		PrintBinarySearchTree(oValueList, CBinarySearchTree<int>::EOrderType::IN);
	}
}

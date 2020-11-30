#include "Example_06.h"
#include "../Global/Utility/Structure/CBinarySearchTree.h"

namespace EXAMPLE_06 {
	struct STData {
		int m_nValue;
		float m_fValue;
		std::string m_oString;
	};

	//! 이진 탐색 트리를 초기화한다
	void InitBinarySearchTree(CBinarySearchTree<int> &a_rValueList, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			int nValue = (rand() % 100) + 1;
			a_rValueList.addValue(nValue);
		}
	}

	//! 이진 탐색 트리를 출력한다
	void PrintBinarySearchTree(CBinarySearchTree<int> a_oValueList, CBinarySearchTree<int>::EOrderType a_eOrderType) {
		a_oValueList.enumerate(a_eOrderType, [=](CBinarySearchTree<int>::STNode *a_pstNode) -> void {
			printf("%d, ", a_pstNode->m_tValue);
		});

		printf("\n");
	}

	void Example_06(const int argc, const char ** args) {
		CBinarySearchTree<int> oValueList;
		InitBinarySearchTree(oValueList, 10);

		printf("===== 원본 요소 =====\n");
		PrintBinarySearchTree(oValueList, CBinarySearchTree<int>::EOrderType::IN);
		
		oValueList.removeValue(3);
		oValueList.removeValue(7);

		printf("\n===== 삭제 후 요소 =====\n");
		PrintBinarySearchTree(oValueList, CBinarySearchTree<int>::EOrderType::IN);
	}
}

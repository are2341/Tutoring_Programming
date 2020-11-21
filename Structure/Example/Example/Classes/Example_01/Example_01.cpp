#include "Example_01.h"
#include "../Global/Utility/Structure/CArrayList.h"

namespace EXAMPLE_01 {
	//! �迭 ����Ʈ�� �ʱ�ȭ�Ѵ�
	void InitArrayList(CArrayList<int> &a_rValueList, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			a_rValueList.addValue(i + 1);
		}
	}

	//! �迭 ����Ʈ�� ����Ѵ�
	void PrintArrayList(const CArrayList<int> &a_rValueList) {
		for(int i = 0; i < a_rValueList.getCount(); ++i) {
			printf("%d, ", a_rValueList[i]);
		}

		printf("\n");
	}

	void Example_01(const int argc, const char ** args) {
		CArrayList<int> oValueList;
		InitArrayList(oValueList, 10);

		printf("===== ���� ��� =====\n");
		PrintArrayList(oValueList);

		oValueList.insertValue(0, 100);

		printf("\n===== ������ ���� �� =====\n");
		PrintArrayList(oValueList);

		oValueList.removeValue(5);

		printf("\n===== ������ ���� �� =====\n");
		PrintArrayList(oValueList);
	}
}

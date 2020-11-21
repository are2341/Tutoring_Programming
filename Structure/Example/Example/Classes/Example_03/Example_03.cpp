#include "Example_03.h"
#include "../Global/Utility/Structure/CStack.h"

namespace EXAMPLE_03 {
	//! ������ �ʱ�ȭ�Ѵ�
	void InitStack(CStack<int> &a_rStack, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			a_rStack.pushValue(i + 1);
		}
	}

	//! ������ ����Ѵ�
	void PrintStack(CStack<int> &a_rStack) {
		while(a_rStack.getCount() >= 1) {
			printf("%d, ", a_rStack.popValue());
		}

		printf("\n");
	}

	void Example_03(const int argc, const char ** args) {
		CStack<int> oStack;
		InitStack(oStack, 10);

		printf("===== ���� ��� =====\n");
		PrintStack(oStack);
	}
}

#include "Example_03.h"
#include "../Global/Utility/Structure/CStack.h"

namespace EXAMPLE_03 {
	//! 스택을 초기화한다
	void InitStack(CStack<int> &a_rStack, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			a_rStack.pushValue(i + 1);
		}
	}

	//! 스택을 출력한다
	void PrintStack(CStack<int> &a_rStack) {
		while(a_rStack.getCount() >= 1) {
			printf("%d, ", a_rStack.popValue());
		}

		printf("\n");
	}

	void Example_03(const int argc, const char ** args) {
		CStack<int> oStack;
		InitStack(oStack, 10);

		printf("===== 스택 요소 =====\n");
		PrintStack(oStack);
	}
}

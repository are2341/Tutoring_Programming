#include "Example_07.h"
#include "../Global/Utility/Structure/CPriorityQueue.h"

namespace EXAMPLE_07 {
	//! 우선 순위 큐를 초기화한다
	void InitPriorityQueue(CPriorityQueue<int> &a_rStack, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			int nValue = (rand() % 100) + 1;
			a_rStack.enqueueValue(nValue);
		}
	}

	//! 우선 순위 큐를 출력한다
	void PrintPriorityQueue(CPriorityQueue<int> &a_rStack) {
		while(a_rStack.getCount() >= 1) {
			printf("%d, ", a_rStack.dequeueValue());
		}

		printf("\n");
	}

	void Example_07(const int argc, const char ** args) {
		CPriorityQueue<int> oStack;
		InitPriorityQueue(oStack, 10);

		printf("===== 우선 순위 큐 요소 =====\n");
		PrintPriorityQueue(oStack);
	}
}

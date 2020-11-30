#include "Example_07.h"
#include "../Global/Utility/Structure/CPriorityQueue.h"

namespace EXAMPLE_07 {
	//! �켱 ���� ť�� �ʱ�ȭ�Ѵ�
	void InitPriorityQueue(CPriorityQueue<int> &a_rStack, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			int nValue = (rand() % 100) + 1;
			a_rStack.enqueueValue(nValue);
		}
	}

	//! �켱 ���� ť�� ����Ѵ�
	void PrintPriorityQueue(CPriorityQueue<int> &a_rStack) {
		while(a_rStack.getCount() >= 1) {
			printf("%d, ", a_rStack.dequeueValue());
		}

		printf("\n");
	}

	void Example_07(const int argc, const char ** args) {
		CPriorityQueue<int> oStack;
		InitPriorityQueue(oStack, 10);

		printf("===== �켱 ���� ť ��� =====\n");
		PrintPriorityQueue(oStack);
	}
}

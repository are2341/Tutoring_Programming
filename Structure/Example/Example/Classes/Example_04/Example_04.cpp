#include "Example_04.h"
#include "../Global/Utility/Structure/CQueue.h"

namespace EXAMPLE_04 {
	//! 큐를 초기화한다
	void InitQueue(CQueue<int> &a_rQueue, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			a_rQueue.enqueueValue(i + 1);
		}
	}

	//! 큐를 출력한다
	void PrintQueue(CQueue<int> &a_rQueue) {
		while(a_rQueue.getCount() >= 1) {
			printf("%d, ", a_rQueue.dequeueValue());
		}

		printf("\n");
	}

	void Example_04(const int argc, const char ** args) {
		CQueue<int> oQueue;
		InitQueue(oQueue, 10);

		printf("===== 큐 요소 =====\n");
		PrintQueue(oQueue);
	}
}

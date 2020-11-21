#pragma once

#include "../Global/Define/KGDefine.h"

/*
* 배열 리스트란?
* :
* - 배열의 원리를 통해서 데이터의 순차성을 보장하는 자료구조로써, 메모리의 물리적인 순서와 데이터의 순서가
* 일치하는 자료구조이다.
* 
* 배열 리스트 장점
* :
* - 배열 원리를 통해서 구현된 자료구조이기 때문에 데이터의 위치 (순서) 를 알고 있다면 인덱스를 통해서
* 상수 시간에 접근하는 것이 가능하다. (즉, 랜덤 엑세스가 가능하다.)
* 
* 배열 리스트 단점
* :
* - 메모리의 물리적인 순서에 의존해서 데이터의 순차성을 보장하기 때문에 리스트 중간에 데이터의 삽입/삭제가 발생 할 경우
* 대량의 데이터 이동이 발생한다. (즉, 리스트의 크기가 커질수록 삽입/삭제에 따른 퍼포먼스 저하가 발생한다.)
*/
namespace EXAMPLE_01 {
	//! Example 1
	void Example_01(const int argc, const char **args);
}

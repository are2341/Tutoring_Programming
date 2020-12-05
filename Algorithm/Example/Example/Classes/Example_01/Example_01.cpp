#include "Example_01.h"

namespace EXAMPLE_01 {
	//! 위치
	struct STCoord {
		int m_nX;
		int m_nY;
	};

	//! 노드
	struct STNode {
		int m_nFValue;
		STCoord m_stCoord;

		STNode *m_pstPrevNode;
	};

	//! 노드를 생성한다
	STNode * CreateNode(int a_nFValue, STCoord a_stCoord) {
		auto pstNode = (STNode *)malloc(sizeof(STNode));
		pstNode->m_nFValue = a_nFValue;
		pstNode->m_stCoord = a_stCoord;
		pstNode->m_pstPrevNode = nullptr;

		return pstNode;
	}

	//! 경로를 탐색한다
	std::stack<STCoord> FindPathByAStar(char (*a_pszMap)[5], 
		int a_nWidth, int a_nHeight, STCoord a_stFrom, STCoord a_stTo) 
	{
		std::vector<STNode *> oOpenNodeList;
		std::vector<STNode *> oCloseNodeList;

		auto pstCurNode = CreateNode(0, a_stFrom);
		oOpenNodeList.push_back(pstCurNode);

		while(oOpenNodeList.size() >= 1) {
			pstCurNode = oOpenNodeList.front();

			oCloseNodeList.push_back(pstCurNode);
			oOpenNodeList.erase(oOpenNodeList.begin());

			// 목적지에 도달했을 경우
			if(pstCurNode->m_stCoord.m_nX == a_stTo.m_nX &&
				pstCurNode->m_stCoord.m_nY == a_stTo.m_nY)
			{
				std::stack<STCoord> oPathList;

				while(pstCurNode != nullptr) {
					oPathList.push(pstCurNode->m_stCoord);
					pstCurNode = pstCurNode->m_pstPrevNode;
				}

				for(int i = 0; i < oOpenNodeList.size(); ++i) {
					free(oOpenNodeList[i]);
				}

				for(int i = 0; i < oCloseNodeList.size(); ++i) {
					free(oCloseNodeList[i]);
				}

				return oPathList;
			}

			STCoord astNextCoords[] = {
				{ pstCurNode->m_stCoord.m_nX + 1, pstCurNode->m_stCoord.m_nY },
				{ pstCurNode->m_stCoord.m_nX - 1, pstCurNode->m_stCoord.m_nY },
				{ pstCurNode->m_stCoord.m_nX, pstCurNode->m_stCoord.m_nY + 1 },
				{ pstCurNode->m_stCoord.m_nX, pstCurNode->m_stCoord.m_nY - 1 }
			};

			const int nSize = sizeof(astNextCoords) / sizeof(astNextCoords[0]);

			for(int i = 0; i < nSize; ++i) {
				auto stNextCoord = astNextCoords[i];

				if(stNextCoord.m_nX < 0 || stNextCoord.m_nX >= a_nWidth ||
					stNextCoord.m_nY < 0 || stNextCoord.m_nY >= a_nHeight)
				{
					continue;
				}

				if(a_pszMap[stNextCoord.m_nY][stNextCoord.m_nX] == 'x') {
					continue;
				}

				int nFValue = pstCurNode->m_nFValue + 1;

				int nGValue = nFValue + 
					(std::abs(stNextCoord.m_nX - a_stTo.m_nX) + 
					std::abs(stNextCoord.m_nY - a_stTo.m_nY));

				auto oIterator = std::find_if(oCloseNodeList.begin(),
					oCloseNodeList.end(), [stNextCoord](STNode *a_pstNode) -> bool 
				{
					return a_pstNode->m_stCoord.m_nX == stNextCoord.m_nX &&
						a_pstNode->m_stCoord.m_nY == stNextCoord.m_nY;
				});

				// 방문한 노드가 아닐 경우
				if(oIterator == oCloseNodeList.end()) {
					auto pstNextNode = CreateNode(nFValue, stNextCoord);
					pstNextNode->m_pstPrevNode = pstCurNode;

					oOpenNodeList.push_back(pstNextNode);
				}
				// 현재 노드 탐색 비용이 더 적을 경우
				else if(nFValue < (*oIterator)->m_nFValue) {
					(*oIterator)->m_nFValue = nFValue;
					(*oIterator)->m_pstPrevNode = pstCurNode;
				}
			}
		}
	}

	void Example_01(const int argc, const char ** args) {
		char pszMap[5][5] = {
			's', '_', 'x', '_', '_',
			'_', '_', '_', '_', '_',
			'_', '_', 'x', '_', '_',
			'_', '_', '_', '_', '_',
			'_', '_', 'x', '_', 'e'
		};

		STCoord stStart = { 
			0, 0
		};

		STCoord stEnd = {
			4, 4
		};

		auto oPath = FindPathByAStar(pszMap, 5, 5, stStart, stEnd);

		while(!oPath.empty()) {
			auto stCoord = oPath.top();
			oPath.pop();

			pszMap[stCoord.m_nY][stCoord.m_nX] = '*';
		}

		for(int i = 0; i < 5; ++i) {
			for(int j = 0; j < 5; ++j) {
				printf("%c ", pszMap[i][j]);
			}

			printf("\n");
		}
	}
}

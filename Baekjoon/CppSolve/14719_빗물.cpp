#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 처음 풀이
int CountRainWater(const vector<int>& hole)
{
	int wallY = 0, wallX = 0, blocks = 0, sum = 0;
	int curY, width, height;

	for (int curX = 0; curX < hole.size(); curX++)
	{
		curY = hole[curX];
		// 현재 길이가 기존값(초기값or첫벽)보다 클 경우
		if (wallY <= curY)
		{
			// 첫 벽
			if (0 == wallY)
			{
				wallY = curY;
				wallX = curX;
			}
			// 두번째 벽이라면 빗물 총량 구하기
			else
			{
				width = (curX - (wallX - 1)) - 2;

				// 기둥이 서로 붙어있지 않은 경우에만 빗물의 양 계산
				if (0 < width)
				{
					height = min(wallY, curY);
					sum += (width * height) - blocks;
				}
				wallY = curY;
				wallX = curX;
				blocks = 0;
			}
		}
		// 기존 벽보다 짧다면 (나중에 빼줄)바닥 블록 넓이에 더해주기
		else
		{
			blocks += hole[curX];
		}
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 1 <= H, W <= 500
	int H, W;
	cin >> H >> W;
	int rainwater = 0;
	vector<int> Walls(W, 0);
	vector<int> Front, Back;

	int maxY = 0, maxX;
	for (int x = 0; x < W; x++)
	{
		cin >> Walls[x];
		//if (maxY < heights[x]) 처음 풀이
		//{
		//	maxY = heights[x];
		//	maxX = x;
		//}
	}
	// 처음 풀이
	//Front.assign(heights.begin(), heights.begin() + maxX + 1);
	//Back.assign(heights.begin() + maxX, heights.end());
	//reverse(Back.begin(), Back.end());
	//rainwater = CountRainWater(Front) + CountRainWater(Back);

	// 두번째 풀이(스택 활용)
	stack<int> IdxStack;
	int floor, width, height;
	for (int i = 0; i < W; ++i)
	{
		// 스택이 비어있지 않고, 현재 벽이 최근 벽보다 높아지면 실행
		while (!IdxStack.empty() && Walls[IdxStack.top()] < Walls[i])
		{
			floor = IdxStack.top();
			IdxStack.pop();

			if (IdxStack.empty())
				break;

			// 빗물 너비 = 양쪽 벽 사이의 너비 | 빗물 높이 = 양쪽 벽 중 더 낮은 높이 - 바닥 높이
			width = (i - IdxStack.top()) - 1;
			height = min(Walls[i], Walls[IdxStack.top()]) - Walls[floor];
			rainwater += width * height;
		}
		IdxStack.push(i); // 현재 벽의 인덱스 삽입
	}

	cout << rainwater;
	return 0;
}
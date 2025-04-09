#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// ó�� Ǯ��
int CountRainWater(const vector<int>& hole)
{
	int wallY = 0, wallX = 0, blocks = 0, sum = 0;
	int curY, width, height;

	for (int curX = 0; curX < hole.size(); curX++)
	{
		curY = hole[curX];
		// ���� ���̰� ������(�ʱⰪorù��)���� Ŭ ���
		if (wallY <= curY)
		{
			// ù ��
			if (0 == wallY)
			{
				wallY = curY;
				wallX = curX;
			}
			// �ι�° ���̶�� ���� �ѷ� ���ϱ�
			else
			{
				width = (curX - (wallX - 1)) - 2;

				// ����� ���� �پ����� ���� ��쿡�� ������ �� ���
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
		// ���� ������ ª�ٸ� (���߿� ����)�ٴ� ��� ���̿� �����ֱ�
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
		//if (maxY < heights[x]) ó�� Ǯ��
		//{
		//	maxY = heights[x];
		//	maxX = x;
		//}
	}
	// ó�� Ǯ��
	//Front.assign(heights.begin(), heights.begin() + maxX + 1);
	//Back.assign(heights.begin() + maxX, heights.end());
	//reverse(Back.begin(), Back.end());
	//rainwater = CountRainWater(Front) + CountRainWater(Back);

	// �ι�° Ǯ��(���� Ȱ��)
	stack<int> IdxStack;
	int floor, width, height;
	for (int i = 0; i < W; ++i)
	{
		// ������ ������� �ʰ�, ���� ���� �ֱ� ������ �������� ����
		while (!IdxStack.empty() && Walls[IdxStack.top()] < Walls[i])
		{
			floor = IdxStack.top();
			IdxStack.pop();

			if (IdxStack.empty())
				break;

			// ���� �ʺ� = ���� �� ������ �ʺ� | ���� ���� = ���� �� �� �� ���� ���� - �ٴ� ����
			width = (i - IdxStack.top()) - 1;
			height = min(Walls[i], Walls[IdxStack.top()]) - Walls[floor];
			rainwater += width * height;
		}
		IdxStack.push(i); // ���� ���� �ε��� ����
	}

	cout << rainwater;
	return 0;
}
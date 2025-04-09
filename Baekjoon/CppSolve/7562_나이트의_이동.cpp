#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int board[300][300];
int movey[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int movex[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void bfs(pair<int, int>& start, const pair<int, int>& goal, const int& len)
{
	queue<pair<int, int>> q;
	q.push({ start.first, start.second });
	board[start.first][start.second] = 0;

	int cy, cx, ny, nx;
	while (!q.empty())
	{ 
		cy = q.front().first;
		cx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			ny = cy;
			nx = cx;
			ny += movey[i];
			nx += movex[i];

			// 유효범위 이고, 방문한 적 없다면 큐에 삽입
			if (0 <= ny && ny < len && 0 <= nx && nx < len)
			{
				if (-1 == board[ny][nx])
				{
					board[ny][nx] = board[cy][cx] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, l;
	cin >> T;

	pair<int, int> StartPos, GoalPos;
	for (int i = 0; i < T; ++i)
	{
		memset(board, -1, sizeof(board));
		cin >> l;
		cin >> StartPos.first >> StartPos.second;
		cin >> GoalPos.first >> GoalPos.second;

		bfs(StartPos, GoalPos, l);
		cout << board[GoalPos.first][GoalPos.second] << '\n';
	}
	return 0;
}
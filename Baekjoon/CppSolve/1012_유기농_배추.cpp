#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상/하/좌/우 방향
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int x, int y, vector<vector<int>>& field,
	vector<vector<bool>>& visited, int m, int n)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		
		q.pop();

		// 상하좌우 탐색
		for (int i = 0; i < 4; i++)
		{
			int NewX = CurX + dx[i];
			int NewY = CurY + dy[i];

			// 유효 범위 체크
			if (0 <= NewX && m > NewX && 0 <= NewY && n > NewY)
			{
				// 배추가 심어져 있고, 방문한 적 없으면 방문처리
				if (1 == field[NewY][NewX] && !visited[NewY][NewX])
				{
					visited[NewY][NewX] = true;
					//cout << "\nLinked Node -> " << NewY << " , " << NewX;
					q.push({ NewX, NewY });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		// 1 <= M <= 50		: 배추밭 가로길이
		// 1 <= N <= 50 : 배추밭 세로길이
		// 1 <= K <= 2500 : 배추 개수
		int M, N; // (가로, 세로) (열, 행) (X, Y)
		int K;
		cin >> M >> N >> K;
		
		vector<vector<int>> Field(N, vector<int>(M, 0));
		vector<vector<bool>> Visited(N, vector<bool>(M, false));
		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			Field[Y][X] = 1;
		}

		int BugCount = 0;
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; ++x)
			{
				// 배추가 심어져 있고, 방문한 적 없음
				if (1 == Field[y][x] && !Visited[y][x])
				{
					// bfs 수행해서 연결된 배추 방문한 뒤 카운트+1
					//cout << "\n\n[Start Node] : " << y << " , " << x;
					bfs(x, y, Field, Visited, M, N);
					++BugCount;
				}
			}
		}

		cout << '\n' << "답 : " << BugCount << '\n';
	}

	return 0;
}
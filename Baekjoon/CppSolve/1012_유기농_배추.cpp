#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ��/��/��/�� ����
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

		// �����¿� Ž��
		for (int i = 0; i < 4; i++)
		{
			int NewX = CurX + dx[i];
			int NewY = CurY + dy[i];

			// ��ȿ ���� üũ
			if (0 <= NewX && m > NewX && 0 <= NewY && n > NewY)
			{
				// ���߰� �ɾ��� �ְ�, �湮�� �� ������ �湮ó��
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
		// 1 <= M <= 50		: ���߹� ���α���
		// 1 <= N <= 50 : ���߹� ���α���
		// 1 <= K <= 2500 : ���� ����
		int M, N; // (����, ����) (��, ��) (X, Y)
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
				// ���߰� �ɾ��� �ְ�, �湮�� �� ����
				if (1 == Field[y][x] && !Visited[y][x])
				{
					// bfs �����ؼ� ����� ���� �湮�� �� ī��Ʈ+1
					//cout << "\n\n[Start Node] : " << y << " , " << x;
					bfs(x, y, Field, Visited, M, N);
					++BugCount;
				}
			}
		}

		cout << '\n' << "�� : " << BugCount << '\n';
	}

	return 0;
}
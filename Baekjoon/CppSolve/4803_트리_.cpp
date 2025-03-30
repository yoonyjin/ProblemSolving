#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, s, e;
// 특정 노드와 연결된 노드 중 가장 값이 작은 노드를 저장함
vector<int> DisjointSet;

// 원소 x가 속한 부분집합의 루트 노드를 반환
int Find(const int& x)
{
	if (x == DisjointSet[x])
		return x;

	return DisjointSet[x] = Find(DisjointSet[x]);
}

// 원소 x와 y가 속한 각 부분집합의 합집합을 구한다.
// 한 트리의 루트가 다른 트리의 루트를 가리키도록 하여 두 트리를 하나로 병합
void Union(int& x, int& y)
{
	// 루트를 찾아와서 
	x = Find(x);
	y = Find(y);

	// 값이 더 큰 노드의 루트 노드를 작은 값으로 초기화
	if (x < y)
	{
		DisjointSet[y] = x;
	}
	else if (x > y)
	{
		DisjointSet[x] = y;
	}
	else
	{
		// 이미 연결된 간선을 또 입력하는 경우는 없다고 했으니
		// x==y, 루트 노트가 같다면(같은 트리라면) 
		// 사이클이 발생하게 되어 트리가 아닌 그래프가 된다.
		// 따라서 루트 노드를 0으로 초기화해서 트리가 아님을 표현한다.
		// (i == DisjointSet[i] 조건으로 카운팅 안되도록)
		DisjointSet[x] = 0;
		DisjointSet[y] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int CaseNum = 1;
	while (true)
	{
		int treecount = 0;
		cin >> n >> m;
		if (0 == n && 0 == m)
			break;

		DisjointSet.assign(n + 1, 0);

		for (int i = 0; i <= n; i++)
		{
			DisjointSet[i] = i;
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> s >> e;
			Union(s, e);
		}

		for (int i = 1; i <= n; i++)
		{
			if (i == DisjointSet[i])
				++treecount;
		}

		cout << "Case " << CaseNum++ << ": ";
		if (1 < treecount)
			cout << "A forest of " << treecount << " trees.";

		else if (1 == treecount)
			cout << "There is one tree.";

		else
			cout << "No trees.";

		cout << '\n';
	}

	return 0;
}
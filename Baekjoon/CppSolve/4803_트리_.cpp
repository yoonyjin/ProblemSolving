#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, s, e;
// Ư�� ���� ����� ��� �� ���� ���� ���� ��带 ������
vector<int> DisjointSet;

// ���� x�� ���� �κ������� ��Ʈ ��带 ��ȯ
int Find(const int& x)
{
	if (x == DisjointSet[x])
		return x;

	return DisjointSet[x] = Find(DisjointSet[x]);
}

// ���� x�� y�� ���� �� �κ������� �������� ���Ѵ�.
// �� Ʈ���� ��Ʈ�� �ٸ� Ʈ���� ��Ʈ�� ����Ű���� �Ͽ� �� Ʈ���� �ϳ��� ����
void Union(int& x, int& y)
{
	// ��Ʈ�� ã�ƿͼ� 
	x = Find(x);
	y = Find(y);

	// ���� �� ū ����� ��Ʈ ��带 ���� ������ �ʱ�ȭ
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
		// �̹� ����� ������ �� �Է��ϴ� ���� ���ٰ� ������
		// x==y, ��Ʈ ��Ʈ�� ���ٸ�(���� Ʈ�����) 
		// ����Ŭ�� �߻��ϰ� �Ǿ� Ʈ���� �ƴ� �׷����� �ȴ�.
		// ���� ��Ʈ ��带 0���� �ʱ�ȭ�ؼ� Ʈ���� �ƴ��� ǥ���Ѵ�.
		// (i == DisjointSet[i] �������� ī���� �ȵǵ���)
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
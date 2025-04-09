#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 1 <= N <= 100��
	// 1 <= M <= 20��
	int N, M;
	cin >> N >> M;
	vector<int> Trees(N, 0);
	int answer = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> Trees[i];
	}

	int left = 0;
	int right = *max_element(Trees.begin(), Trees.end());
	int mid = 0;
	long long sum;

	while (left <= right)
	{
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (mid < Trees[i])
				sum += Trees[i] - mid;
		}

		// ��Ȯ�� M�� ���� mid�� �������� ���� �� �����Ƿ�
		// sum�� M���� ū mid �߿��� �ִ��� ���ؾ� ��
		if (sum >= M)
		{
			// �ϴ� answer �ʱ�ȭ�ϰ� �� ū mid �õ��ϱ�
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;
	return 0;
}
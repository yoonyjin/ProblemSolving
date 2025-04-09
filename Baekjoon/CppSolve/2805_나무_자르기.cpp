#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 1 <= N <= 100만
	// 1 <= M <= 20억
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

		// 정확히 M과 같은 mid가 존재하지 않을 수 있으므로
		// sum이 M보다 큰 mid 중에서 최댓값을 구해야 함
		if (sum >= M)
		{
			// 일단 answer 초기화하고 더 큰 mid 시도하기
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;
	return 0;
}
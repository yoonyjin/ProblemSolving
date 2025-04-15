#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int R = 0;
const int G = 1;
const int B = 2;
// 백트래킹 : O(3^N) 으로 N=1000일 경우(최악) 엄청나게 오래 걸림
// DP : O(N)
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<vector<int>> cost(N, vector<int>(3));
	vector<vector<int>> dp(N, vector<int>(3, 0));

	for (int i = 0; i < N; ++i)
	{
		cin >> cost[i][R] >> cost[i][G] >> cost[i][B];
	}

	dp[0][R] = cost[0][R];
	dp[0][G] = cost[0][G];
	dp[0][B] = cost[0][B];

	for (int i = 1; i < N; ++i)
	{
		dp[i][R] = cost[i][R] + min(dp[i - 1][G], dp[i - 1][B]);
		dp[i][G] = cost[i][G] + min(dp[i - 1][R], dp[i - 1][B]);
		dp[i][B] = cost[i][B] + min(dp[i - 1][R], dp[i - 1][G]);
	}

	int answer = min({dp[dp.size() - 1][R], dp[dp.size() - 1][G], dp[dp.size() - 1][B]});
	cout << answer;
	return 0;
}
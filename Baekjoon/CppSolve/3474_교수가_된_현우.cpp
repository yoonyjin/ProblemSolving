#include <iostream>

using namespace std;

// 끝자리가 0이려면 10이 필요하고,
// 10을 만들려면 2와 5가 필요하다.
// 0의 개수 == Min(2개수, 5개수)
// -> 2의배수는 짝수마다 들어있어 많으므로
// 5의배수의 최대 개수만 세자

// 3! == 6 (0개)
// 5! == 120 (1개)
// 9! == 362,880 (1개)
// 10! == 3,628,800 (2개)
// 12! == 479,001,600 (2개)
// 15! == 1,307,674,368,000 (3개)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	
	// 시간제한 : 1초
	// 문제 : N!의 오른쪽 끝에 있는 0의 개수 출력
	while (T--)
	{
		// 1 <= N <= 1,000,000,000 (10억, 10^9)
		long long N = 0;
		long long answer = 0;
		cin >> N;

		// 5, 25, 125.. 순으로 나눈 값 더함
		for (long long i = 5; i <= N; i *= 5)
		{
			answer += (N / i);
		}
		cout << answer << '\n';
	}
	return 0;

}
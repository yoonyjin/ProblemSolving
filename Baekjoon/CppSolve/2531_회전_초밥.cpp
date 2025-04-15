#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, d, k, c; // 접시수, 초밥가지수, 연속접시수, 쿠폰번호
	cin >> N >> d >> k >> c;
	vector<int> Sushi(N, 0);		// 벨트 위의 초밥
	vector<int> Count(d + 1, 0);	// 초밥 종류별 개수

	for (int i = 0; i < N; ++i)
	{
		cin >> Sushi[i];
	}

	// 첫 윈도우
	int SushiNum = 0, MaxType = 0;
	for (int i = 0; i < k; ++i)
	{
		if (0 == Count[Sushi[i]]++)
			SushiNum++;
	}
	MaxType = SushiNum + (0 == Count[c] ? 1 : 0);

	int next, result;
	for (int i = 1; i < N; ++i)
	{
		// 이전 초밥 지우기
		if (0 == --Count[Sushi[i - 1]])
			SushiNum--;

		// 다음 초밥 추가하기
		next = Sushi[(i + k - 1) % N];
		if (0 == Count[next]++)
			SushiNum++;

		result = SushiNum + (Count[c] == 0 ? 1 : 0);
		MaxType = max(MaxType, result);
	}

	cout << MaxType;
	return 0;
}
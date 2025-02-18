#include <iostream>
#include <vector>

using namespace std;
int main()
{
	// 전구 : N개
	// 전구상태 : 1(ON), 0(OFF)

	// N : 전구개수, M : 명렁어개수
	// 1 <= N,M <= 4000
	int N = 0, M = 0;
	cin >> N >> M;
	vector<bool> Lamps;

	bool Status = 0;
	// N개의 전구의 상태 입력
	for (int i = 0; i < N; i++)
	{
		cin >> Status;
		Lamps.push_back(Status);
	}

	int Number = 0;
	int Second = 0, Third = 0;
	// M번 명령어 입력
	for (int i = 0; i < M; i++)
	{
		cin >> Number >> Second >> Third;

		// 명령어)
		// 1번째 [i x] : i번째 전구를 x로 변경 
		if (1 == Number)
		{
			Lamps[Second-1] = Third;
		}
		else
		{
			for (int j = Second-1; j <= Third-1; j++)
			{
				// 2번째 [l r] : l~r 사이 전구 상태 반전
				if (2 == Number)
					Lamps[j] = !Lamps[j];

				// 3번째 [l~r] : l~r 사이 전구 OFF
				else if (3 == Number)
					Lamps[j] = 0;
				
				// 4번째 [l~r] : l~r 사이 전구 ON
				else if (4 == Number)
					Lamps[j] = 1;
			}
		}
	}

	for (bool b : Lamps)
	{
		cout << b << ' ';
	}

	return 0;
}
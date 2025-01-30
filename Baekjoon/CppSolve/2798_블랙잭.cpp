#include <iostream>
#include <set>

using namespace std;
int main()
{
	int* CardsArr;

	int Sum = 0;
	int N = 0, M = 0;
	int CardNum = 0;
	int AllCardSum = 0;

	cin >> N >> M;

	CardsArr = new int[N];

	// 카드 : 양의정수
	// N개의 카드의 숫자공개, M : MaxSum, 10 <= M <= 300,000
	// 3 <= N <= 100
	for (int i = 0; i < N; i++)
	{
		cin >> CardNum;
		CardsArr[i] = CardNum;
		AllCardSum += CardNum;
	}

	// 삭제) 이거 빼도 성능에 큰 차이 없다
	// 모든 카드의 숫자를 합해도 M보다 작을 수 있으므로
	// 최대 합계값을 업데이트해줌
	//if (AllCardSum < M)
	//	M = AllCardSum;

	int MedSum = 0;
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				MedSum = CardsArr[i] + CardsArr[j] + CardsArr[k];

				if (MedSum > Sum && MedSum <= M)
					Sum = MedSum;
			}
		}
	}

	cout << Sum;
	//cout << "결과값: " << Sum << "\n";
	delete[]CardsArr;
	return 0;
}

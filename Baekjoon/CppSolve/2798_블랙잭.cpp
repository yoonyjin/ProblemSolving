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

	// ī�� : ��������
	// N���� ī���� ���ڰ���, M : MaxSum, 10 <= M <= 300,000
	// 3 <= N <= 100
	for (int i = 0; i < N; i++)
	{
		cin >> CardNum;
		CardsArr[i] = CardNum;
		AllCardSum += CardNum;
	}

	// ����) �̰� ���� ���ɿ� ū ���� ����
	// ��� ī���� ���ڸ� ���ص� M���� ���� �� �����Ƿ�
	// �ִ� �հ谪�� ������Ʈ����
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
	//cout << "�����: " << Sum << "\n";
	delete[]CardsArr;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	// ���� : N��
	// �������� : 1(ON), 0(OFF)

	// N : ��������, M : �����
	// 1 <= N,M <= 4000
	int N = 0, M = 0;
	cin >> N >> M;
	vector<bool> Lamps;

	bool Status = 0;
	// N���� ������ ���� �Է�
	for (int i = 0; i < N; i++)
	{
		cin >> Status;
		Lamps.push_back(Status);
	}

	int Number = 0;
	int Second = 0, Third = 0;
	// M�� ��ɾ� �Է�
	for (int i = 0; i < M; i++)
	{
		cin >> Number >> Second >> Third;

		// ��ɾ�)
		// 1��° [i x] : i��° ������ x�� ���� 
		if (1 == Number)
		{
			Lamps[Second-1] = Third;
		}
		else
		{
			for (int j = Second-1; j <= Third-1; j++)
			{
				// 2��° [l r] : l~r ���� ���� ���� ����
				if (2 == Number)
					Lamps[j] = !Lamps[j];

				// 3��° [l~r] : l~r ���� ���� OFF
				else if (3 == Number)
					Lamps[j] = 0;
				
				// 4��° [l~r] : l~r ���� ���� ON
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
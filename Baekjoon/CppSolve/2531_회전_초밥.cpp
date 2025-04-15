#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, d, k, c; // ���ü�, �ʹ䰡����, �������ü�, ������ȣ
	cin >> N >> d >> k >> c;
	vector<int> Sushi(N, 0);		// ��Ʈ ���� �ʹ�
	vector<int> Count(d + 1, 0);	// �ʹ� ������ ����

	for (int i = 0; i < N; ++i)
	{
		cin >> Sushi[i];
	}

	// ù ������
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
		// ���� �ʹ� �����
		if (0 == --Count[Sushi[i - 1]])
			SushiNum--;

		// ���� �ʹ� �߰��ϱ�
		next = Sushi[(i + k - 1) % N];
		if (0 == Count[next]++)
			SushiNum++;

		result = SushiNum + (Count[c] == 0 ? 1 : 0);
		MaxType = max(MaxType, result);
	}

	cout << MaxType;
	return 0;
}
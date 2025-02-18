#include <iostream>
#include <vector>

using namespace std;

// �Է� : N (���� Ƚ��(�ݺ�Ƚ��)), 1 <= N <= 100
// ��� : �Ұ� ���� �ǳʰ�(������ �ٲ�) Ƚ��

int main()
{
	vector<int> Cow(11, -1);
	vector<int> CowCount(11, 0);

	int TotalCount = 0;
	int N = 0;
	cin >> N;

	// 1 <= CowNum <= 10
	// CowDir : 0 or 1
	int CowNum, CowDir;
	for (int i = 0; i < N; i++)
	{
		cin >> CowNum >> CowDir;
		
		// ó�� �ǳʴ� �� �ƴϰ�,
		// ������ �ٲ���ٸ�, ī��Ʈ 1 ����
		if (Cow[CowNum] != -1
			&& Cow[CowNum] != CowDir)
			TotalCount++;
		
		Cow[CowNum] = CowDir;
	}
	
	cout << TotalCount << endl;

	return 0;
}
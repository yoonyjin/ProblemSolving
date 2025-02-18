#include <iostream>
#include <vector>

using namespace std;

// 입력 : N (관찰 횟수(반복횟수)), 1 <= N <= 100
// 출력 : 소가 길을 건너간(방향을 바꾼) 횟수

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
		
		// 처음 건너는 게 아니고,
		// 방향이 바뀌었다면, 카운트 1 증가
		if (Cow[CowNum] != -1
			&& Cow[CowNum] != CowDir)
			TotalCount++;
		
		Cow[CowNum] = CowDir;
	}
	
	cout << TotalCount << endl;

	return 0;
}
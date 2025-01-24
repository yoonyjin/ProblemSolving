#include <iostream>
#include <vector>
#include <set>

const unsigned int MaxSum = 21;

using namespace std;
int main()
{
	set<unsigned int> CardSet;
	//vector<unsigned int> CardVec = {};

	unsigned int Sum = 0;
	unsigned int N = 0, M = 0;
	unsigned int CardNum = 0;

	cin >> N >> M;

	// 카드 : 양의정수
	// N개의 카드의 숫자공개

	for (int i = 0; i < N; i++)
	{
		cin >> CardNum;
		CardSet.insert(CardNum);
	}


	for (int num : CardSet)
	{
		cout << num << ", ";
	}

	// 첫카드, 두번째카드, 세번째카드 각각 가리키는 Iterator 필요
	// 각 Iterator 값을 더한 sum

	cout << "\n";

	return 0;
}
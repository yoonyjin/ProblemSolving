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

	// ī�� : ��������
	// N���� ī���� ���ڰ���

	for (int i = 0; i < N; i++)
	{
		cin >> CardNum;
		CardSet.insert(CardNum);
	}


	for (int num : CardSet)
	{
		cout << num << ", ";
	}

	// ùī��, �ι�°ī��, ����°ī�� ���� ����Ű�� Iterator �ʿ�
	// �� Iterator ���� ���� sum

	cout << "\n";

	return 0;
}
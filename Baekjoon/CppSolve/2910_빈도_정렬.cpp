#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 1 <= N <= 1000, 1 <= C <= 10��
	int N = 0, C = 0;
	cin >> N >> C;
	unordered_map<int, int> NumMap;
	vector<int> OrderVec;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		
		if (0 == NumMap[num])
			OrderVec.push_back(num);

		// map�� [] �����ڿ� ������ ���� ���� ��,
		// ã�� key�� �������� ������ �ش� key�� ���Ҹ� ���� ���� value�� 0���� �ʱ�ȭ��
		NumMap[num]++;
	}
	
	// map�� sort�� �Ұ����ϱ� ������ vector�� �����ؼ� map�� ������ ��ü �������ش�.
	vector<pair<int, int>> vec(NumMap.begin(), NumMap.end());
	// stable_sort (���� ����) : ������ ������ ����Ǵ� ����
	stable_sort(OrderVec.begin(), OrderVec.end(),
		// key�� �ƴ� value ���� ������ ���� �����ؾ� �ؼ� �����Լ� ����
		// 1��) ���� ������θ� ���ĵƴ� ���� -> 2��) ���� ī��Ʈ�� ������ ����
		// ���� �Լ��� ĸ�� ���� &�� ������ : �����Լ� �ܺ��� ��� ������ ���۷����� ������
		[&](int a, int b)
		{
			return NumMap[a] > NumMap[b]; });
	
	for (const int& n : OrderVec)
	{
		for (int i = 0; i < NumMap[n]; i++)
			cout << n << ' ';
	}

	return 0;
}
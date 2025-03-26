#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 1 <= N <= 1000, 1 <= C <= 10억
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

		// map의 [] 연산자에 접근해 값을 넣을 때,
		// 찾는 key가 존재하지 않으면 해당 key로 원소를 새로 만들어서 value를 0으로 초기화함
		NumMap[num]++;
	}
	
	// map은 sort가 불가능하기 때문에 vector를 생성해서 map의 값들을 전체 복사해준다.
	vector<pair<int, int>> vec(NumMap.begin(), NumMap.end());
	// stable_sort (안정 정렬) : 삽입한 순서가 보장되는 정렬
	stable_sort(OrderVec.begin(), OrderVec.end(),
		// key가 아닌 value 기준 정렬은 직접 구현해야 해서 람다함수 정의
		// 1차) 삽입 순서대로만 정렬됐던 벡터 -> 2차) 많이 카운트된 순으로 정렬
		// 람다 함수의 캡쳐 내에 &를 넣으면 : 람다함수 외부의 모든 변수를 레퍼런스로 가져옴
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
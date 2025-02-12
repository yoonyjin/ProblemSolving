#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm> // sort

// 입력1 : N, M (듣도 못한 사람/보도 못한 사람 수)
// -> 범위가 최대 500,000으로 이전 문제들보다 커졌음
// 입력2 : N개의 사람이름, M개의 사람이름 
// 이름 : 공백X, 소문자만, 크기 20이하
// 출력 : 듣지도/보지도 못한사람 이름 (중복되는 이름)
// -> 사전순 (알파벳순)

// std::string은 == 연산자 지원한다

/* 처음에 이름들은 vectotr<string>, 정답은 set에 집어넣고
	N만큼, M만큼, N*M만큼 다 반복시켰다가 시간초과 뜸 */
/* N(==M) 범위 50만이므로 N*M = 2500억 (백준 C++기준 1억번:1초, 즉 2500초 ;;) */
/* -> unordered_set 으로 변경 */

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	
	string name;
	unordered_set<string> NM_Names = {};
	vector<string> Twice_Names = {};
	/* STL
	* set : 레드블랙트리로 구현됨. 정렬O, 중복X, 탐색속도 O(logN)
	* unordered_set : 해시테이블로 구현됨, 정렬X, 중복X, 삽입/삭제/탐색속도 O(1) */

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		NM_Names.insert(name);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> name;
		if (NM_Names.find(name) != NM_Names.end())
		{
			Twice_Names.push_back(name);
		}
	}

	sort(Twice_Names.begin(), Twice_Names.end());

	cout << Twice_Names.size() << '\n';
	for (const string& str : Twice_Names)
	{
		cout << str << '\n';
	}

	return 0;
}
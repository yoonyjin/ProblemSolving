#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm> // sort

// �Է�1 : N, M (�赵 ���� ���/���� ���� ��� ��)
// -> ������ �ִ� 500,000���� ���� �����麸�� Ŀ����
// �Է�2 : N���� ����̸�, M���� ����̸� 
// �̸� : ����X, �ҹ��ڸ�, ũ�� 20����
// ��� : ������/������ ���ѻ�� �̸� (�ߺ��Ǵ� �̸�)
// -> ������ (���ĺ���)

// std::string�� == ������ �����Ѵ�

/* ó���� �̸����� vectotr<string>, ������ set�� ����ְ�
	N��ŭ, M��ŭ, N*M��ŭ �� �ݺ����״ٰ� �ð��ʰ� �� */
/* N(==M) ���� 50���̹Ƿ� N*M = 2500�� (���� C++���� 1���:1��, �� 2500�� ;;) */
/* -> unordered_set ���� ���� */

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
	* set : �����Ʈ���� ������. ����O, �ߺ�X, Ž���ӵ� O(logN)
	* unordered_set : �ؽ����̺�� ������, ����X, �ߺ�X, ����/����/Ž���ӵ� O(1) */

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
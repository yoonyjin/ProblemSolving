#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
// 250211 ������
// �Է� : �׽�Ʈ���̽� �� T (1 <= T <= 20)
// ��� : �� �׽�Ʈ���̽��� ���
// ? : �ҹ��ڸ��ΰ��� �빮�� �����ΰ��� �𸣰���

// ���ĺ� a ~ z : �ƽ�Ű�ڵ� 97 ~ 122
//using namespace std;
using std::cin;
using std::cout;
using std::string;

int main()
{
	int T;
	string Problem[20];
	cin >> T;
	// ���๮�� ����
	// �̰� �� �ߴ��� �׽�Ʈ���̽��� ���ڿ� �Է¹����� 1ȸ�� ���๮�ڷ� ó���ع���
	cin.ignore();
	
	for (int i = 0; i < T; i++)
	{
		string Problem;
		getline(cin, Problem);
		int alphabets[26] = { 0 };
		int MaxCount = 0;
		char MaxChar = '?';
		bool IsUnique = true;

		for (char C : Problem)
		{
			if (isalpha(C))
			{
				// �빮�ڶ�� �ҹ��ڷ� ��ȯ �� �ε��� �����
				int idx = tolower(C) - 'a';
				if (0 <= idx && idx < 26)
				{
					alphabets[idx]++;

					if (alphabets[idx] > MaxCount)
					{
						MaxCount = alphabets[idx];
						MaxChar = 'a' + idx;
						IsUnique = true;
					}
					else if (alphabets[idx] == MaxCount)
					{
						IsUnique = false;
					}
				}
			}
		}

		if (IsUnique)
			cout << MaxChar;
		else
			cout << "?";
		cout << '\n';
	}
	return 0;
}
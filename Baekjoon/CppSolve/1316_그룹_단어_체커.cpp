#include <iostream>
using namespace std;

int main(void) {
	int N;
	string word;
	int cnt = 0;
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> word;
		bool isGroup = true;
		for (int j = 0; j < word.length(); j++)
		{
			//뒤에 같은 알파벳 있는지 확인하기
			for (int k = 0; k < j; k++)
			{
				//앞뒤 알파벳이 다르고, 앞 알파벳이 뒤쪽에 또 있으면 그룹 단어가 아님
				if (word[j] != word[j - 1] && word[j] == word[k])
					isGroup = false;
				break;
			}
		}
		if (isGroup)
			cnt++;
	}
	cout << cnt;
}
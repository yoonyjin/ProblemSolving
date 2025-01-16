#include <iostream>
#include <string>
#include <stack>
//#include <sstream>
//#include <vector>

using namespace std;

int main()
{
	// 250116 Ç®ÀÌ1
	int count = 0;
	string InputWord;

	stack<char> strstack;

	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; i++)
	{
		getline(cin, InputWord);
		InputWord += ' ';

		for (int i = 0; i < InputWord.size(); i++)
		{
			if (InputWord[i] == ' ')
			{
				while (!strstack.empty())
				{
					cout << strstack.top();
					strstack.pop();
				}
				cout << " ";
			}
			else
			{
				strstack.push(InputWord[i]);
			}
		}
		cout << "\n";
	}

	return 0;
}
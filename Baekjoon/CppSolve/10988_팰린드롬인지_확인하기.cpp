#include <iostream>

using namespace std;

int main()
{
	bool IsPalindrome = false;
	string Input = "";
	cin >> Input;
	int count = ((int)Input.length()) / 2;

	std::string::iterator FrontIter = Input.begin();
	std::string::iterator BackIter = Input.end() - 1;

	while (count)
	{
		if (*FrontIter == *BackIter)
		{
			FrontIter++;
			BackIter--;
		}
		else
		{
			IsPalindrome = false;
			cout << IsPalindrome;
			return 0;
		}

		count--;
	}

	IsPalindrome = true;
	cout << IsPalindrome;
	return 0;
}
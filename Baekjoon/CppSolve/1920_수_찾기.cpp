#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// 이분탐색 문제 (정렬되어야 함)
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N; // 1 <= N <= 100,000
	cin >> N;

	//ifstream file("Test1920.txt");
	//file >> N;
	
	vector<int> Numbers(N);
	for (int i = 0; i < N; ++i)
	{
		//file >> Numbers[i];
		cin >> Numbers[i];
	}

	// 오름차순 정렬
	sort(Numbers.begin(), Numbers.end());

	int M;
	//file >> M;
	cin >> M;
	vector<int> Targets(M);
	for (int i = 0; i < M; ++i)
	{
		//file >> Targets[i];
		cin >> Targets[i];
	}

	//ofstream outfile("output.txt");
	for (int i = 0; i < Targets.size(); ++i)
	{
		int Left = 0;
		int Right = Numbers.size() - 1;
		int Mid = 0;
		bool IsFound = false;

		while (Left <= Right)
		{
			Mid = (Left + Right) / 2;
			if (Targets[i] == Numbers[Mid])
			{
				IsFound = true;
				break;
			}
			else if (Targets[i] < Numbers[Mid])
				Right = Mid - 1;

			else if (Targets[i] > Numbers[Mid])
				Left = Mid + 1;
		}
		//outfile << IsFound ? 1 : 0;
		//outfile << '\n';
		cout << IsFound ? 1 : 0;
		cout << '\n';
	}
	return 0;
}
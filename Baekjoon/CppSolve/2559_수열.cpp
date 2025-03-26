#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	//ifstream file("Test2559.txt");
	//file >> N >> K;

	cin >> N >> K;
	
	vector<int> NumVec(N);
	int WindowSum = 0;
	int MaxSum = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> NumVec[i];
	}

	//for (int i = 0; i < N; i++)
	//{
	//	file >> NumVec[i];
	//}

	for (int i = 0; i < K; ++i)
	{
		WindowSum += NumVec[i];
	}

	MaxSum = WindowSum;
	for (int i = K; i < N; ++i)
	{
		WindowSum = WindowSum - NumVec[i - K] + NumVec[i];
		MaxSum = max(MaxSum, WindowSum);
	}

	cout << MaxSum;
	return 0;
}
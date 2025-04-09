#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> Meeting(N);
	int laststart, lastend;
	int answer = 1;

	for (int i = 0; i < N; ++i)
	{
		cin >> Meeting[i].first >> Meeting[i].second;
	}

	sort(Meeting.begin(), Meeting.end());
	
	laststart = Meeting[N-1].first;
	lastend = Meeting[N-1].second;
	for (int i = N-2; i >= 0; --i)
	{
		if (Meeting[i].second <= laststart)
		{
			laststart = Meeting[i].first;
			lastend = Meeting[i].second;
			++answer;
		}
	}

	cout << answer;
	return 0;
}
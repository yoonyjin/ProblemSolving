#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// https://www.acmicpc.net/problem/1747
using namespace std;

bool CheckPalin(int prime)
{
    string Rev = to_string(prime);
    reverse(Rev.begin(), Rev.end());

    if (prime == stoi(Rev))
        return true;
    return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// N보다 크거나 같고, 소수이면서, 팰린드롬인 수
	// 중에서 가장 작은 수 구하기
	int N;
	cin >> N;

    const int LIMIT = 1100000;
    vector<bool> PrimeVec(LIMIT+1, true);
    PrimeVec[0] = PrimeVec[1] = false;

    // 에라토스테네스의 체 알고리즘으로 소수 전처리
    for (long long Prime = 2; Prime * Prime <= LIMIT; Prime++)
    {
        // 현재 숫자가 소수라면
        if (PrimeVec[Prime])
        {
            // Prime의 배수를 false로 변경
            for (long long j = Prime * 2; j <= LIMIT; j += Prime)
            {
                PrimeVec[j] = false;
            }
        }
    }

    int PalNum = 0;
    for (int i = N; i <= LIMIT; i++)
    {
        if (PrimeVec[i] && CheckPalin(i))
        {
            PalNum = i;
            break;
        }
    }

    cout << PalNum;
	return 0;
}
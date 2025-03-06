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

	// N���� ũ�ų� ����, �Ҽ��̸鼭, �Ӹ������ ��
	// �߿��� ���� ���� �� ���ϱ�
	int N;
	cin >> N;

    const int LIMIT = 1100000;
    vector<bool> PrimeVec(LIMIT+1, true);
    PrimeVec[0] = PrimeVec[1] = false;

    // �����佺�׳׽��� ü �˰������� �Ҽ� ��ó��
    for (long long Prime = 2; Prime * Prime <= LIMIT; Prime++)
    {
        // ���� ���ڰ� �Ҽ����
        if (PrimeVec[Prime])
        {
            // Prime�� ����� false�� ����
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
#include <string>

using namespace std;

int solution(int num) {
    long long n = num;
    int answer = 0;
    if (0 == n)
    {
        return 0;
    }

    for (int i = 0; i < 500; i++)
    {
        if (1 == n)
        {
            return answer;
        }
        n = (0 == n % 2) ? n / 2 : 3 * n + 1;
        answer++;
    }
    return -1;
}
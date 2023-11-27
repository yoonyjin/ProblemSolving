#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int remain;

    // n의 각 자릿수의 합 구하기
    while (n >= 10)
    {
        remain = n % 10;
        answer += remain;
        n /= 10;
    }
    answer += n;
    return answer;
}
#include <string>

using namespace std;

int solution(int n) {
    // 3 <= n 이므로 2부터 나누기 시작한다
    for (int x = 2; x < n; ++x)
    {
        if (1 == n % x)
        {
            return x;
        }
    }
}
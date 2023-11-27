#include <vector>

using namespace std;

int solution(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++)
    {
        // i가 n의 약수인 경우, sum에 i를 더한다
        if (0 == n % i)
        {
            sum += i;
         // i가 n의 제곱근이 아닌 경우, sum에 n/i 값(약수)을 더한다.
            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }
    return sum;
}
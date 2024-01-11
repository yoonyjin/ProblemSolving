#include <string>
#include <vector>

using namespace std;

    // 유클리드 호제법
    // 큰 수를 작은 수로 나눈다.
    // 나누는 수를 나머지 값으로 계속 나누다 나머지가 0이 되면
    // 그 때 나누는 수가 최대공약수가 된다.

vector<int> solution(int n, int m) {
    if (n == m) return { n, n };
    int big = n, small = m, mod;
    if (big < small) swap(big, small);
    while (0 != big % small)
    {
        mod = big % small;
        big = small;
        small = mod;
    }
    return { small, n * m / small };

}
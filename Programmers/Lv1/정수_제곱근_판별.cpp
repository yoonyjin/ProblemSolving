#include <string>
#include <cmath>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long x = 0;
    x = sqrt(n);
    if (n == x * x)
    {
        return (x + 1) * (x + 1);
    }
    else
    {
        return -1;
    }
}
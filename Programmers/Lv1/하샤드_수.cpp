#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int temp = x, sum = 0;

    while (temp > 0)
    {
        sum += temp % 10;
        temp /= 10;
    }
    return 0 == x % sum ? true : false;
}
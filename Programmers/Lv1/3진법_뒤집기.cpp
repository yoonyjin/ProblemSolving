#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int mod, ten = 0;
    vector<int> three;

    while (0 < n)
    {
        mod = n % 3;
        n /= 3;
        three.push_back(mod);
    }

    for (int i = 0; i < three.size(); i++)
    {
        ten += (pow(3, three.size() - i - 1) * (three[i]));
    }
    return ten;
}
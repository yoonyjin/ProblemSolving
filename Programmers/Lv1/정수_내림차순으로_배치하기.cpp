#include <string>
#include <algorithm>

using namespace std;


long long newsolution(long long n) {
    string tmp = to_string(n);
    sort(tmp.begin(), tmp.end(), greater<>());
    return stoull(tmp);
}
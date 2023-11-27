#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int minus = 1;
    if ('-' == s[0])
    {
        minus *= -1;
        s.erase(s.begin());
    }
    else if ('+' == s[0])
    {
        s.erase(s.begin()); 
    }

    return stoi(s) * minus;
}
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int pNum = 0, yNum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ('p' == s[i] || 'P' == s[i])
        {
            pNum++;
        }
        else if ('y' == s[i] || 'Y' == s[i])
        {
            yNum++;
        }
    }

    if (pNum == yNum || 0 == pNum && 0 == yNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}
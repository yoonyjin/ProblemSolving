#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (' ' == s[i])
        {
            answer += ' ';
            continue;
        }
        if (90 < s[i] + n && s[i] + n < 97)
        {
            answer += (64 + (s[i] + n - 90));
            continue;
        }
        if (122 < s[i] + n)
        {
            answer += (96 + (s[i] + n - 122));
            continue;
        }
        answer += (s[i] + n);
    }
    return answer;
}
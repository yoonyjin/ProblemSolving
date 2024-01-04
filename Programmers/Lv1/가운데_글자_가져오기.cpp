#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    // 홀수
    if (1 == s.size()%2)
    {
        answer = s[s.size() / 2];
    }
    // 짝수
    else 
    {
        answer = s.substr(s.size()/2-1, 2);
    }
    return answer;
}
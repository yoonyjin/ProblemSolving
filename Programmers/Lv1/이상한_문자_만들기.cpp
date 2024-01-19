#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int idx = 0;

    for (int i = 0; i < s.length(); i++)
    {
        // 공백 문자가 나오면 각 단어의 인덱스 초기화
        if (' ' == s[i])
        {
            idx = 0;
            continue;
        }
        // 인덱스가 0,짝수 : 대문자 , 홀수 : 소문자 변환
        s[i] = (0 == idx % 2) ? toupper(s[i]) : tolower(s[i]);
        idx++;
    }
    return s;
}
#include <string>
#include <vector>
// isdigit() 사용
#include <cctype>

using namespace std;

bool solution(string s) {
    // 아스키코드
    // 숫자 0~9 : 48~57
    // A~Z : 65~90, a~z : 97 ~ 122
    
    if (4 == s.length() || 6 == s.length())
    {
        for (int i = 0; i < s.length(); i++)
        {
            // 처음 풀이
            if (48 > s[i] || 57 < s[i])
            {
                return false;
            }
            // isdigit() 사용
           /* if (false == isdigit(s[i]))
            {
                return false;
            }*/
        }
        return true;
    }
    return false;

}
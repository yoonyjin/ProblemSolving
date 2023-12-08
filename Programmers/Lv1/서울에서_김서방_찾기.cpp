#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    //string answerKim = "Kim";
    string answer = "";
    for (int i = 0; i < seoul.size(); i++)
    {
        // 다시 풂
        if ("Kim" == seoul[i])
        {
            answer = "김서방은 " + to_string(i) + "에 있다";
            return answer;
        }
        // 처음 풀이
        //for (int j = 0; j <= 3; j++)
        //{
        //    if (answerKim[j] != (seoul[i])[j])
        //        break;
        //    if (3 == j)
        //    {
        //        answer = "김서방은 " + to_string(i) + "에 있다";
        //        return answer;
        //    }
        //}
    }
}  
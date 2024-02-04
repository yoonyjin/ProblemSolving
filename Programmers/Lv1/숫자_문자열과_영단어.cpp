#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int length = 0;
    vector<string> v;
    string sAnswer;

    for (int i = 0; i < s.size(); i+=length)
    {
        if (isdigit(s[i])) {
            sAnswer += s[i];
            length = 1;
            continue;
        }

        else if ('z' == s[i])
        {
            sAnswer += '0';
            length = 1;
            //i += 4;
        }
        else if ('o' == s[i])
        {
            sAnswer += '1';
            length = 3;
            //i += 2;
        }
        else if ('t' == s[i] && 'w' == s[i + 1])
        {
            sAnswer += '2';
            i += 3;
        }
        else if ('t' == s[i] && 'h' == s[i + 1])
        {
            sAnswer += '3';
            i += 5;
        }
        else if ('f' == s[i] && 'o' == s[i + 1])
        {
            sAnswer += '4';
            length = 4;
            //i += 4;
        }
        else if ('f' == s[i] && 'i' == s[i + 1])
        {
            sAnswer += '5';
            i += 4;
        }
        else if ('s' == s[i] && 'i' == s[i + 1])
        {
            sAnswer += '6';
            i += 3;
        }
        else if ('s' == s[i] && 'e' == s[i + 1])
        {
            sAnswer += '7';
            length = 5;
            //i += 5;
        }
        else if ('e' == s[i])
        {
            sAnswer += '8';
            length = 5;
            //i += 5;
        }
        else if ('n' == s[i])
        {
            sAnswer += '9';
            i += 4;
        }
    }
        answer = stoi(sAnswer);
        return answer;
}

void main() {
    solution("one4seveneight");
}
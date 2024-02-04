#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string sAnswer;
    string::iterator iter = s.begin(); 
    while(iter != s.end())
    {
        if (!isdigit(*iter)) {
            switch (*iter) {
            case 'z': // zero
                sAnswer += '0';
                break;
            case 'o': // one
                sAnswer += '1';
                break;
            case 't':
                if ('w' == *(iter + 1)) // two
                    sAnswer += '2';
                else // three
                    sAnswer += '3';
                break;
            case 'f':
                if ('o' == *(iter + 1)) // four
                    sAnswer += '4';
                else // five
                    sAnswer += '5';
                break;
            case 's':
                if ('i' == *(iter + 1)) // six
                    sAnswer += '6';
                else // seven
                    sAnswer += '7';
                break;
            case 'e': // eight
                sAnswer += '8';
                break;
            case 'n': // nine
                sAnswer += '9';
                break;
            } // switch end
        }
        else { // digit
            sAnswer += *iter;
            s.erase(s.begin(), s.begin()+1);
            continue;
        }
        if ('1' == sAnswer.back() || '2' == sAnswer.back() || '6' == sAnswer.back())
            s.erase(s.begin(), s.begin()+3);
        else if ('0' == sAnswer.back() || '4' == sAnswer.back() || '9' == sAnswer.back())
            s.erase(s.begin(), s.begin()+4);
        else if ('3' == sAnswer.back() || '5' == sAnswer.back() || '7' == sAnswer.back() || '8' == sAnswer.back())
            s.erase(s.begin(), s.begin()+5);
    }
    return stoi(sAnswer);
}

void main() {
    solution("123");
}
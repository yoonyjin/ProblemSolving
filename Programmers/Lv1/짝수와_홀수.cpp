#include <string>

using namespace std;

string solution(int num) {
    if (0 == num % 2)
    {
        return "Even";
    }
    else
    {
        return "Odd";
    }
}
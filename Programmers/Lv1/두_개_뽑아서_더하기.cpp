#include <iostream>

using namespace std;

void solution(string str) {
    string answer = "";
    char Alpha;
    for (int i = 0; i < str.size(); i++)
    {
        Alpha = str[i] < 68 ? str[i] - 3 + 26 : str[i] - 3;
        answer += Alpha;
    }
    cout << answer;
}

int main() {
    string ST = "";
    cin >> ST;
    solution(ST);

    return 0;
}
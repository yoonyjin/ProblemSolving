#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    // 처음 풀이
    //bool check[10] = { false, };

    //for (int i = 0; i < arr.size(); i++)
    //{
    //    if (!check[arr[i]])
    //    {
    //        fill_n(check, 10, 0);
    //        check[arr[i]] = true;
    //        answer.push_back(arr[i]);
    //    }
    //}
    // return answer;

    // 두번째 풀이
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
     return arr;
}
void main() {
    solution({4,4,4,3,3});
}
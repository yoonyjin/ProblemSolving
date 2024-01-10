#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	// 단순히 더하는 방법
	for (int i = 0; i < arr1.size(); i++)
	{
		for (int j = 0; j < arr1[i].size(); j++)
		{
			arr1[i][j] += arr2[i][j];
		}
	}
    return arr1; 

	// 돟적 할당하는 방법
	// 
	//vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size()));

	//for (int i = 0; i < arr1.size(); i++)
	//{
	//	for (int j = 0; j < arr1[i].size(); j++)
	//	{
	//		answer[i][j] += (arr1[i][j] + arr2[i][j]);
	//	}
	//}
	// return answer;
}
#include <iostream>

using namespace std;


float Calculation(const float& score, const string& grade)
{
	float GradePoint = 0.0;

	if ('P' == grade[0] || 'F' == grade[0])
	{
		return 0.0;
	}

	if ('A' == grade[0])
	{
		GradePoint += 4.0;
	}
	else if ('B' == grade[0])
	{
		GradePoint += 3.0;
	}
	else if ('C' == grade[0])
	{
		GradePoint += 2.0;
	}
	else if ('D' == grade[0])
	{
		GradePoint += 1.0;
	}

	if ('+' == grade[1])
	{
		GradePoint += 0.5;
	}

	return GradePoint * score;
}

int main()
{
	struct ResultByLecture
	{
		string LectureName = "";
		float Score = 0.0;
		string Grade = "";
	};

	ResultByLecture Results[20];

	for (int i = 0; i < 20; i++)
	{
		cin >> Results[i].LectureName;
		cin >> Results[i].Score;
		cin >> Results[i].Grade;
	}

	cout << fixed;
	cout.precision(6);

	float Sum = 0.0;
	float TotalScore = 0.0;

	for (int i = 0; i < 20; i++)
	{
		TotalScore += Calculation(Results[i].Score, Results[i].Grade);

		if ('P' != (char)(Results[i].Grade[0]))
		{
			Sum += Results[i].Score;
		}
	}

	cout << TotalScore / Sum;

	return 0;
}
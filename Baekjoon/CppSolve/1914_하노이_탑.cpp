#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void hanoi(int n, int begin, int mid, int end) {
	if (1 == n) {
		cout << begin << " " << end << "\n";
		return;
	}
	hanoi(n - 1, begin, end, mid);
	cout << begin << " " << end << "\n";
	hanoi(n - 1, mid, begin, end);
}

int main() {
	int N;
	string str;
	cin >> N;

	// ÀÌµ¿ È½¼ö : 2^n-1
	str = to_string(pow(2, N));
	str = str.substr(0, str.find('.'));
	str.back()--;
	cout << str;
	if (20 >= N) {
		cout << "\n";
		hanoi(N, 1, 2, 3);
	}
	return 0;

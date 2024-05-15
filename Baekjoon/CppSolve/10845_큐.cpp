#include <iostream>
#include <string>

using namespace std;

int arr[10000];
int first = -1, last = -1;

void push(int X) {
	if (9999 <= last) return;
	if (0 > first) first = 0;
	arr[++last] = X;
}

int pop() {
	if (0 > first) return -1;
	int tmp = arr[first];
	arr[first++] = 0;
	if (first > last) first = -1, last = -1;
	return tmp;
}

int size() { return 0 > first ? 0 : (last - first + 1); }
bool empty() { return 0 > first ? 1 : 0; }
int front() { return 0 > first ? -1 : arr[first]; }
int back() { return 0 > first ? -1 : arr[last]; }


int main() {
	int N;
	string func;
	cin >> N;
	while (N--) {
		cin >> func;
		if ("push" == func) {
			int num;
			cin >> num;
			push(num);
		}
		if ("pop" == func) cout << pop() << '\n';
		if ("size" == func) cout << size() << '\n';
		if ("empty" == func) cout << empty() << '\n';
		if ("front" == func) cout << front() << '\n';
		if ("back" == func) cout << back() << '\n';
	}
}
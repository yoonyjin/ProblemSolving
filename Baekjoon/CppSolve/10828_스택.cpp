#include <iostream>
#include <string>

using namespace std;

int arr[10000];
int idxTop = -1;

void push(int X) {
	if (9999 <= idxTop) return;
	arr[++idxTop] = X;
}

int pop() {
	if (0 > idxTop) return -1;
	int tmp;
	tmp = arr[idxTop];
	arr[idxTop--] = 0;
	return tmp;
}

int size() { return idxTop + 1; }
bool empty() { return 0 > idxTop ? 1 : 0; }
int top() { return 0 > idxTop ? -1 : arr[idxTop]; }


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
		if ("top" == func) cout << top() << '\n';
	}
}
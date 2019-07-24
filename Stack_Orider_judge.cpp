#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

bool IsPopOrder(const int* pPush, const int* pPop, int length) {
	bool Possible = false;
	if (pPush == nullptr || pPop == nullptr)
		return false;
	const int* pNextPush = pPush;
	const int* pNextPop = pPop;
	std::stack<int> s;
	while (pNextPop - pPop < length) {
		while (s.empty() || s.top() != *pNextPop) {
			if (pNextPush - pPush < length) {
				s.push(*pNextPush);
				pNextPush++;
			}
			else {
				break;
			}
		}
		if (s.top() != *pNextPop)
			break;
		s.pop();
		pNextPop++;
	}
	if (s.empty() && pNextPush - pPush == length)
		Possible = true;
	return Possible;
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 4,5,3,2,1 };
	int c[] = { 4,3,5,1,2 };
	int size = sizeof(a) / sizeof(a[0]);
	if (IsPopOrder(a, b, size))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	if (IsPopOrder(a, c, size))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	system("pause");
	return 0;
}

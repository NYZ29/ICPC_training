/*#define _CRT_SECURE_NO_WARNINGS
*/

#include <iostream>
//#include <cstdio>

using namespace std;

int main() {
	/*if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 2;*/

	int t;
	cin >> t;

	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;

		cout << (3 - (n % 3)) % 3 << '\n';
	}

	return 0;
}
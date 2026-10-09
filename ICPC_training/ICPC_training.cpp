/*
#define _CRT_SECURE_NO_WARNINGS
*/
#include <iostream>
#include <vector>
#include <algorithm>
//#include <cstdio>

using namespace std;

int main() {
	/*if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 2;*/

	int t;
	cin >> t;

	int n, k;
	string s;

	for (int i = 0; i < t; i++) {
		cin >> n >> k >> s;

		if (n == k) {
			for (int _ = 0; _ < n; _++) {
				cout << '-';
			}
			cout << '\n';
		}
		else {
			vector<char> ans(n);
			int start = 0, end = n - 1;

			for (char& a : ans) {
				a = '+';
			}

			sort(s.begin(), s.end());

			int j = 0;
			while (j < s.size() && s[j] == '0') {
				ans[start] = '-';
				start++;
				j++;
			}

			while (j < s.size() && s[j] == '1') {
				ans[end] = '-';
				end--;
				j++;
			}

			j = s.size() - j;

			if (end - start + 1 > 2 * j) {
				for (int _ = 0; _ < j; _++) {
					ans[start++] = '?';
					ans[end--] = '?';
				}
			}
			else {
				for (int q = start; q <= end; q++) {
					ans[q] = '?';
				}
			}

			for (const char a : ans) {
				cout << a;
			}
			cout << '\n';
		}
	}

	return 0;
}
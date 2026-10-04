#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 2;

	int n;
	cin >> n;

	vector<long long> price(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> price[i];
	}

	vector<long long> dp(n + 1, 0);

	for (int len = 1; len <= n; len++) {
		for (int piece = 1; piece <= len; piece++) {
			dp[len] = max(dp[len], price[piece] + dp[len - piece]);
		}
	}

	cout << dp[n];
	
	return 0;
}
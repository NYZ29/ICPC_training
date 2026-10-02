#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 2;

	int n;
	cin >> n;

	double minPrice;
	cin >> minPrice;

	double maxRevenue = 0.0;

	for (int i = 1; i < n; i++) {
		double currentPrice;
		cin >> currentPrice;

		maxRevenue = max(maxRevenue, currentPrice - minPrice);

		minPrice = min(minPrice, currentPrice);
	}

	cout << fixed << setprecision(1) << maxRevenue;

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	/*if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 1;*/

	int n;
	cin >> n;

	vector<double> temperatures(n);
	for (int i = 0; i < n; i++) 
		cin >> temperatures[i];

	int k = 5;
	vector<bool> isNotAbove8C(k);
	bool isTurnOn = true;

	for (int i = 0; i < k; i++) {
		isNotAbove8C[i] = (temperatures[i] <= 8);
		isTurnOn = isTurnOn && isNotAbove8C[i];
	}

	if (isTurnOn) cout << 6;
	else {
		int dayOfTurnOn = 0;

		for (int i = k; i < n && !isTurnOn; i++) {
			isTurnOn = true;
			isNotAbove8C[(i % k)] = (temperatures[i] <= 8);

			for (bool b : isNotAbove8C) {
				isTurnOn = isTurnOn && b;
				if (!isTurnOn) break;
			}

			if (isTurnOn) dayOfTurnOn = i + 2;
		}

		cout << dayOfTurnOn;
	}

	return 0;
}
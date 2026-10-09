/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	/*if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 2;*/

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		string word1, word2;
		cin >> word1 >> word2;

		int equalStart = -1;
		int minLen = min(word1.size(), word2.size());

		while (equalStart < minLen - 1 && word1[equalStart + 1] == word2[equalStart + 1]) equalStart++;

		int neededTime = word1.size() + word2.size();
		if (equalStart != -1) neededTime -= equalStart;

		cout << neededTime << '\n';
	}

	return 0;
}
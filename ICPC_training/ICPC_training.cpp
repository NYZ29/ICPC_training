#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	/*if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 2;*/

	string text;
	cin >> text;

	vector<string> st;

	for (char c : text) {
		if (c == '(') st.push_back("(");
		else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') st.push_back(string(1, c));
		else {
			vector<string> parts;

			while (st.back() != "(") {
				parts.push_back(st.back());
				st.pop_back();
			}

			st.pop_back();

			string inside;

			for (int i = (int)parts.size() - 1; i >= 0; i--) {
				inside += parts[i];
			}

			if (inside.empty()) continue;

			if (inside.front() == '(' && inside.back() == ')') {
				int balance = 0;
				bool oneGroup = true;

				for (int i = 0; i < (int)inside.size(); i++) {
					if (inside[i] == '(') balance++;
					else if (inside[i] == ')') balance--;

					if (balance == 0 && i != (int)inside.size() - 1) {
						oneGroup = false;
						break;
					}
				}

				if (oneGroup) {
					st.push_back(inside);
					continue;
				}
			}

			st.push_back("(" + inside + ")");
		}
	}

	string answer;

	for (const string& part : st) {
		answer += part;
	}

	cout << answer;

	return 0;
}
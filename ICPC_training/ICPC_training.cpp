#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

void readInput(vector<string>& matrix) {
	string row;

	while (getline(cin, row)) {
		if (!row.empty() && row.back() == '\r') {
			row.pop_back();
		}

		if (!row.empty()) {
			matrix.push_back(row);
		}
	}
}

int main() {
	if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 2;

	vector<string> matrix;
	

	readInput(matrix);

	for (int i = 0; i < matrix[0].length(); i += 4) {
		int num;
		if (matrix[0][i + 1] == ' ') {
			if (matrix[1][i] == ' ') num = 1;
			else num = 4;
		} else {
			if (matrix[1][i] == ' ') {
				if (matrix[2][i + 2] == ' ') num = 2;
				else if (matrix[2][i] == ' ' && matrix[2][i + 1] == ' ') num = 7;
				else num = 3;
			}
			else if (matrix[1][i + 1] == ' ') num = 0;
			else if (matrix[1][i + 2] == ' ') {
				if (matrix[2][i] == ' ') num = 5;
				else num = 6;
			}
			else {
				if (matrix[2][i] == ' ') num = 9;
				else num = 8;
			}
		}

		cout << num;
	}

	return 0;
}
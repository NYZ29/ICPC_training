#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
	if (!freopen("INPUT.TXT", "r", stdin)) return 1;
	if (!freopen("OUTPUT.TXT", "w", stdout)) return 2;

	int n;
	cin >> n;

	for (int labytinthNumber = 1; labytinthNumber <= n; labytinthNumber++) {
		int k, m;
		cin >> k >> m;

		vector<vector<int>> graph(k);

		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		vector<bool> used(k, false);
		queue<int> q;

		used[0] = true;
		q.push(0);

		while (!q.empty()) {
			int currentRoom = q.front();
			q.pop();

			for (int nextRoom : graph[currentRoom]) {
				if (!used[nextRoom]) {
					used[nextRoom] = true;
					q.push(nextRoom);
				}
			}
		}

		if (used[k - 1]) {
			cout << labytinthNumber;
			return 0;
		}
	}

	return 0;
}
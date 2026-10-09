#include <iostream>
#include<vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}

		vector<pair<int, int>> values(cnt.begin(), cnt.end());

		int answer = 0;
		int left = 0;
		int sum = 0;

		for (int right = 0; right < (int)values.size(); right++) {
			if (right > 0 && values[right].first != values[right - 1].first + 1) {
				left = right;
				sum = 0;
			}

			sum += values[right].second;

			while (right - left + 1 > k) {
				sum -= values[left].second;
				left++;
			}

			answer = max(answer, sum);
		}

		cout << answer << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
	int firstChild = -1;

	int firstWord = -1;
	int secondWord = -1;
};

struct Edge {
	int child;
	int nextSibling;
	char letter;
};

int getChild(
	int node,
	char letter,
	vector<Node>& trie,
	vector<Edge>& edges
) {
	int edge = trie[node].firstChild;

	while (edge != -1) {
		if (edges[edge].letter == letter) {
			return edges[edge].child;
		}

		edge = edges[edge].nextSibling;
	}

	int child = static_cast<int> (trie.size());
	trie.emplace_back();

	edges.push_back({
		child,
		trie[node].firstChild,
		letter
		});

	trie[node].firstChild = static_cast<int>(edges.size()) - 1;

	return child;
}

void updateWords(Node& node, int wordIndex) {
	if (node.firstWord == -1) {
		node.firstWord = wordIndex;
	}
	else if (node.secondWord == -1) {
		node.secondWord = wordIndex;
	}
}

void dfs(
	int node,
	int depth,
	const vector<Node>& trie,
	const vector<Edge>& edges,
	int& bestLength,
	int& firstAnswer,
	int& secondAnswer
) {
	if (trie[node].secondWord != -1 &&
		depth > bestLength) {

		bestLength = depth;
		firstAnswer = trie[node].firstWord;
		secondAnswer = trie[node].secondWord;
	}

	int edge = trie[node].firstChild;

	while (edge != -1) {
		const Edge& currentEdge = edges[edge];

		dfs(
			currentEdge.child,
			depth + 1,
			trie,
			edges,
			bestLength,
			firstAnswer,
			secondAnswer
		);

		edge = currentEdge.nextSibling;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> words(n);

	vector<Node> trie;
	vector<Edge> edges;

	trie.reserve(1'000'000);
	edges.reserve(1'000'000);

	trie.emplace_back();

	for (int i = 0; i < n; i++) {
		cin >> words[i];

		updateWords(trie[0], i);

		int node = 0;

		for (int pos = static_cast<int>(words[i].size()) - 1;
			pos >= 0;
			pos--) {
			char letter = words[i][pos];

			int child = getChild(
				node,
				letter,
				trie,
				edges
			);

			node = child;
			updateWords(trie[node], i);
		}
	}

	int bestLength = 0;
	int firstAnswer = 0;
	int secondAnswer = 1;

	dfs(
		0,
		0,
		trie,
		edges,
		bestLength,
		firstAnswer,
		secondAnswer
	);

	cout << bestLength << '\n';
	cout << words[firstAnswer] << '\n';
	cout << words[secondAnswer] << '\n';

	return 0;
}
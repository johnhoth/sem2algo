#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;

int findMSTPrim(int n, int m, const vector<vector<pair<int, int>>> &g) {
	int res = 0;
	vector<int> used(n, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, 0});
	while (!q.empty()) {
		pair<int, int> tmp(q.top());
		q.pop();
		int dist = tmp.first, v = tmp.second;
		if (!used[v]) {
			used[v] = 1;
			res += dist;
			for (auto ed : g[v]) {
				int u = ed.first, len = ed.second;
				if (!used[u]) {
					q.push({len, u});
				}
			}
		}

	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		x--;y--;
		g[x].push_back({y, c});
		g[y].push_back({x, c});
	}

	cout << findMSTPrim(n, m, g) << endl;

	return 0;
}

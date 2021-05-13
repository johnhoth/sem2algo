#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int INF = 1e9 + 7;


void dfs(vector <vector <int>> &g, vector <int> &used, vector <int> &d, vector <int> &h, int v, int p, set <int> &ans) {
	used[v] = 1;
	d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
	int children = 0;
	for (int u : g[v]) {
		if (u == p)  continue;
		if (used[u])
			d[v] = min(d[v], h[u]);
		else {
			dfs(g, used, d, h, u, v, ans);
			d[v] = min(d[v], d[u]);
			if (h[v] <= d[u] && p != -1) {
				ans.insert(v);
			}
			children++;
		}
	}
	if (p == -1 && children > 1) {
		ans.insert(v);
	}
}
			


int solve() {
	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n, vector <int>());
	vector <int> used(n, 0);
	vector <int> d(n, 0);
	vector <int> h(n, 0);
	set <int> ans;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int v = 0; v < n; ++v) {
		if (!used[v]) {
			dfs(g, used, d, h, v, -1, ans);
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i + 1 << ' ';
	}
	cout << endl;

	return 0;
}

int main() {
	solve();
	return 0;
}

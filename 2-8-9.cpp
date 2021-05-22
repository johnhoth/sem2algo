#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int INF = 1e9 + 7;


void dfs(const vector <vector <int>> &g, vector <int> &used, vector <int> &d, vector <int> &h, int v, int p, set <int> &ans) {
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
			


int find_cutpoints(const vector <vector <int>> &g) {
	vector <int> used(n, 0); // used[v] - visited vertex v or not
	vector <int> d(n, 0);
	// d[v] - minimal depth of all ->
	// -> vertices that connected with v with reverse edge
	vector <int> h(n, 0); // h[v] - height or depth of vertex from root
	set <int> ans; // result set of cutpoints
	for (int v = 0; v < n; ++v) {
		if (!used[v]) {
			dfs(g, used, d, h, v, -1, ans);
		}
	}
	return ans;
}

int main() {
	int n, m; // n - vertex number, m - edges number
	cin >> n >> m;
	vector <vector <int>> g(n, vector <int>());
	
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	auto ans = find_cutpoints(n, m, g);

	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i + 1 << ' ';
	}
	cout << endl;


	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9 + 7;


void dfs(vector <vector <int>> &g, vector <int> &tin, vector <int> &tout, int v, int p, int &timer) {
	tin[v] = timer;
	timer++;
	for (int u : g[v]) {
		if (u != p) {
			dfs(g, tin, tout, u, v, timer);
		}
	}
	tout[v] = timer;
	timer++;
}


void precalc_times(const vector <vector<int>> &g, vector<int> &tin, vector<int> &tout) {
	dfs(g, tin, tout, root, -1, timer);
}


int check_if_bridge(const vector<vector<int>> &g, int x, int y) {
	return static_cast<int>(tin[x] <= tin[y] && tout[y] <= tout[x]);
}


int main() {
	int n, timer = 0, root = 0;
	cin >> n;
	vector <vector <int>> g(n);
	vector <int> tin(n, -1), tout(n, -1);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x == 0) {
			root = i;
			continue;
		}
		x--;
		g[x].push_back(i);
		g[i].push_back(x);
	}

	precalc_times(g, tin, tout);	
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		cout << check_if_bridge(g, x - 1, y - 1) << endl;
	}

	return 0;
}

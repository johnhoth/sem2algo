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

	dfs(g, tin, tout, root, -1, timer);
	

	// for (int i:tin) {
	// 	cout << i << ' ';
	// }
	// cout << endl;

	// for (int i:tout) {
	// 	cout << i << ' ';
	// }
	// cout << endl;

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cout << static_cast<int>(tin[x] <= tin[y] && tout[y] <= tout[x]) << endl;
	}

	return 0;
}

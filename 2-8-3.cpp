#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9 + 7;


bool find_cycle(vector <vector <int>> &g, vector <int> &used, vector <int> &stack, int v, int color) {
	used[v] = color;

	stack.push_back(v);

	int found = 0;
	
	for (int u : g[v]) {
		if (used[u] == color) {
			stack.push_back(u);
			found = 1;
		} else {
			found |= find_cycle(g, used, stack, u, color);
		}
		if (found) break;
	}

	if (!found) {
		stack.pop_back();
	}

	used[v] = -color;

	return found;
}

bool check_for_cycle(vector <vector <int>> &g, vector <int> &used, vector <int> &stack) {
	for (int start = 0; start < g.size(); ++start) {
		if (!used[start]) {
			// cout << "start " << start << endl;
			if (find_cycle(g, used, stack, start, start + 1)) {
				return true;
			}
		}
	}
	return false;
}

int solve() {
	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n, vector <int>());
	vector <int> used(n, 0);
	vector <int> ans;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
	}
	
	if (check_for_cycle(g, used, ans)) {
		cout << "YES" << endl;
		int i = 0;
		while (ans[i] != ans.back()) {
			i++;
		}
		i++;
		for (; i < ans.size(); ++i) {
			cout << ans[i] + 1 << ' ';
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}

int main() {
	solve();
	return 0;
}

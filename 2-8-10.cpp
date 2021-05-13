#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int INF = 1e9 + 7;


void find_euler_cycle(vector <vector <int>> &g, vector <int> &ans, int start) {
	int n = g.size();
	vector <int> stack = {start};
	map <pair <int, int>, int> used;
	while (!stack.empty()) {
		int v = stack.back();
		int flag = 0;
		for (int u = 0; u < n; ++u) {
			if (g[v][u] && !used[make_pair(v, u)]) {
				stack.push_back(u);
				used[make_pair(v, u)] = 1;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			stack.pop_back();
			ans.push_back(v + 1);
		}
	}
}
			


int solve() {
	int n, start;
	cin >> n >> start;
	start--;
	vector <vector <int>> g(n, vector <int>(n));
	vector <int> ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> g[j][i];
			if (i != j) g[j][i] ^= 1;
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		// if (i > j) {
	// 		g[i + n][j + n] = g[i][j];
	// 			// g[i][j] = 0;
	// 		// }
	// 	}
	// }

	// for (int j = 0; j < g.size(); ++j) {
	// 	for (int i:g[j]) {
	// 		cout << i << ' ';
	// 	}
	// 	cout << endl;
	// }
	// return 0;

	find_euler_cycle(g, ans, start);
	// cout << ans.size() << endl;
	for (int i = 1; i < ans.size(); ++i) {
		cout << ans[i - 1] << ' ' << ans[i] << '\n';
	}
	// for (int i = 1; i < ans.size(); ++i) {
	// 	cout << ans[i] << ' ' << ans[i - 1] << '\n';
	// }

	return 0;
}

int main() {
	solve();
	return 0;
}

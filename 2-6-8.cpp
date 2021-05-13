#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int INF = 1e5 + 7;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n + 1), b(m + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i + 1];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i + 1];
	}
	vector <vector <int>> d(n + 1, vector <int> (m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		int ind = 0, best = 0;
		for (int j = 1; j <= m; ++j) {
			d[i][j] = d[i - 1][j];

			if (a[i] == b[j] && d[i - 1][j] < best + 1) {
				d[i][j] = best + 1;
			}
			if (a[i] > b[j] && d[i - 1][j] > best) {
				best = d[i - 1][j];
				ind = j;
			}
		}
	}

	// for (int i=0; i<n; ++i) {
	// 	for (int j=0; j<m; ++j) {
	// 		cout <<d[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	int res = 0;
	for (int j = 1; j <= m; ++j) {
		if (d[n][j] > d[n][res]) {
			res = j;
		}
	}
	cout << d[n][res] << endl;
	return 0;
}

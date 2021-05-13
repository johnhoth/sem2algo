#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9 + 7;

int bit(int x, int i) {
	if (i < 0) return 0;
	return (x & (1 << i)) != 0;
}

int main() {

	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);

	vector <vector <int>> d(1 << n, vector <int> (1 << n));
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0;  j < (1 << n); ++j) {
			bool check = true;

			for (int k = 0; k < (n - 1); ++k) {
				if (bit(i, k) == bit(j, k) &&
					bit(i, k + 1) == bit(j, k + 1) &&
					bit(i, k) == bit(i, k+1)) {

					check = false;
					break;
				}
			}

			d[i][j] = check;
		}
	}

	vector <vector <int>> a(m + 1, vector <int> (1 << n));

	for (int i = 0; i < (1 << n); ++i) {
		a[0][i] = 1;
	}
	for (int k = 1; k <= m; ++k) {
		for (int j = 0; j < (1 << n); ++j) {
			for (int i = 0; i < (1 << n); ++i) {
				a[k][j] += a[k - 1][i] * d[i][j];
			}
		}
	}

	long long ans = 0;

	for (int i = 0; i < (1 << n); ++i) {
		ans += a[m - 1][i];
	}

	cout << ans << endl;
	// cout << a[m][0] << endl;

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9 + 7;

int bit(int x, int i) { // get i_th bit of x (counts from right)
	if (i < 0) return 0;
	return (x & (1 << i)) != 0;
}


long long number_of_beautiful_patterns(int n, int m) {
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


	return ans;
}



int main() {

	int n, m;
	cin >> n >> m;
	cout << number_of_beautiful_patterns(n, m) << endl;

	return 0;
}

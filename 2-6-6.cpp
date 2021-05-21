#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int length_of_longest_common_subsequence(vector<int> &a, vector<int> &b) {
	vector <vector <int>> dp(n + 1, vector <int> (m + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}



	return dp[n][m];;
}


int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector <int> b(m);
	for (int i=0; i<m; ++i) {
		cin >> b[i];
	}
	
	cout << length_of_longest_common_subsequence(a, b) << endl;


	return 0;
}

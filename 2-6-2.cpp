#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	
	vector <int> dp(n + 1, -1), p(n+1, -1);
	dp[0] = INF;
	int len = 0;
	for (int i = 0; i < n; ++i) {
		int left = 1, right = len;
		while (left <= right) {
			int mid = (left + right + 1) / 2;
			if (a[dp[mid]] > a[i]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
			// cout << "b " << left << ' ' << right << ' ' << mid << endl;
		}
		int newLen = left;
		p[i] = dp[newLen - 1];
		dp[newLen] = i;
		if (newLen > len) {
			len = newLen;
		}
	}
	vector <int> res(len);
	int now = dp[len];
	for (int i = len - 1; i >= 0; --i) {
		res[i] = now;
		now = p[now];
	}
	cout << res.size() << endl;
	for (int i : res) {
		cout << i + 1 << ' ';
	}
	cout << endl;
	return 0;
}

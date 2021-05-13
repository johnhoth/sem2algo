#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 999999937;

vector <vector <long long>> multiply_square(vector <vector <long long>> a, vector <vector <long long>> b) {
	vector <vector <long long>> res(a);

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			res[i][j] = 0;
			for (int k = 0; k < a.size(); ++k) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return res;
}

vector <vector <long long>> pow(vector <vector <long long>> a, long long power) {
	if (power <= 1) return a; // probably strange line
	if (power % 2 == 1) {
		return multiply_square(pow(multiply_square(a, a), power / 2), a);
	} else {
		return pow(multiply_square(a, a), power / 2);
	}
}

long long solve(long long x) {
	if (x == 1) return 5;

	vector <vector <long long>> a = {
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 0},
		{1, 1, 0, 1, 0}
	};

	auto res = pow(a, x - 1);
	long long ans = 0;
	for (auto i:res) 
		for (auto j:i) 
			ans = (ans + j) % MOD;
	return ans;
	cout << ans << endl;
}

int main() {

	// vector <pair <long long, int>> q;
	long long x = 1;
	
	while (x) {
		cin >> x;
		if (!x) break;

		cout << solve(x) << endl;
		// q.push_back(make_pair(x, q.size()));
	}
	// q.pop_back();

	// sort(q.begin(), q.end());

	
	// vector <vector <vector <long long>>> dp(2, a);
	
	// vector <int> ans(q.size());
	/*
	banned:
	34, 35, 54, 55
	*/

	// for (int i = 0; i <= q.size(); ++i) {

	// } 

	return 0;
}

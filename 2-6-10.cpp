#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int INF = 1e5 + 7;


int maximum_knapsack(int s, vector<int> &a) {
	int n = a.size();
	bitset<INF> is(0);
	
	// is[x] - are we able to get weight x
	
	is[0] = 1;
	for (int i = 0; i < n; ++i) {
   		is |= is << a[i];
	}

	for (int i = s; i >= 0; --i) {
		if (is[i]) {
			return i;
		}
	}


	return 0;
}


int main() {
	int s, n;
	cin >> s >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << maximum_knapsack(s, a) << endl;

	return 0;
}

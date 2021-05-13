#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int INF = 1e5 + 7;

int main() {
	int s, n;
	cin >> s >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	bitset<INF> is(0);
	is[0] = 1;
	for (int i = 0; i < n; ++i) {
   		is |= is << a[i];
	}

	for (int i = s; i >= 0; --i) {
		if (is[i]) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}

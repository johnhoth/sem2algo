#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;


class DSU {
private:
	vector<int> p, rk;

public:
	DSU(int sz) {
		p.resize(sz, 0);
		rk.resize(sz, 0);
		
		for (int i = 0; i < sz; ++i) {
			p[i] = i;
			rk[i] = 1;
		}
	}
	DSU() : DSU(200005) {}
	DSU(const DSU&) = delete;
  	void operator=(const DSU&) = delete;
	~DSU() = default;

	int get(int x) {
		return (p[x] == x ? x : p[x] = get(p[x]));
	}

	int unite(int a, int b) {
		int ra = get(a), rb = get(b);

		if (ra == rb) return false;

		if (rk[ra] < rk[rb]) {
			p[ra] = rb;
		} else if (rk[rb] < rk[ra]) {
			p[rb] = ra;
		} else {
			p[ra] = rb;
			rk[rb]++;
		}

		return true;
	}
};


int findMSTKruskal(int n, int m, vector<pair<int, pair<int, int>>> &e) {
	int res = 0;
	sort(e.begin(), e.end());

	DSU myDSU;

	for (auto x : e) {
		if (myDSU.unite(x.second.first, x.second.second)) {
			res += x.first;
		}
	}
	
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> g(m);
	for (int i = 0; i < m; ++i) {
		cin >> g[i].second.first >> g[i].second.second >> g[i].first;
		g[i].second.first--;
		g[i].second.second--;
	}

	cout << findMSTKruskal(n, m, g) << endl;

	return 0;
}

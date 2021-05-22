#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int INF = 1e9+7;

int weight_of_minimal_path_between(const vector<vector<pair<int, int>>> &g, int s, int t) {
    vector<int> dist(n, INF); // dist[i] - distance from s to i

    set<pair<int, int>> q; // queue of unrelaxed verticies

    dist[s] = 0;
    q.insert(make_pair(0, s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto to : g[v]) {
            int len = to.second;
            int u = to.first;
            if (dist[u] > dist[v] + len) {
                dist[u] = dist[v] + len;
                q.insert(make_pair(dist[u], u));
            }
        }
    }

    if (dist[t] == INF) {
        return -1; // no way :(
    } else {
        return dist[t];
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    
    cout << weight_of_minimal_path_between(s, t) << endl;
}


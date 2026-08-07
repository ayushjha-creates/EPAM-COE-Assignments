#include <iostream>
using namespace std;

int main() {
    int N, M, D;
    cin >> N >> M >> D;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N + 1, -1);
    vector<bool> visited(N + 1, false);

    queue<int> q;

    q.push(1);
    visited[1] = true;
    dist[1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }

    int count = 0;

    for (int i = 1; i <= N; i++) {
        if (dist[i] != -1 && dist[i] <= D)
            count++;
    }

    cout << count;

    return 0;
}
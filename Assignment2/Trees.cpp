#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> value;
int K;
int answer = 0;

void dfs(int node, int parent, int currentXor)
{
    currentXor ^= value[node];

    if (currentXor >= K)
        answer++;

    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs(child, node, currentXor);
        }
    }
}

int main()
{
    int N;
    cin >> N >> K;

    value.resize(N + 1);
    tree.resize(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> value[i];

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0, 0);

    cout << answer;

    return 0;
}
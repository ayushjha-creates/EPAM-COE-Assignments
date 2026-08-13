#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    if (n == 1) {
        cout << points[0] << endl;
        return 0;
    }

    long long prev2 = points[0];
    long long prev1 = max(points[0], points[1]);

    for (int i = 2; i < n; i++) {
        long long current = max(prev1, prev2 + points[i]);
        prev2 = prev1;
        prev1 = current;
    }

    cout << prev1 << endl;

    return 0;
}

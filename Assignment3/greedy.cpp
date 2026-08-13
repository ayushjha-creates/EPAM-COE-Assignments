#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long budget;

    cin >> n >> budget;

    vector<int> scholarships(n);

    for (int i = 0; i < n; i++) {
        cin >> scholarships[i];
    }

    sort(scholarships.begin(), scholarships.end());

    int count = 0;
    long long total = 0;

    for (int amount : scholarships) {
        if (total + amount <= budget) {
            total += amount;
            count++;
        } else {
            break;
        }
    }

    cout << count << endl;

    return 0;
}


#include <iostream>
#include <vector>
using namespace std; 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> array[i];
    }
    int tot = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            for (int u = j + 1; u < n; u ++) {
                tot += (array[i] + array[j] + array[u] == k) ? 1 : 0;
            }
        }
    }
    cout << tot << endl;
    return 0;
}
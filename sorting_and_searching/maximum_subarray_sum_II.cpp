#include <iostream> 
#include <vector>

using namespace std;
using ll = long long;

ll spt[20][200005];

int log2_val(int x) {
    return 31 - __builtin_clz(x);
}

int main() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    vector<int> v(n+1);
    for(int i = 0; i < n; ++i) cin >> v[i+1];
    vector<ll> ps(n+1);
    for(int i = 1; i < n+1; ++i) {
        ps[i] = v[i] + ps[i-1];
    }
    for(int i = 0; i < n+1; ++i) spt[0][i] = ps[i];
    for(int i = 1; i < 20; ++i) {
        for(int j = 0; j <= n-(1<<i)+1; ++j) {
            spt[i][j] = min(spt[i-1][j], spt[i-1][(1<<(i-1))+j]);
        }
    }
    ll maxel = -1e18;
    for(int i = a; i <= n; ++i) {
        int x1 = max(0,i-b);
        int x2 = max(0,i-a);
        int l = log2_val(x2 - x1 + 1);
        maxel = max(maxel, ps[i] - min(spt[l][x1], spt[l][x2-(1<<l)+1]));
    }
    cout << maxel << "\n";
}

/*

n - x + 1 = (1<<i);
n - (1<<i) + 1 = x;

x - j + 1 = (1<<(i-1));
x+1 = (1<<(i-1)) + j;

x2 - k + 1 = (1<<l);
x2 - (1<<l) + 1 = k;

mistake : oh okay minimum length of subarray should be a so i should start from index a;

*/
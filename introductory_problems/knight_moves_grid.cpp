#include <iostream>     // Input/output stream objects
#include <fstream>      // File stream objects
#include <sstream>      // String stream objects
#include <iomanip>      // Input/output manipulators
#include <string>       // String class and functions
#include <vector>       // Dynamic array
#include <list>         // Doubly linked list
#include <set>          // Set container
#include <map>          // Map container
#include <queue>        // Queue container
#include <stack>        // Stack container
#include <algorithm>    // Algorithms on sequences (e.g., sort, find)
#include <cmath>        // Mathematical functions
#include <ctime>        // Date and time functions
#include <cstdlib>      // General purpose functions (e.g., memory management)
#include <cstring>      // C-style string functions
#include <cctype>       // Character classification functions
#include <cassert>      // Assert function for debugging
#include <exception>    // Standard exceptions
#include <functional>   // Function objects
#include <iterator>     // Iterator classes
#include <limits>       // Numeric limits
#include <locale>       // Localization and internationalization
#include <numeric>      // Numeric operations (e.g., accumulate)
#include <random>       // Random number generators
#include <stdexcept>    // Standard exception classes
#include <typeinfo>     // Runtime type information
#include <utility>      // Utility components (e.g., std::pair)
#include <bitset>        // bitset

using namespace std;

using ll = long long;
const int MOD = 1e9+7;

int mod_exp(int x) {
    if(x == 0) return 1;
    ll res = mod_exp(x/2);
    int ans = (res*res)%MOD;
    if(x&1) ans = (ans*2)%MOD;
    return ans;
}

const int inf = 1e9 + 7;
vector<pair<int,int>> dirs = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int main() {
    int n; cin >> n;
    vector<pair<int,int>> v;
    vector<vector<int>> grid(n, vector<int> (n, inf));
    v.push_back({0,0});
    grid[0][0] = 0;
    for(int i = 0; i < (int) v.size(); ++i) {
        for(auto dir : dirs) {
            int x = v[i].first + dir.first;
            int y = v[i].second + dir.second;
            if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == inf) {
                grid[x][y] = grid[v[i].first][v[i].second] + 1;
                v.push_back({x,y});
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}  

/*

1 2 x + 2 1 y = a b

2x + 4y = 2a
2x + y = b

3y = 2a-b

y = (2a-b)/3
x = (2b-a)/3


*/

/*

1 2 3 4 5 | 1
2 3 4 5 1 | 4 

1 2 3 4 5 | 0 
1 2 3 4 5 | 0

a == 0 then b == 0

*/
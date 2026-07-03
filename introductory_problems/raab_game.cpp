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

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a, b; cin >> a >> b;
        if(((a != 0 && b != 0) || (a == 0 && b == 0)) && (a + b <= n))  {
            cout << "YES\n";
            vector<int> ans(n);
            int d = n - (a + b);
            for(int i = n - d; i < n; ++i) ans[i] = i+1;
            n = n - d;
            for(int i = b; i < n; ++i) {
                ans[i] = i - b + 1;
            }
            for(int i = 0; i < b; ++i) {
                ans[i] = i + a + 1;
            }
            for(int i = 0; i < n + d; ++i) cout << i + 1 << " ";
            cout << "\n";
            for(int i = 0; i < n + d; ++i) cout << ans[i] << " ";
            cout << "\n";
        }else {
            cout << "NO\n";
        }
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
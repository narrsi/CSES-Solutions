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

vector<string> solve(int n) {
    if(n == 1) {
        return {"0","1"};
    }
    vector<string> res = solve(n-1);
    vector<string> ans;
    for(string s : res) {
        ans.push_back("0"+s);
    }
    reverse(res.begin(), res.end());
    for(string s : res) {
        ans.push_back("1"+s);
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<string> ans = solve(n);
    for(string s : ans) {
        cout << s << "\n";
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
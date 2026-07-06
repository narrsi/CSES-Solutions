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
#include <bitset>       // bitset
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool is_safe(vector<int> &v, ll x, int t) {
    ll no_of_products = 0;
    for(int i : v) {    
        no_of_products += x/i;
        if(no_of_products >= t) {
            return false;
        }
    }
    if(no_of_products >= t) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    ll ans = 0;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        int d; cin >> v[i] >> d;
        ans += d;
    }
    sort(v.begin(), v.end());

    ll sum = 0;
    ll curr = 0;
    for(int i = 0; i < n; ++i) {
        curr += v[i];
        sum += curr;
    }
    ans = ans - sum;

    cout << ans << "\n";

}   

/*

reward = deadline - finshing time
a, d
duration, deadline 

d1 - a1 + d2 - a1 - a2 + .. 
d1 + d2 + d3 - (a1 + (a1 + a2) + (a1 + a2 + a3));

*/  
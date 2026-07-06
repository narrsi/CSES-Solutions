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

ll mod(ll a, ll b) {
    return (a % b + b) % b;
}

bool is_safe(vector<int> &v, ll x, int k) {
    int no_of_cuts = 0;
    ll curr_sum = 0;
    int n = v.size();
    for(int i = 0; i < n; ++i) {
        curr_sum += v[i];
        if(curr_sum > x) {
            curr_sum = v[i];
            no_of_cuts++;
        }
    }
    if(no_of_cuts >= k) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int k; cin >> k;

    vector<int> v(n);
    int maxel = -1;
    for(int i = 0; i < n; ++i) {
        cin >> v[i]; 
        maxel = max(maxel, v[i]);
    }

    ll x = maxel - 1;

    for(ll i = (long long) 1e18; i > 0; i /= 2) {
        while(is_safe(v,x+i,k)) {
            x += i;
        }
    }
    cout << x + 1 << "\n";
}       

/*

greater the number of divisions in array lesser the maximum 
divide the array into k subarrays (k-1) cuts
so maximum sum of among the subarray sums is as small as possible

2 cuts
k = 3
2 4 7 3 5

maximum sum in subarray is <=        no of cuts
21                                          0
20                                          0

19  => 0
18 => 0
17 => 0
16 => 1
15 => 1
14 => 1
13 => 1
12 => 2
11 => 2
10 => 2
9 => 2
8 => 2 ---------> ANSWER (minimum sum with no of cuts = 2);
7 => 3
.
.
.

if(no of cuts >= k) return true;
return false;

5 5
2 4 7 3 5
*/  
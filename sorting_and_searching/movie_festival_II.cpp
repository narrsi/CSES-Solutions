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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int k; cin >> k;

    vector<pair<int,int>> v(n); 

    for(int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if(a.second != b.second) return a.second < b.second; 
        return a.first < b.first;
    });

    multiset<int> ends;
    for(int i = 0; i < k; ++i) ends.insert(0);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        auto it = ends.upper_bound(v[i].first);
        if(it != ends.begin()) {
            cnt++;
            ends.erase(prev(it));
            ends.insert(v[i].second);
        }
    }
    cout << cnt << "\n";
}       

/*

greedily choose movies which ends earliest

so i should i assign a movie to that person such that endtime is as large as possible and also endtime <= v[i].first
try keeping endtimes of people as small as possible 
so i can get more room for improvement

0 0 

4 6

lower_bound >= 
upper_bound >

*/  
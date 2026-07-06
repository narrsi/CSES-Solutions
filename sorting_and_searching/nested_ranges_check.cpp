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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int,int>> v(n);
    map<pair<int,int>, int> m;
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        m[v[i]] = i;
    } 

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if(a.first != b.first) return a.first < b.first; 
        return a.second > b.second;
    });

    // does that range enclose some other range
    vector<int> encloses(n);
    int minel = 1e9 + 7;

    for(int i = n-1; i >= 0; --i) {
        if(minel <= v[i].second) {
            encloses[i] = 1;
        }
        minel = min(minel, v[i].second);
    }

    // does that range get enclosed by some other range 
    vector<int> gets_enclosed(n);
    int maxel = -1e9 - 7;

    for(int i = 0; i < n; ++i) {
        if(maxel >= v[i].second) {
            gets_enclosed[i] = 1;
        }
        maxel = max(maxel, v[i].second);
    }
    vector<int> ans1(n), ans2(n);
    for(int i = 0; i < n; ++i) {
        ans1[m[v[i]]] = encloses[i];
    }
    for(int i = 0; i < n; ++i) {
        ans2[m[v[i]]] = gets_enclosed[i];
    }
    for(int i = 0; i < n; ++i) {
        cout << ans1[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; ++i) {
        cout << ans2[i] << " ";
    }
    cout << "\n";
}   

/*

2 8 

*/
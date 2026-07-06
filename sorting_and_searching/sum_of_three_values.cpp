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
    int x; cin >> x;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    for(int k = 0; k < n; ++k) {
        int i = 0; int j = n-1; 
        int tar = x - v[k].first;
        if(tar <= 0) continue;
        while(i < j) {
            if(i == k) {
                i++;
                continue;
            }
            if(j == k){
                j--;
                continue;
            } 
            if(v[i].first + v[j].first == tar) {
                cout << v[i].second + 1 << " " << v[j].second + 1 << " " << v[k].second + 1 << "\n";
                return 0;
            }else if(v[i].first + v[j].first > tar) {
                j--;
            }else {
                i++;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}       

/*

2 8 3

2 3 8 

1000000000 > 199999

*/  
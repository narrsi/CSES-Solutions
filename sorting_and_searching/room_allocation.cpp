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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> all;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        all.push_back(v[i].first);
        all.push_back(v[i].second);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    vector<vector<int>> in(all.size()), out(all.size());
    auto getid = [&](int x) {
        return lower_bound(all.begin(), all.end(), x) - all.begin();
    };
    for(int i = 0; i < n; ++i) {
        in[getid(v[i].first)].push_back(i);
        out[getid(v[i].second)].push_back(i);
    }
    priority_queue<int> q;
    vector<int> ans(n);
    int maxel = 0;
    for(int i = 0; i < n; ++i) q.push(-i-1);
    for(int i = 0; i < all.size(); ++i) {
        for(int j : in[i]) {
            int x = -1*q.top();
            maxel = max(maxel, x);
            ans[j] = x;
            q.pop();
        }
        for(int j : out[i]) {
            q.push(-1*ans[j]);
        }
    }
    cout << maxel << "\n";
    for(int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << "\n";
}   

/*

2 8 

*/  
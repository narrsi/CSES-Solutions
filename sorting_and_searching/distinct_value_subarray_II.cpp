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

        int n, k; cin >> n >> k;
        vector<int> v(n);

        for(int i = 0; i < n; ++i) cin >> v[i]; 
        int cnt = 0;
        int start = 0;
        map<int,int> m;
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            if(m[v[i]] == 0) cnt++;
            m[v[i]]++;
            while(cnt > k) {
                m[v[start]]--;
                if(m[v[start]] == 0) cnt--;
                start++;
            }
            // cout << i << " " << start << "\n";
            ans += (i - start + 1);
        }
        
        cout << ans << "\n";
    }       

    /*

    2 8 3

    2 3 8 

    1000000000 > 199999

    ps[i] = x + ps[j] such that j < i;

    sum - x = ps[j]

    5 7
    2 -1 3 5 -2

    1 : 1
    2 : 1

    0 0 0 0 0 

    0 : 1



    */  
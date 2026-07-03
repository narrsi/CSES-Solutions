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

using namespace std;

using ll = long long;

int main() {
    ll n; cin >> n;
    ll sum = (n*n + n)/2;
    if(sum&1) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
        vector<ll> a, b;
        ll tar = sum/2;
        ll num = 0;
        ll i = n;
        for(;i >= 1; --i) {
            if(tar <= i) {
                a.push_back(tar);
                break;
            }else {
                a.push_back(i);
                tar -= i;
            }
        }
        for(; i >= 1; --i) {
            if(i != tar) b.push_back(i);
        }
        cout << a.size() << "\n";
        for(ll i : a) cout << i << " ";
        cout << "\n";
        cout << b.size() << "\n";
        for(ll i : b) cout << i << " ";
        cout << "\n";
    }
}

/*

1 2 3 4 5
4 1 3 5 2



*/
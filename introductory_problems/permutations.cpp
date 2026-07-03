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
    int n; cin >> n;
    if(n == 1) cout << 1 << "\n";
    else if(n <= 3) cout << "NO SOLUTION\n";
    else {
        vector<int> ans(n);
        int x = n/2;
        bool check = 1;
        for(int i = 0; i < n/2; ++i) {
            if(check) {
                ans[i] = x;
                ans[n-i-1] = n+1-x;
            }else {
                ans[i] = n+1-x;
                ans[n-i-1] = x;
            }
            x--;
            check ^= 1;
        }
        if(n&1) ans[n/2] = n/2 + 1;
        for(int i : ans) cout << i << " ";
    }
}

/*

1 2 3 4 5
4 1 3 5 2



*/
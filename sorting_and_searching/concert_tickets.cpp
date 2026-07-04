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


using namespace std;

int main() {
    int n, m; cin >> n >> m;
    multiset<int> h;
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        h.insert(a);
    }
    for(int i = 0; i < m; ++i) {
        int a; cin >> a;
        auto it = h.upper_bound(a);
        if(it == h.begin()) {
            if(*it == a) {
                cout << a << "\n";
                h.erase(it);
            }else {
                cout << -1 << "\n";
            }
        }else {
            cout << *prev(it) << "\n";
            h.erase(prev(it));
        }
    }
}   

/*

5 3 7 8 5

3 5 5 7 8

4 

*/
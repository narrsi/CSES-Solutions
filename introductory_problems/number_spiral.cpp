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
    int t; cin >> t;
    while(t--) {
        ll row, col; cin >> row >> col;
        ll level = max(row, col);
        if(level&1) {
            if(row <= col) {
                cout << level*level - row + 1 << "\n";
            }else {
                cout << level*level - level + 1 - (level - col) << "\n";
            }
        }else {
            if(row >= col) {
                cout << level*level - col + 1 << "\n";
            }else {
                cout << level*level - level + 1 - (level - row) << "\n";
            }
        }
    }
}

/*

1 2 3 4 5
4 1 3 5 2



*/
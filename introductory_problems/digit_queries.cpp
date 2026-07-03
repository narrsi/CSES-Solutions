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
#include <bitset>        // bitset


using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--) {
        ll k; cin >> k;
        if(k <= 9) {
            cout << k << "\n";
            continue;
        }
        ll cnt = 0;
        ll x = 9;
        for(int i = 1; i <= 18; ++i) {
            if(cnt + x*i < k) {
                cnt += x*i;
                x *= 10;
            }else {
                ll last = x/9 - 1;
                ll rem = k - cnt;
                // last + rem/i
                if(rem%i == 0) {
                    // last char of last + rem/i;
                    string s = to_string(last + rem/i);
                    cout << s[i-1] << "\n";
                    break;
                }else {
                    // (rem%i - 1)th char of last + rem/i + 1;
                    string s = to_string(last + rem/i + 1);
                    cout << s[(rem%i)-1] << "\n";
                    break;
                }
            }
        }
    }
}
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
    string s; cin >> s; 
    int n = (int) s.length();
    vector<int> v(26);
    for(int i = 0; i < n; ++i) {
        v[s[i]-'A']++;
    }
    for(int i = 0; i < 26; ++i) {
        if(v[i] > (n+1)/2) {
            cout << -1 << "\n";
            return 0;
        }
    }
    string t = "";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 26; ++j) {
            if(v[j] > 0 && (t[max(0,i-1)] != (char)(j+'A') || i == 0)) { 
                v[j]--;
                bool check = 1;
                for(int k = 0; k < 26; ++k) {
                    if(v[k] > (n-i)/2) {
                        check = 0;
                        break;
                    }
                }
                if(!check) v[j]++;
                else {
                    t += (char) (j+'A');
                    break;
                }
            }
        }
    }
    cout << t << "\n";
}
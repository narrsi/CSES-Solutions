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
using ll = long long;

int main() {
    int n; cin >> n;
    int x; cin >> x;
    vector<pair<ll,int>> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].first;
        v[i].second = i;
    } 
    sort(v.begin(), v.end());
    int i = 0; int j = n-1;
    while(i < j) {
        if(v[i].first + v[j].first == x) {
            cout << v[i].second + 1 << " " << v[j].second + 1 << "\n";
            return 0;
        }else if(v[i].first + v[j].first > x) {
            j--;
        }else {
            i++;
        }   
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}   

/*



*/
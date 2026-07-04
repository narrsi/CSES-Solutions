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
    int q; cin >> q;
    vector<int> v(n);
    vector<int> pos(n+1);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    int cnt = 1;
    for(int i = 1; i < n; ++i) {
        if(pos[i] > pos[i+1]) cnt++;
    }
    while(q--) {
        int a, b; cin >> a >> b;
        if(a == b) {
            cout << cnt << "\n";
            continue;
        }
        a--; b--;
        if(v[a] > v[b]) {
            swap(a, b);
        }
        if(v[b] - v[a] == 1) {
            if(v[a] > 1 && pos[v[a] - 1] > pos[v[a]]) cnt--;
            if(pos[v[a]] > pos[v[b]]) cnt--;
            if(v[b] < n && pos[v[b]] > pos[v[b] + 1]) cnt--;
            swap(pos[v[a]], pos[v[b]]);
            if(v[a] > 1 && pos[v[a] - 1] > pos[v[a]]) cnt++;
            if(pos[v[a]] > pos[v[b]]) cnt++;
            if(v[b] < n && pos[v[b]] > pos[v[b] + 1]) cnt++;
            swap(v[a], v[b]);
        }else {
            if(v[a] > 1 && pos[v[a] - 1] > pos[v[a]]) cnt--;
            if(pos[v[a]] > pos[v[a] + 1]) cnt--;
            if(pos[v[b] - 1] > pos[v[b]]) cnt--;
            if(v[b] < n && pos[v[b]] > pos[v[b] + 1]) cnt--;
            swap(pos[v[a]], pos[v[b]]);
            if(v[a] > 1 && pos[v[a] - 1] > pos[v[a]]) cnt++;
            if(pos[v[a]] > pos[v[a] + 1]) cnt++;
            if(pos[v[b] - 1] > pos[v[b]]) cnt++;
            if(v[b] < n && pos[v[b]] > pos[v[b] + 1]) cnt++;
            swap(v[a], v[b]);
        }
        cout << cnt << "\n";
    }
}   

/*

5
4 2 1 5 3

1 + 1 

*/
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

ll cnt = 0;
string s;
const int N = 7;
vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<bool>> visited(N+2, vector<bool> (N+2,0));

void solve(int x, int y, int k) {
    visited[x][y] = 1;
    if(x == N && y == 1) {
        if(k == N*N-1) cnt++;
        visited[x][y] = 0;
        return;
    }
    if((visited[x-1][y-1] && !visited[x-1][y] && !visited[x][y-1]) || (visited[x+1][y+1] && !visited[x+1][y] && !visited[x][y+1]) || (visited[x-1][y+1] && !visited[x-1][y] && !visited[x][y+1]) || (visited[x+1][y-1] && !visited[x+1][y] && !visited[x][y-1])) {
        visited[x][y] = 0;
        return;
    }
    if((visited[x+1][y] && visited[x-1][y] && !visited[x][y-1] && !visited[x][y+1]) || (!visited[x+1][y] && !visited[x-1][y] && visited[x][y-1] && visited[x][y+1])) {
        visited[x][y] = 0;
        return;
    }
    if(s[k] == '?') {
        for(pair<int,int> dir : dirs) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny]) {
                solve(nx,ny,k+1);
            }
        }
    }else {
        if(s[k] == 'L' && !visited[x][y-1]) solve(x,y-1,k+1);
        else if(s[k] == 'R' && !visited[x][y+1]) solve(x,y+1,k+1);
        else if(s[k] == 'D' && !visited[x+1][y]) solve(x+1,y,k+1);
        else if(s[k] == 'U' && !visited[x-1][y]) solve(x-1,y,k+1);
    }
    visited[x][y] = 0;
}

int main() {
    for(int i = 0; i < N+2; ++i) {
        visited[0][i] = 1;
        visited[N+1][i] = 1;
        visited[i][0] = 1;
        visited[i][N+1] = 1;
    }
    cin >> s;
    solve(1,1,0);
    cout << cnt << "\n";
}
#include <iostream>
#include <vector>
#include <unordered_map>

#define loop(start, end, inc) for(int itr = start; itr != end; itr += inc)

using namespace std;

vector<string> gears;
vector<vector<int>> visited;

inline bool isDigit(char a) {
    return  ((a - '0') >= 0) and ((a-'0') < 10);
}

int expandNumber(int i, int j) {
    int ans = 0;
    if( isDigit(gears[i][j]) ) {
        int start_index = j;
        while( start_index > -1 and isDigit(gears[i][start_index])) start_index--;
        start_index++;

        while(start_index < gears[i].size() and isDigit(gears[i][start_index])) {
            visited[i][start_index] = 1;
            ans = ans * 10 + (gears[i][start_index++] - '0');
        }
    }
    return ans;
}

int findNumber(int i, int j) {
    vector<pair<int, int>> points{
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    long long num_prod = 1, count = 0;
    for(auto& point: points) {
        int index_i = i + point.first, index_j = j + point.second;
        if( index_i < 0 || index_i >= gears.size()
        || index_j < 0 || index_j >= gears[index_i].size() || visited[index_i][index_j] ) {
            // cout << "YES\n";
            continue;
        };

        long long temp = expandNumber(index_i, index_j);
        if(temp) {
            count++;
            num_prod *= temp; 
        }
    }
    return (count == 2)?num_prod:0;
}

long long solve() {
    long long ans = 0;
    for(int i = 0; i < gears.size(); i++) {
        for(int j = 0; j < gears[i].size(); j++) {
            if(gears[i][j] == '*') {
                ans += findNumber(i, j);
            }
        }
    }
    return ans;
}

int main() {
    freopen("input", "r", stdin);

    string input;
    long long ans = 0;

    while( cin >> input ) {
        gears.push_back(input);
    }

    visited = vector<vector<int>> (gears.size(), vector<int>(gears[0].size(), 0));
    ans = solve();

    cout << ans << "\n";
}
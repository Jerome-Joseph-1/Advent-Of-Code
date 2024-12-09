#include <iostream>

#define loop(start, end, inc) for(int itr = start; itr != end; itr += inc)

using namespace std;

int max_g, max_b, max_r;

int isGamePossible(string& input) {
    int gameId, n, g, r, b;
    int mg = 0, mr = 0, mb = 0;
    cin >> gameId >> n;
    // cout << gameId << " " << n << "\n";
    for(int i = 0; i < n; i++) {
        cin >> g >> r >> b;
        mg = max(mg, g);
        mr = max(mr, r);
        mb = max(mb, b);
    }

    return mg * mr * mb;
}

int main() {
    freopen("formatted_input", "r", stdin);

    string input;
    long long ans = 0;
    max_g = 13, max_b  = 14, max_r = 12;
    while( cin >> input ) {
        long long temp = isGamePossible(input);
        ans += temp;
    }
    cout << ans << "\n";
}
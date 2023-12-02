#include <iostream>

#define loop(start, end, inc) for(int itr = start; itr != end; itr += inc)

using namespace std;

int findIndex(string& input, int direction) {
    int ans = 0;
    int start = 0, end = input.size(), inc = 1;
    if(direction) start = input.size() - 1, end = -1, inc = -1;
    loop(start, end, inc) {
        if(input[itr] - '0' < 10 and input[itr] - '0' > -1) 
            { ans = input[itr] - '0'; break;}
    }

    return ans;
}

int main() {
    freopen("input", "r", stdin);

    string input;
    long long ans = 0;

    while( cin >> input ) {
        long long temp = findIndex(input, 0) * 10 + findIndex(input, 1);
        ans += temp;
    }
    cout << ans << "\n";
}
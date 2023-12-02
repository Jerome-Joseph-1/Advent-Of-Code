#include <iostream>
#include <unordered_map>
#include <vector>

#define loop(start, end, inc) for(int itr = start; itr != end; itr += inc)

using namespace std;

unordered_map<string, int> valid;
unordered_map<char, vector<int>> lengths;

void initialize( vector<string>& s, unordered_map<char, vector<int>>& lengths, unordered_map<string, int> &valid) {
    int count = 1;
    for(auto str: s) {
        lengths[str[0]].push_back(str.size());
        valid[str] = count++;
    }
}

bool checkWord(string& input, int index, int& wordValue) {
    if(input[index] - '0' > -1 and input[index] - '0' < 10) {
        wordValue = input[index] - '0';
        return true;
    }
    for(auto& length: lengths[input[index]]) {
        if(index + length - 1 < input.size() and valid[input.substr(index, length)]) {
            wordValue = valid[input.substr(index, length)];
            return true;
        }
    }
    return false;
}

int findIndex(string& input, int direction) {
    int ans = 0, wordValue = 0;
    int start = 0, end = input.size(), inc = 1;
    if(direction) start = input.size() - 1, end = -1, inc = -1;
    
    loop(start, end, inc) {
        if(checkWord(input, itr, wordValue)) {
            ans = wordValue;
            break;
        }
    }

    return ans;
}

int main() {
    freopen("input", "r", stdin);

    string input;
    long long ans = 0;

    vector<string> s{
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };

    initialize(s, lengths, valid);

    while( cin >> input ) {
        long long temp = findIndex(input, 0) * 10 + findIndex(input, 1);
        ans += temp;
    }
    cout << ans << "\n";
}
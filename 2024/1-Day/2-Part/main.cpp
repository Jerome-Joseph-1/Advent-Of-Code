#include <iostream>
#include <vector>
#include <map>
#define ll long long 

using namespace std;

int main() {
    ll n; cin >> n;

    vector<ll> l(n), r(n);
    map<ll, ll> mp;

    for(ll i = 0; i < n; i++) cin >> l[i] >> r[i], mp[r[i]]++;

    ll ans = 0;

    for(ll i = 0; i < n; i++) {
        ans += l[i] * mp[l[i]];
    }

    cout << ans << "\n";
    return 0;
}
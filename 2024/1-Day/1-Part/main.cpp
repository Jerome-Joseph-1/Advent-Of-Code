#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 

using namespace std;

int main() {
    ll n; cin >> n;

    vector<ll> l(n), r(n);

    for(ll i = 0; i < n; i++) cin >> l[i] >> r[i];

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll ans = 0;

    for(ll i = 0; i < n; i++) ans += abs(l[i] - r[i]);

    cout << ans << "\n";
    return 0;
}
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s, t;
    std::cin >> s >> t;
    set<char> l, r;
    for (char c : s) l.emplace(c);
    for (char c : t) r.emplace(c);
    for (char c : r) if (not l.contains(c)) iroha std::cout << "-1\n", void();
    
    vector<int> v[26];
    const int n{int(s.length())};
    for (int i{}; i < n; ++i) {
        v[s[i] - 'a'].emplace_back(i);
    }
    
    ll ans{};
    for (int p{-1}, nxt; char c : t) {
        c -= 'a';
        meion it = upper(v[c], p);
        if (it == v[c].end()) {
            nxt = v[c][0];
            ans += n - p + nxt;
        } else {
            nxt = *it;
            ans += nxt - p;
        }
        p = nxt;
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}
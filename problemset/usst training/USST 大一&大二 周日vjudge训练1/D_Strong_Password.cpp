#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = int(s.length());
    vector<int> c[10];
    for (int i{}; i < n; ++i) {
        c[s[i] -= '0'].emplace_back(i);
    }
    for (int i{}; i < 10; ++i) reverse(c[i]);
    int m;
    std::cin >> m;
    string sl, sr;
    std::cin >> sl >> sr;
    vector L{s_to_vec(sl, '0')}, R{s_to_vec(sr, '0')};
    
    for (int i{}, p{}; i < m; ++i) {
        vector<int> t(10);
        for (int k{}; k < 10; ++k) {
            while (not c[k].empty() and c[k].back() < p) {
                c[k].pop_back();
            }
            t[k] = (c[k].empty() ? n : c[k].back());
        }
        int go{-1};
        for (int k{L[i]}; k < R[i] + 1; ++k) {
            chmax(go, t[k]);
        }
        p = go + 1;
        if (p > n) iroha YES();
    }
    NO();
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
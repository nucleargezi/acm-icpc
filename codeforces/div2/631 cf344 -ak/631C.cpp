#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(int, a, n);
    vector<pair<int, int>> s;
    FOR(m) {
        INT(op, sz);
        while (not(s.empty() or s.back().second > sz)) s.pop_back();
        if (s.empty() or s.back().first != op) s.emplace_back(op, sz);
    }
    s.emplace_back(0, 0);
    multiset<int> se{a.begin(), a.begin() + s[0].second};
    vector<int> lst{a.begin() + s[0].second, a.end()};
    vector<int> ans;
    FOR(i, len(s) - 1) {
        meion [op, sz] = s[i];
        meion [po, zs] = s[i + 1];
        FOR(sz - zs) {
            if (op == 1) {
                ans.emplace_back(*se.rbegin());
                se.extract(--se.end());
            } else {
                ans.emplace_back(*se.begin());
                se.extract(se.begin());
            }
        }
    }
    reverse(ans);
    UL(ans + lst);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}
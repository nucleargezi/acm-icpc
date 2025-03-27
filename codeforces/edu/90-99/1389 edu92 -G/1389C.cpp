#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    SV(s, '0');
    const int n{len(s)};

    vector<int> c(10);
    FOR(i, n) ++c[s[i]];

    int ans{n - qmax(c)};
    vector<pair<int, int>> t;
    FOR(i, 10) FOR(k, 10) if (i != k) t.emplace_back(i, k);

    for (meion [x, y] : t) {
        int a[]{x, y}, k{}, c{};
        FOR(i, n) if (a[k] == s[i]) {
            k ^= 1;
            ++c;
        }
        chmin(ans, n - c + k);
    }
    UL(ans);
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
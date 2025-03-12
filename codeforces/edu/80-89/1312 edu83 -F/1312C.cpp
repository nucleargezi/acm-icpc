#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, K);
    assert(K);
    VEC(ll, a, n);

    vector<vector<int>> v(n);
    FOR(i, n) {
        while (a[i]) {
            v[i].emplace_back(a[i] % K);
            a[i] /= K;
        }
        v[i].resize(64, 0);
    }

    FOR(i, 64) {
        int s{};
        FOR(k, n) {
            s += v[k][i];
        }
        if (s > 1) iroha NO();
    }
    YES();
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
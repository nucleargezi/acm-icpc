#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<vector<int>> v(n);
    vector<uint> vis(n), chs(n);
    FOR(i, n) {
        INT(sz);
        v[i].resize(sz);
        IN(v[i]);
        sort(v[i]);
        for (int x : v[i]) {
            if (vis[x - 1]) continue;
            vis[x - 1] = 1;
            chs[i] = x;
            break;
        }
    }
    FOR(i, n) if (not chs[i]) {
        FOR(k, n) {
            if (not vis[k]) {
                iroha UL("IMPROVE"), UL(i + 1, k + 1);
            }
        }
        break;
    }
    UL("OPTIMAL");
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
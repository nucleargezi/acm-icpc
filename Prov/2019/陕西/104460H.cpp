#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/primtable.hpp"

constexpr int N = 1'000'00;
vector prims = primtable(N);
void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n);
    const int m{upper(prims, n) - prims.begin()};
    vector<int> vis(n + 1), ans;
    FOR_R(i, m) {
        vector<int> v;
        FOR(k, prims[i], n + 1, prims[i]) {
            if (not vis[k]) v.emplace_back(k);
        }
        if (len(v) & 1) {
            if (len(v) == 1) continue;
            for (int x : v)
                if (x != v[1]) {
                    vis[x] = 1;
                    ans.emplace_back(x);
                }
        } else {
            ans += v;
            for (int x : v) vis[x] = 1;
        }
    }
    UL(len(ans) >> 1, ans);
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
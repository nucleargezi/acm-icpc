#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    sort(a);
    
    map<int, int> M;
    FOR(i, n) ++M[a[i]];
    int ans{};
    FOR(i, n) {
        if (not M[a[i]]) continue;
        --M[a[i]];
        FOR(x, 1, inf<int>) {
            if (M.contains(a[i] + x) and M[a[i] + x]) {
                --M[a[i] + x];
            } else {
                break;
            }
        }
        ++ans;
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
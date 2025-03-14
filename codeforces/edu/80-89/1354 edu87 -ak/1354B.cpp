#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    SV(s, '0');
    const int n{len(s)};
    int ans{inf<int>};
    FOR(i, 1, 4) {
        FOR(k, 1, 4) {
            FOR(j, 1, 4) {
                if (i == k or i == j or k == j) continue;
                vector<int> L(n, inf<int>), R(n, -inf<int>);
                FOR(x, n) {
                    if (s[x] == i) L[x] = x;
                    else if (x) L[x] = L[x - 1];
                }
                FOR_R(x, n) {
                    if (s[x] == k) R[x] = x;
                    else if (x < n - 1) R[x] = R[x + 1];
                }
                FOR(x, n) {
                    if (s[x] == j and L[x] != inf<int> and R[x] != -inf<int>) {
                        chmin(ans, R[x] - L[x] + 1);
                    }
                }
            }
        }
    }
    UL(ans == inf<int> ? 0 : ans);
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
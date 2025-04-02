#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m, k);
    vector<pair<int, int>> X(n), Y(m);
    FOR(i, k) {
        INT(op, x, y);
        (op == 1 ? X : Y)[--x] = {i, y};
    }
    vector ans(n, vector<int>(m));
    FOR(i, n) FOR(k, m) { 
        ans[i][k] = MAX(X[i], Y[k]).second; 
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
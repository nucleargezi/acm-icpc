#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    SV(a, '0');
    vector c(2, vector<int>(n + 1));
    FOR(i, n) {
        c[0][i + 1] = c[0][i];
        c[1][i + 1] = c[1][i];
        if (a[i] == -1) continue;
        c[a[i]][i + 1] = i + 1;
    }
    vector<int> ans;
    FOR(len, 1, n + 1) {
        int l{}, s{};
        while (l + len < n + 1) {
            if (c[0][l + len] == c[0][l] or c[1][l + len] == c[1][l]) {
                l += len;
                ++s;
            } else {
                l = c[c[1][l + len] < c[0][l + len]][l + len];
            }
        }
        ans.emplace_back(s);
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
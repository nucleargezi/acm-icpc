#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    vector<int> stk;
    stk.emplace_back(-1);
    int mx{}, ans{1};
    FOR(i, n) {
        if (s[i] == '(') {
            stk.emplace_back(i);
        } else {
            stk.pop_back();
            if (not stk.empty()) {
                int x{i - stk.back()};
                if (chmax(mx, x)) {
                    ans = 1;
                } else if (mx == x) {
                    ++ans;
                }
            } else {
                stk.emplace_back(i);
            }
        }
    }
    UL(mx, ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}
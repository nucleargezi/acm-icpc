#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);

    int ans{}, p{};
    vector<int> s;
    FOR(i, n << 1) {
        S(op);
        int x{};
        if (len(op) == 3) IN(x);
        if (x) {
            s.emplace_back(x);
        } else {
            ++p;
            if (not s.empty() and s.back() == p) {
                s.pop_back();
            } else if (not s.empty()) {
                ++ans;
                s.clear();
            } 
        }
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
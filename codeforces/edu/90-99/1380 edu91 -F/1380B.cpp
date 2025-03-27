#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};

    map<char, int> M{{'S', 'R'}, {'R', 'P'}, {'P', 'S'}}, se;
    FOR(i, n) ++se[s[i]];    
    
    pair<int, char> mx{};
    for (meion [x, y] : se) {
        chmax(mx, pair{y, x});
    }
    UL(string(n, M[mx.second]));
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
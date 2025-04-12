#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    set<string> se;
    string s;
    ll ans{};
    while (std::getline(std::cin, s)) {
        if (s[0] == '+') {
            se.emplace(s.substr(1));
        } else if (s[0] == '-') {
            se.extract(s.substr(1));
        } else {
            FOR(i, len(s)) {
                if (s[i] == ':') {
                    ans += len(s.substr(i + 1)) * se.size();
                }
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}
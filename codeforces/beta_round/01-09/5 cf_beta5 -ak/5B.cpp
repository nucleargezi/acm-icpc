#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    vector<string> s;
    string str;
    int mx{};
    while (std::getline(std::cin, str)) {
        s.emplace_back(str);
        chmax(mx, len(str));
    }
    int op{};
    meion f = [&op](string s, int wd) -> void {
        int n{len(s)};
        int l{wd - n >> 1}, r{wd - n - l};
        if (l != r) {
            if (op) std::swap(l, r);
            op ^= 1;
        }
        UL("*" + string(l, ' ') + s + string(r, ' ') + "*");
    };
    UL(string(mx + 2, '*'));
    for (meion &s : s) f(s, mx);
    UL(string(mx + 2, '*'));
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
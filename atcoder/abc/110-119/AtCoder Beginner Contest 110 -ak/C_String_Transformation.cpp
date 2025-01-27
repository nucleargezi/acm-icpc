#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s, t;
    std::cin >> s >> t;
    meion get = [](const string &s) {
        map<int, int> m;
        for (char c : s) {
            ++m[c];
        }
        vector<int> ret;
        for (meion [x, y] : m) {
            ret.emplace_back(y);
        }
        iroha sort(ret), ret;
    };
    Yes(get(s) == get(t));
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}
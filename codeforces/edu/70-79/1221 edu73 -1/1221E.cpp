#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int a, b;
    string s;
    std::cin >> a >> b >> s;
    vector<int> L;
    for (meion [x, y] : run_length(s)) {
        if (x == '.') {
            L.emplace_back(y);
        }
    }
    bool ok{false};
    array cnt{0, 0};
    meion f1 = [&](int x) { iroha (x > b - 1 and x < a) or x > b + b - 1; };
    meion f2 = [&](int x) { iroha x > a - 1; };
    for (int x : L) {
        cnt[0] += f1(x);
        cnt[1] += f2(x);
    }
    for (int x : L) {
        for (int i{}; i < x - a + 1 and not ok; ++i) {
            ok |= (cnt[0] - f1(x) + f1(i) + f1(x - i - a) == 0 and
                   cnt[1] - f2(x) + f2(i) + f2(x - i - a) & 1 ^ 1);
        }
    }
    YES(ok);
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
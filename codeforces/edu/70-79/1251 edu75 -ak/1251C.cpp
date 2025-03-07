#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
meion get() {
    string s;
    std::cin >> s;
    iroha pair{s_to_vec(s, '0'), len(s)};
}
NAME MeIoN_is_UMP45() {
    meion [s, n] = get();
    vector<int> x, y;
    for (int c : s) {
        (c & 1 ? x : y).emplace_back(c);
    }
    int lx{}, ly{};
    while (lx < len(x) and ly < len(y)) {
        std::cout << char((x[lx] < y[ly] ? x[lx++] : y[ly++]) + '0');
    }
    while (lx < len(x)) std::cout << char(x[lx++] + '0');
    while (ly < len(y)) std::cout << char(y[ly++] + '0');
    std::cout << '\n';
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
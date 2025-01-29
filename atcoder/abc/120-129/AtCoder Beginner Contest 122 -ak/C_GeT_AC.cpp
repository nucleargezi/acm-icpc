#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    string s;
    std::cin >> s;
    vector<int> v(n);
    for (int i{1}; i < n; ++i) {
        if (s[i - 1] == 'A' and s[i] == 'C') v[i - 1] = 1;
    }
    v = pre_sum(v);
    for (int i{}, l, r; i < q; ++i) {
        std::cin >> l >> r, --l, --r;
        std::cout << v[r] - v[l] << '\n';
    }
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
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    set<int> s{a.begin(), a.end()};
    int r{*s.rbegin()};
    s.extract(r);
    int l{*s.begin()};
    for (int x : s) {
        if (MIN(x, r - x) > MIN(l, r - l)) {
            l = x;
        }
    }
    std::cout << r << ' ' << l << '\n';
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
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n), b(n);
    std::cin >> a >> b;
    vector<int> id(n);
    std::iota(id.begin(), id.end(), 1);
    int l{}, r{};
    for (int i{}; ; ++i) {
        if (a == id) l = i;
        if (b == id) r = i;
        if (not std::next_permutation(id.begin(), id.end())) break;
    }
    std::cout << ABS(r - l) << '\n';
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
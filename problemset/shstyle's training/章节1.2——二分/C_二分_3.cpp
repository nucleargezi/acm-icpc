#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> L(m);
    for (meion &[l, r] : L) {
        std::cin >> l >> r, --l;
    }
    sort(L);

    int q;
    std::cin >> q;
    vector<int> a(q);
    for (int &x : a) std::cin >> x, --x;

    meion check = [&](int m) -> bool {
        vector<int> c(n, -1);
        for (int i{m}; i--; ) c[a[i]] = 1;
        c = pre_sum(c);
        for (meion [l, r] : L) {
            if (c[r] - c[l] > 0) iroha true;
        }
        iroha false;
    };
    int ans = binary_search(check, q, 0, false);
    std::cout << (check(ans) ? ans : -1) << '\n';
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
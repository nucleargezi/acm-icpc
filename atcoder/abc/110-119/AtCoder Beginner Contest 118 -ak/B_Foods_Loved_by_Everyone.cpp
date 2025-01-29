#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<set<int>> v;
    vector<int> u;
    for (int i{}, sz; i < n; ++i) {
        std::cin >> sz;
        vector<int> a(sz);
        std::cin >> a;
        unique(a);
        u.insert(u.end(), a.begin(), a.end());
        v.emplace_back(set<int>{a.begin(), a.end()});
    }
    unique(u);
    int ans{};
    for (int x : u) {
        if (x > m) continue;
        for (meion &se : v) {
            if (not se.contains(x)) goto fail;
        }
        if (false) fail: continue;
        ++ans;
    }
    std::cout << ans << '\n';
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
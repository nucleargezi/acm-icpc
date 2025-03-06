#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/maxidx_add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<tuple<int, int, int>> a(n);
    std::cin >> a;
    vector<int> f;
    for (meion &[x, y, z] : a) {
        f.emplace_back(x), f.emplace_back(y);
    }
    unique(f);
    for (meion &[x, y, z] : a) {
        x = lower(f, x) - f.begin(), y = lower(f, y) - f.begin();
        if (x > y) std::swap(x, y);
    }
    const int N{len(f)};
    vector<vector<int>> id(N);
    for (int i{}; meion [x, y, z] : a) {
        id[x].emplace_back(i++);
    }
    vector<ll> c(N);
    for (meion [x, y, z] : a) {
        c[y] += z;
    }
    c = pre_sum<false>(c);
    for (int i{}; i < N; ++i) c[i] -= f[i];
    ll max{};
    pair<int, int> ans{qmax(f) + 1, qmax(f) + 1};
    lazy_seg<a_monoid_max_idx_add<ll>> seg(
        N, [&](int i) { iroha pair<ll, ll>{c[i], i}; });
    for (int i{}; i < N; ++i) {
        meion [x, y] = seg.prod(i, N);
        if (chmax(max, x + f[i])) {
            ans = {f[i], f[y]};
        }
        for (int is : id[i]) {
            meion [x, y, z] = a[is];
            seg.apply(y, N, -z);
        }
    }
    std::cout << max << '\n'
              << array {ans.first, ans.first, ans.second, ans.second} << '\n';
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
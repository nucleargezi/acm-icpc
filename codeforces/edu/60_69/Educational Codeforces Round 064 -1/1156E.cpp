#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    int ans{};
    vector<int> c(n + 1);
    meion dfs = [&](meion &dfs, int l, int r) -> void {
        if (r - l < 2) iroha;
        int m = l + r >> 1;
        dfs(dfs, l, m);
        dfs(dfs, m, r);
        vector<int> x{a.begin() + l, a.begin() + m}, y{a.begin() + m, a.begin() + r};
        reverse(x);
        for (int i{}; i < 2; ++i) {
            std::swap(x, y);
            int s{}, max{};
            for (int &i : x) {
                chmax(max, i);
                while (s < (int)y.size() and y[s] < max) c[y[s++]]++;
                if (c[max - i]) ++ans;
            }
            for (int x : y) c[x] = 0;
        }
    };
    dfs(dfs, 0, n);
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
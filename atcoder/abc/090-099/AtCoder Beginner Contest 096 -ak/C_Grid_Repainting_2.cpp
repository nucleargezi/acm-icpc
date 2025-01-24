#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    bool a[n][m];
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            char c;
            std::cin >> c;
            a[i][k] = c == '#';
        }
    }
    int ans{};
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            if (not a[i][k]) continue;
            for (meion [dx, dy] : vector{pair{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int xx = i + dx, yy = k + dy;
                if (not(xx > -1 and xx < n and yy > -1 and yy < m)) continue;
                if (a[xx][yy]) goto fail;
            }
            ++ans;
            fail: ;
        }
    }
    No(ans);
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
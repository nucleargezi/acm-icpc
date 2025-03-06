#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    map<int, int> M;
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        ++M[x];
    }
    while (not M.empty() and M.begin()->first < 2048) {
        meion [x, y] = *M.begin();
        M.erase(M.begin());
        if (y >> 1) M[x << 1] += y >> 1;
    }
    YES(M.begin()->first == 2048);
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
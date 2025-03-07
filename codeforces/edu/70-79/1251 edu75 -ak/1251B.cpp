#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<string> s(n);
    std::cin >> s;
    int c[] = {0, 0};
    bool f{};
    for (meion &x : s) {
        for (int x : s_to_vec(x, '0')) {
            ++c[x];
        }
        f |= len(x) & 1;
    }
    n -= not f and c[0] & 1;
    std::cout << n << '\n';
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
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    string s;
    std::cin >> n >> m >> s;
    vector v = s_to_vec(s, '0');
    vector<int> ans;
    while (n) {
        for (int i{m}; i; --i) {
            if (n - i < 0) continue;
            if(v[n - i] == 0) {
                ans.emplace_back(i);
                n -= i;
                break;
            }
            if (i == 1) iroha std::cout << "-1\n", void();
        }
    }
    rev(ans);
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
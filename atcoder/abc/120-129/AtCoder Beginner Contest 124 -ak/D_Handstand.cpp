#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    string s;
    std::cin >> s;
    vector<pair<int, int>> q;
    for (char c : s) {
        c -= '0';
        if (q.empty() or q.back().first != c) {
            q.emplace_back(c, 1);
        } else {
            ++q.back().second;
        }
    }
    vector<int> seg;
    for (meion [x, y] : q) {
        seg.emplace_back(y);
    }
    seg = pre_sum(seg);
    int ans{};
    n = int(seg.size()) - 1;
    for (int i{0}; meion [x, y] : q) {
        chmax(ans, seg[MIN(n, i + k + k + x)] - seg[i]);
        ++i;
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
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n), b(n), aa(n), bb(n);
    std::cin >> a >> b;
    for (int i{}; i < n; ++i) {
        aa[--a[i]] = i; 
        bb[--b[i]] = i;
    }
    map<int, int> M[2];
    ll ans{};
    for (int l{}, r{}; l < n; ++l) {
        if (r == l) M[0][aa[r]] = M[1][bb[r]] = r, ++r;
        while (r < n) {
            int ax{-1}, ay{-1}, bx{-1}, by{-1};
            meion it = M[0].upper_bound(aa[r]);
            if (it != M[0].end()) {
                ay = it->second;
            }
            if (it != M[0].begin()) {
                ax = (--it)->second;
            }
            it = M[1].upper_bound(bb[r]);
            if (it != M[1].end()) {
                by = it->second;
            }
            if (it != M[1].begin()) {
                bx = (--it)->second;
            }
            if (ax != bx or ay != by) break;
            M[0][aa[r]] = M[1][bb[r]] = r;
            ++r;
        }
        ans += r - l;
        M[0].erase(aa[l]), M[1].erase(bb[l]);
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}
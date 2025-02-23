#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    int n = (int)s.length();
    int l{}, r{n - 1};
    while (l < r and s[l] == s[r]) {
        ++l, --r, n -= 2;
    }
    s = s.substr(l, n);
    vector<int> c(26);
    for (char ch : s) {
        c[ch - 'a']++;
    }
    string t(s);
    rev(t);
    int ans{n};
    meion check = [&]() {
        HASH h(s), hh(t);
        vector<int> cc(c);
        map<char, int> m, mm;
        for (int i{}; i < n; ++i) {
            ++m[s[i]], ++mm[s[n - i - 1]];
            --cc[s[i] - 'a'];
            if (i < n / 2) {
                if (mm == m and
                    (i + 1 == n / 2 or
                     hash_same(h, i + 1, hh, i + 1, n / 2 - i - 1))) {
                    chmin(ans, i + 1);
                }
            } else {
                bool f{true};
                for (int k{}; k < 26 and f; ++k) {
                    if (cc[k] > c[k] / 2) {
                        f = false;
                    }
                }
                if (f) chmin(ans, i + 1);
            }
        }
    };
    check();
    std::swap(s, t);
    check();
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
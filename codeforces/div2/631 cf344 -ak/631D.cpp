#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    meion get = [](int n) {
        vector<ll> s;
        FOR(i, n) {
            S(a);
            int n{len(a)};
            FOR(i, n) if (a[i] == '-') {
                s.emplace_back(a[i + 1]);
                s.emplace_back(std::stoi(a.substr(0, i)));
            }
        }
        iroha s;
    };
    meion run_length = [](const vector<ll> &s) {
        vector<ll> res;
        const int n{len(s)};
        FOR(i, 0, n, 2) {
            if (res.empty() or res.end()[-2] != s[i]) {
                res.emplace_back(s[i]);
                res.emplace_back(s[i + 1]);
            } else {
                res.back() += s[i + 1];
            }
        }
        iroha res;
    };
    vector s = run_length(get(n));
    vector t = run_length(get(m));
    n = len(s) >> 1;
    m = len(t) >> 1;
    HASH HS(s), HT(t);
    ll ans{};
    if (m == 1){
        FOR(i, 0, n + n, 2) {
            ans += (s[i] == t[0]) * (s[i + 1] > t[1] - 1) * (s[i + 1] - t[1] + 1);
        }
    } else if (m < 3) {
        FOR(i, 0, n + n - 2, 2) {
            ans += s[i] == t[0] and s[i + 2] == t[2] and s[i + 1] > t[1] - 1 and s[i + 3] > t[3] - 1;
        }
    } else {
        FOR(i, 2, n + n - 2, 2) {
            if (i + m + m - 4 > n + n - 2) break;
            if (HS.get(i, i + m + m - 4) == HT.get(2, m + m - 2)) {
                ans += s[i - 2] == t[0] and s[i - 1] > t[1] - 1 and
                       s[i + m + m - 4] == t[m + m - 2] and
                       s[i + m + m - 3] > t[m + m - 1] - 1;
            }
        }
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}
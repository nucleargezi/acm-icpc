#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    ll n, k;
    std::cin >> n >> k;
    if (n == 1) {
        mint res = MAX(k - 1, 0ll);
        iroha std::cout << res.val << '\n', void();
    }
    meion rever = [&](ll n, ll i) -> mint {
        vector<ll> s;
        ll x{n};
        while (x) {
            s.emplace_back(x % i);
            x /= i;
        }
        mint res{};
        for (ll x : s) {
            res *= i;
            res += x;
        }
        iroha res;
    };
    meion get = [&](ll x, ll y) {
        if (x > y) iroha mint(0);
        iroha mint(y * (y + 1) / 2 - (x - 1) * x / 2);
    };
    meion QL = [&](ll n, ll m) -> ll {
        if (m == 0) iroha 0;
        ll res = 0;
        ll q = 1;
        while (q <= m and q <= n) {
            ll val = n / q;
            if (val == 0) break;
            ll tt = n / val + 1, cm = MIN(m, tt - 1);
            res += val * (cm - q + 1);
            q = tt;
        }
        for (ll i = q; i <= m; ++i) {
            if (i > n) break;
            res += n / i;
        }
        iroha res;
    };
    
    meion QR = [&](ll n, ll m) -> ll {
        if (m == 0) iroha 0;
        ll res = 0;
        ll q = 1;
        while (q <= m and q <= n) {
            ll val = n / q;
            if (val == 0) break;
            ll tt = n / val + 1, cm = MIN(m, tt - 1), a = q, b = cm,
               sa = (a - 1) * a * (2 * (a - 1) + 1) / 6,
               sb = b * (b + 1) * (2 * b + 1) / 6;
            res += val * (sb - sa);
            q = tt;
        }
        for (ll i = q; i <= m; ++i) {
            if (i > n) break;
            res += i * i * (n / i);
        }
        iroha res;
    };

    mint ans;
    ll sqrtn = (std::sqrt(n) + 1);
    ll a = sqrtn + 1;
    ll b = MIN(k, n);
    
    if (a < b + 1) {
        mint S = get(a, b), SL = QL(n, b), SLL = QL(n, a - 1), del = (SL - SLL),
             SR = QR(n, b), SRR = QR(n, a - 1), dell = (SR - SRR);
        ans = S * n;
        ans += del - dell;
    }
    ll limit = MIN(k, sqrtn);
    for (ll i = 2; i <= limit; ++i) {
        mint r = rever(n, i);
        ans += r;
    }
    if (k > n) {
        ll L = MAX(n + 1, 2LL);
        if (L <= k) {
            mint cnt = k - L + 1;
            ans += cnt * n;
        }
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
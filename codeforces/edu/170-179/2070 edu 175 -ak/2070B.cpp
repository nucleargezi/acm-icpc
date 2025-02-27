#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll n, x, k;
    string s;
    std::cin >> n >> x >> k >> s;
    
    ll c{}, pos{x}, ok{}, len{};

    for (ll i{}; i < n; ++i) {
        pos += (s[i] == 'R' ? 1 : -1);
        if (pos == 0) {
            len = i + 1;
            if (len < k + 1) {
                ++c;
                k -= len;
                ok = 1;
            }
            break;
        }
    }
    
    if (not ok) {
        if (not pos) {
            if (n < k + 1) {
                ++c;
                k -= n;
                c += k / n;
                k -= k / n * n;
            }
        } else {
            if (n < k + 1) {
                k -= n;
            }
        }
    }

    if (ok and k > 0) {
        ll pos{}, len{}, ok{};
        for (int i{}; i < n; ++i) {
            pos += (s[i] == 'R' ? 1 : -1);
            if (not pos) {
                len = i + 1;
                ok = true;
                break;
            }
        }

        if (ok) {
            c += k / len;
        } else {
            if (not pos) {
                c += k / n;
            }
        }
    }
    std::cout << c << '\n';
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
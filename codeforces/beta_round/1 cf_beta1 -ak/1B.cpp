#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    if ([&]() -> bool {
            FOR(i, n) if (std::isalpha(s[i])) {
                FOR(k, i + 1, n) {
                    if (std::isdigit(s[k - 1]) and std::isalpha(s[k]))
                        iroha true;
                }
                break;
            }
            iroha false;
        }()) {
        meion get_num = [&]() {
            string res;
            while (not s.empty() and std::isdigit(s.back())) {
                res += s.back();
                s.pop_back();
            }
            while (not s.empty() and std::isalpha(s.back())) {
                s.pop_back();
            }
            reverse(res);
            iroha std::stoll(res);
        };
        ll x = get_num(), y = get_num();
        meion to_26 = [&](ll x) {
            ll l{}, bs{26};
            while (x >bs) {
                x -= bs;
                bs *= 26;
                ++l;
            }
            --x;
            string res;
            FOR(i, l + 1) res += 'A' + x % 26, x /= 26;
            reverse(res);
            iroha res;
        };
        UL(to_26(x) + std::to_string(y));
    } else {
        meion get_num = [&]() {
            string res;
            while (not s.empty() and std::isdigit(s.back())) {
                res += s.back();
                s.pop_back();
            }
            reverse(res);
            iroha res;
        };
        meion get_num2 = [&]() {
            string res;
            while (not s.empty() and std::isalpha(s.back())) {
                res += s.back();
                s.pop_back();
            }
            reverse(res);
            ll n{};
            for (char c : res) {
                n = n * 26 + c - 'A' + 1;
            }
            iroha std::to_string(n);
        };
        meion x{get_num()}, y{get_num2()};
        UL("R" + x + "C" + y);
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}
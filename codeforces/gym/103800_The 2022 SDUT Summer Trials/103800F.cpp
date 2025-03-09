#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    int t;
    std::cin >> s >> t;
    vector<pair<int, int>> a;
    int n{-1}, f{-1};
    for (char c : s) {
        if (c == '|') {
            if (n != -1) a.emplace_back(f * n, len(a) + 1);
            n = -1;
            f = -1;
        } else if (c == '-') {
            f = 1;
        } else {
            if (n != -1) n = n * 10 + c - '0';
            else n = c - '0';
        }
    }
    if (n != -1) a.emplace_back(f * n, len(a) + 1);
    vector<pair<int, int>> b, c;
    vector<int> zero;
    for (meion [x, y] : a) {
        if (x < 0) b.emplace_back(x, y);
        if (x > 0) c.emplace_back(-x, y);
        if (x == 0) zero.emplace_back(y);
    }
    sort(b);
    sort(c);
    sort(zero);
    vector<int> ans;
    if (b.empty()) {
        if (zero.empty()) {
            if (t & 1) {
                for (int i{}; i < t; ++i) {
                    ans.emplace_back(c.end()[-1 - i].second);
                }
            } else {
                for (int i{}; i < t; ++i) {
                    ans.emplace_back(c[i].second);
                }
            }
        } else {
            if (t & 1) goto pas;
            else {
                for (int i{}; i < t; ++i) {
                    ans.emplace_back(c[i].second);
                }
            }
        }
    } else if (len(b) + len(c) / 2 * 2 < t) {
        pas:{}
        ans.resize(t);
        std::iota(ans.begin(), ans.end(), 1);
        if (ans.back() < zero[0]) {
            ans.pop_back();
            ans.emplace_back(zero[0]);
        }
    } else {
        int i{}, k{};
        while (i + 1 < len(b) and k + 1 < len(c) and len(ans) + 1 < t) {
            int v1{b[i].first + b[i + 1].first},
                v2{c[k].first + c[k + 1].first};
            pair<int, int> id1{b[i].second, b[i + 1].second},
                           id2{c[k].second, c[k + 1].second};
            if (v1 == v2) {
                if (id1 < id2) goto go1;
                else goto go2;
                
            } else {
                if (v1 < v2) goto go1;
                else goto go2;
            }
            if (false) go1: {
                ans.emplace_back(id1.first);
                ans.emplace_back(id1.second);
                i += 2;
            }
            if (false) go2: {
                ans.emplace_back(id2.first);
                ans.emplace_back(id2.second);
                k += 2;
            }
        }
        if (len(ans) + 1 == t) {
            if (i < len(b)) ans.emplace_back(b[i++].second);
            else {
                int x = ans.back();
                ans.pop_back();
                int y = ans.back();
                ans.pop_back();
                ans.emplace_back(c[k++].second);
                ans.emplace_back(c[k++].second);
                ans.emplace_back(y);
            }
            if (k + 1 < len(c) and i > 1) {
                int v1{b[i - 1].first + b[i - 2].first};
                int v2{c[k].first + c[k + 1].first};
                if (v2 < v1) {
                    ans.pop_back();
                    ans.pop_back();
                    ans.emplace_back(c[k++].second);
                    ans.emplace_back(c[k++].second);
                }
            }
        } else {
            if (i + 1 < len(b)) {
                while (len(ans) + 1 < t) {
                    ans.emplace_back(b[i++].second);
                    ans.emplace_back(b[i++].second);
                }
            } else {
                while (len(ans) + 1 < t) {
                    ans.emplace_back(c[k++].second);
                    ans.emplace_back(c[k++].second);
                }
            }
            if (len(ans) + 1 == t) {
                ans.emplace_back(b[i].second);
            }
        }
    }
    sort(ans);
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
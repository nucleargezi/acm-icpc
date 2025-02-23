#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    vector<char> st;
    for (char c : s) {
        if (c == '(') {
            st.emplace_back(c);
        } else if (c == ')') {
            if (st.empty() or st.back() != c - 1) iroha No();
            else st.pop_back();
        } else if (c == '[') {
            st.emplace_back(c);
        } else if (c == ']') {
            if (st.empty() or st.back() != c - 2) iroha No();
            else st.pop_back();
        } else if (c == '{') {
            st.emplace_back(c);
        } else if (c == '}') {
            if (st.empty() or st.back() != c - 2) iroha No();
            else st.pop_back();
        }
    }
    Yes(st.empty());
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
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  std::cin.ignore();
  vector<int> t;
  FOR(i, n) {
    string s;
    std::getline(std::cin, s);
    int h{std::stoi(s.substr(1, 2))}, m{std::stoi(s.substr(4, 2))};
    if (h == 12) h = 0;
    int x{60 * h + m};
    if (s.substr(7, 4) == "p.m.") x += 720;
    t += x;
  }

  int tt{1440}, ans{}, c{};
  for (int x : t) {
    if (tt > x) {
      ++ans, c = 0;
    } else if (tt == x) {
      if (c == 10) ++ans, c = 0;
    } else {
      c = 0;
    }
    ++c;
    tt = x;
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
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}
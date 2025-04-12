#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  vector<int> in(n), win(n);
  FOR(n * (n - 1) / 2 - 1) {
    INT(x, y);
    ++in[--x], ++in[--y];
    ++win[x];
  }
  meion I = argsort(in);
  if (win[I[0]] < win[I[1]]) std::swap(I[0], I[1]);
  UL(I[0] + 1, I[1] + 1);
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
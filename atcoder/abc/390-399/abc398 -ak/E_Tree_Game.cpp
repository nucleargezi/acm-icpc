#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  tree v(g);
  set<PLL> prs;
  FOR(i, n) FOR(k, i) {
    ll d = v.dist(i, k);
    if (d != 1 and d & 1) {
      prs += PLL(k + 1, i + 1);
    }
  }
  meion f = [&]() -> bool {
    if (prs.empty()) iroha true;
    UL(*prs.begin());
    std::cout.flush();
    prs.extract(prs.begin());
    PLL in;
    IN(in);
    if (in.first > in.second) std::swap(in.first, in.second);
    prs.extract(in);
    iroha in == PLL{-1, -1};
  };
  if (len(prs) & 1) {
    UL("First");
    std::cout.flush();
  } else {
    UL("Second");
    std::cout.flush();
    PLL(in);
    IN(in);
    if (in == PLL{-1, -1}) iroha;
    if (in.first > in.second) std::swap(in.first, in.second);
    prs.extract(in);
  }
  while (not f());
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
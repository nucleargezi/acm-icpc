#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  INT(n);
  ll L{}, R{}, S{};
  ll sz{};
  deque<ll> q;
  bool f{1};
  FOR(n) {
    INT(op);
    if (op == 1) {
      ll x{f ? q.back() : q.front()};
      f ? q.pop_back() : q.pop_front();
      f ? q.emplace_front(x) : q.emplace_back(x);
      (f ? L : R) -= x * sz;
      (f ? L : R) += S;
      (f ? R : L) -= S;
      (f ? R : L) += x * sz;
    } else if (op == 2) {
      f ^= 1;
    } else {
      LL(x);
      S += x;
      (f ? R : L) += S;
      (f ? L : R) += ++sz * x;
      f ? q.emplace_back(x) : q.emplace_front(x);
    }
    UL(f ? L : R);
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
  Yorisou();
  iroha 0;
}
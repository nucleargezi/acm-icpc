#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(K);
  min_heap<ll> q;
  FOR(i, 1, 10) q.eb(i);
  int d = 0;
  for (; d < K - 1; ++d) {
    ll x = pop(q);
    int top = x % 10;
    if (top > 0) q.eb(x * 10 + top - 1);
    q.eb(x * 10 + top);
    if (top < 9) q.eb(x * 10 + top + 1);
  }
  print(q.top());
}

int main() { Yorisou(); }
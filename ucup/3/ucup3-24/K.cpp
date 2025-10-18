#include "YRS/all.hpp"

void fail() { cout << "-1\n"; }

void yorisou() {
  LL(a, b, c, d);
  ll m = c - a, mm = d - b;
  if (m != mm or m <= 0) return fail();
  ll x = (a - 1) / m, y = (b - 1) / m;
  if (x != y or (a - 1) % m + 1 != (b - 1) % m) return fail();
  print(d / m + 1, m);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
  return 0;
}
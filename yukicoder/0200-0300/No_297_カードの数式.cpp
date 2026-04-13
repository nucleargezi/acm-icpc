#include "YRS/all.hpp"

ll big(vc<int>a, int b, int c) {
  sort(a, greater());
  ll s = 0;
  while (c--) s -= pop(a);
  while (b--) s += pop(a);
  ll t = 0;
  for (ll x : a) t = t * 10 + x;
  return s + t;
}
ll sml(vc<int> a, int b, int c) {
  ll s = 0;
  if (c) {
    sort(a, greater());
    ++b;
    while (b--) s += pop(a);
    while (c > 1) s -= pop(a), --c;
    ll t = 0;
    for (ll x : a) t = t * 10 + x;
    s -= t;
  } else {
    int n = b + 1;
    sort(a, greater());
    int c[20]{};
    ll ten[15]{};
    ten[0] = 1;
    FOR(i, 1, 15) ten[i] = ten[i - 1] * 10;
    FOR(i, si(a)) {
      s += a[i] * ten[c[i % n]];
      ++c[i % n];
    }
  }
  return s;
}
void Yorisou() {
  INT(N);
  vc<int> a;
  int b = 0, c = 0;
  FOR(N) {
    CH(s);
    if (s == '+') ++b;
    else if (s == '-') ++c;
    else a.ep(s - '0');
  }
  print(big(a, b, c), sml(a, b, c));
}

int main() {
  Yorisou();
  return 0;
}
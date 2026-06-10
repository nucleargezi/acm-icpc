#include "YRS/all.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/pr/divisors.hpp"

void Yorisou() {
  INT(N);
  vc<int> q(N);
  iota(all(q), 1);
  shuffle(q);
  vc<vc<int>> es;
  FOR(i, 17) {
    vc<int> a;
    FOR(k, N) if (~k >> i & 1) a.ep(q[k]);
    sort(a);
    print("?", si(a), a);
    LL(x);
    if (x) {
      vc<int> s;
      for (int e : divisor(x)) {
        int g = x / e;
        if (e <= g) s.ep(e + g);
      }
      if (si(s)) es.ep(s);
    }
  }
  
  if (es.empty()) return print("!", 1);
  vc<int> s = es[0], ss;
  sort(s);
  FOR(i, 1, si(es)) {
    sort(es[i]);
    ss.clear();
    for (int t : es[i]) {
      if (binary_search(all(s), t)) ss.ep(t);
    }
    s.swap(ss);
  }
  print('!', si(s) ? s[0] : 1);
}

int main() {
  Yorisou();
  return 0;
}
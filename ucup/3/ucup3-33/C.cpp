#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  hashmap<string> mp(1000);
  ll a[18], b[18];
  FOR(sz, 1, 18) {
    FOR(s, 1 << sz) {
      FOR(i, sz) b[i] = a[i] = s >> i & 1;
      FOR(i, sz - 1) a[i + 1] += a[i];
      FOR_R(i, sz - 1) b[i] += b[i + 1];
      ll v = 0;
      FOR(i, 1, sz - 1) if (~s >> i & 1) v += a[i - 1] * b[i + 1];
      if (not mp.contains(v)) {
        string str;
        FOR(i, sz) str += (s >> i & 1) ? 'u' : 'w';
        mp[v] = str;
      }
    }
  }
  INT(N);
  FOR(N) {
    LL(x);
    if (mp.contains(x)) {
      print(mp[x]);
    } else {
      ll t = bina([&](ll t) -> bool {
        ll a = t / 3, b = (t - a) /  2, c = t - a - b;
        return a * b * c >= x;
      }, 6'000'010, 0);
      ll a = t / 3, b = (t - a) / 2, c = t - a - b;
      if (a == b) swap(b, c);
      else if (b == c) swap(a, b);
      ll ex = a * b * c - x;
      vc<PLL> ls;
      while (ex) {
        ll g = bina([&](ll t) -> bool { return t * t <= ex; }, 0, c + 1);
        ll d = ex / (g * g);
        b -= d;
        ex -= d * g * g;
        ls.ep(d, g);
      }
      string s;
      FOR(a) s += 'u';
      FOR(b) s += 'w';
      FOR(i, c) {
        if (si(ls) and ls.back().se == i) {
          int n = pop(ls).fi;
          FOR(n) s += 'w';
        }
        s += 'u';
      }
      for (var [n, d] : ls) FOR(n) s += 'w';
      print(s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}
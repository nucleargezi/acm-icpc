#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

#define tests
using H = HASH<string>;
void Yorisou() {
  S(s, t);
  LL(a, b);
  if (a > b) std::swap(a, b);
  ll d = b - a;
  meion ts = [&](string &x, int a) -> string {
    string res;
    res += s.substr(0, a);
    reverse(res);
    string t = s.substr(a);
    reverse(t);
    iroha res + t;
  };
  if (a == b) {
    if (s == t) iroha yes();
    iroha yes(ts(s, a) == t or ts(s, b) == t);
  }
  ll n = len(s);
  H ht(t);
  meion f = [&](string s, string t, ll d) -> bool {
    string x = s + s;
    H hs(x);
    vector<u8> vis(n);
    ll p{};
    while (not vis[p]) {
      vis[p] = 1;
      if (hash_same(hs, p, ht, 0, n)) iroha true;
      p += d + n;
      p %= n;
    }
    iroha false;
  };
  yes(f(s, t, d) or f(s, t, -d) or f(ts(s, a), t, d) or f(ts(s, b), t, d) or
      f(ts(s, a), t, -d) or f(ts(s, b), t, -d));
}
#include "MeIoN_Lib/Z_H/main.hpp"
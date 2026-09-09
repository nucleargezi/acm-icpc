#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  map<PII, int> mp;
  INT(N);
  FOR(i, 1, N + 1) {
    string s = to_string(i);
    if (i % 10) ++mp[{s[0], s.back()}];
  }
  ll s = 0;
  for (var [a, b] : mp) {
    if (a.fi == a.se) {
      s += 1ll * b * b;
    } else if (a.fi < a.se) {
      s += 2ll * b * mp[{a.se, a.fi}];
    }
  }
  print(s);
}

int main() { Yorisou(); }
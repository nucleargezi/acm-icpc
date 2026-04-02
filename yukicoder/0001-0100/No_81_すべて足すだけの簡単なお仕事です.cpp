#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  INT(N);
  i128 s = 0;
  Z f = [&]() -> i128 {
    STR(s);
    Z p = s.find('.');
    if (p == string::npos) s += '.';
    p = s.find('.');
    while (len(s) - p <= 10) s += '0';
    while (ll(p) + 1 < len(s)) swap(s[p], s[p + 1]), ++p;
    i128 x = 0, op = 1;
    if (s[0] == '-') s.erase(0, 1), op = -1;
    for (char c : s) if (c != '.') x = x * 10 + c - '0';
    return x * op;
  };
  FOR(N) s += f();
  int sz = 0;
  for (i128 x = s; x; x /= 10) ++sz;
  if (s < 0) cout << "-", s = -s;
  if (sz <= 10) {
    cout << "0." << string(10 - sz, '0');
    if (s) print(s);
  } else {
    string str;
    while (s) str += s % 10 + '0', s /= 10;
    reverse(str);
    str.insert(len(str) - 10, ".");
    print(str);
  }
}
#include "YRS/aa/main.hpp"
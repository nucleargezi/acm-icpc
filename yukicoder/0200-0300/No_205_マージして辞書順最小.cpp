#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  INT(N);
  min_heap<string> q;
  FOR(N) {
    STR(s);
    s += char('z' + 1);
    q.eb(s);
  }
  string s;
  while (not q.empty()) {
    string t = pop(q);
    s += t[0];
    if (len(t) > 2) q.eb(t.substr(1));
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"
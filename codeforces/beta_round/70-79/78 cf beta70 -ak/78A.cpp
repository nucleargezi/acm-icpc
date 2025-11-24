#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  const set<char> se{'a','e','i','o', 'u'};
  vector<int> a(3);
  FOR(i, 3) {
    string line, s;
    std::getline(cin, line);
    std::istringstream is(line);
    while (is >> s) {
      int f = 0;
      for (char c : s) f += se.contains(c);
      a[i] += f;
    }
  }
  YES(a == vector{5, 7, 5});
}
#include "YRS/Z_H/main.hpp"
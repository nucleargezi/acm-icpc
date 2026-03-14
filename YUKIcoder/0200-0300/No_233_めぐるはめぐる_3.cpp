#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  VEC(string, str, N);
  set<string> se(all(str));

  string a = "nbmgr", b = "iaaeuu";
  sort(a);
  do {
    sort(b);
    do {
      FOR(i, 5) {
        string c(11, ' ');
        int bs = 0;
        FOR(k, 5) bs += i == k, c[bs] = a[k], bs += 2;
        bs = 0;
        FOR(k, 11) if (c[k] == ' ') c[k] = b[bs++];
        if (not se.contains(c)) return print(c);
      }
    } while (next_permutation(all(b)));
  } while (next_permutation(all(a)));
  NO();
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"
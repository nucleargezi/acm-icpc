#include "YRS/all.hpp"
#include "YRS/string/run_length.hpp"

ll yrs(string a, string b) {
  int N = si(a);
  FOR(i, N) a[i] = a[i] != b[i];
  if (QMAX(a) == 0) {
    return 1ll * N * (N + 1) / 2;
  } else {
    int sz = 0;
    for (pair t : run_length(a)) sz += t.fi;
    if (sz > 2) {
      return 0;
    } else if (sz == 2) {
      return 6;
    } else {
      return (N - 1) << 1;
    }
  }
}

void Yorisou() {
  INT(N);
  STR(a, b);
  print(yrs(a, b));
}
constexpr int tests = 1, fl = 0, DB = 10000;
#include "YRS/aa/main.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"

void Yorisou() {
  INT(Q, N);
  sam_ex<2> ss;
  FOR(N) {
    STR(s);
    for (char &c : s) c -= '0';
    for (int x = 0; int c : s) x = ss.add(x, c);
  }

  FOR(Q) {
    STR(s);
    for (char &c : s) c -= '0';
    int n = si(s);
    vc<int> sl = ss.run(s);
    print(bina([&](int L) -> bool {
      if (L == 0) return 1;
      vc<int> f(n + 1), q(n);
      int l = 0, r = 0;
      Z ke = [&](int i) { return f[i] - i; };
      FOR(i, 1, n + 1) {
        f[i] = f[i - 1];
        int k = i - L;
        if (k >= 0) {
          while (l < r and ke(q[r - 1]) <= ke(k)) --r;
          q[r++] = k;
        }
        int le = i - sl[i - 1];
        while (l < r and q[l] < le) ++l;
        if (l < r) chmax(f[i], i + ke(q[l]));
      }
      return 10 * f[n] >= 9 * n;
    }, 0, n + 1));
  }
}

int main() {
  Yorisou();
  return 0;
}
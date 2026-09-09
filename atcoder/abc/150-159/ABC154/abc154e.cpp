#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  FOR(i, N) s[i] -= '0';
  string t(N, 0);
  INT(k);
  int rs = 0;
  if (k == 1) {
    FOR(i, N) {
      FOR(k, 1, 10) t[i] = k, rs += t <= s;
      t[i] = 0;
    }
  }
  if (k == 2) {
    FOR(i, N) FOR(k, i + 1, N) {
      FOR(j, 1, 10) {
        t[i] = j;
        FOR(j, 1, 10) t[k] = j, rs += t <= s;
        t[k] = 0;
      }
      t[i] = 0;
    }
  }
  if (k == 3) {
    FOR(i, N) FOR(k, i + 1, N) FOR(j, k + 1, N) {
      FOR(l, 1, 10) {
        t[i] = l;
        FOR(l, 1, 10) {
          t[k] = l;
          FOR(l, 1, 10) t[j] = l, rs += t <= s;
          t[j] = 0;
        }
        t[k] = 0;
      }
      t[i] = 0;
    }
  }
  print(rs);
}

int main() { Yorisou(); }
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/binom.hpp"

using mint = mint_t<1'000'000 + 3>;
void Yorisou() {
  INT(N, M);
  retsu<char> a(N, M);
  IN(a);
  
  mint s = 1;
  FOR(i, N) {
    int f = 0;
    FOR(t, 2) {
      int g = 1;
      FOR(k, M) if (a[i][k] != '.') {
        if ((k + t) & 1) g &= a[i][k] == '1' or a[i][k] == '2';
        else g &= a[i][k] == '3' or a[i][k] == '4';
      }
      f += g;
    }
    s *= f;
  }
  FOR(k, M) {
    int f = 0;
    FOR(t, 2) {
      int g = 1;
      FOR(i, N) if (a[i][k] != '.') {
        if ((i + t) & 1) g &= a[i][k] == '2' or a[i][k] == '3';
        else g &= a[i][k] == '1' or a[i][k] == '4';
      }
      f += g;
    }
    s *= f;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}
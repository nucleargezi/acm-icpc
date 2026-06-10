#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

int to(char c) {
  if (c == 'R') return 0;
  if (c == 'Y') return 1;
  if (c == 'G') return 2;
  return 3;
}
void Yorisou() {
  INT(N);
  vc<array<int, 3>> a;
  FOR(i, N << 2) {
    INT(x);
    CH(c);
    int y = to(c);
    a.ep(array{y, i, x});
  }
  for (int i : argsort(a)) {
    FOR(k, N << 2) if (a[k][1] == i) {
      int j = k, c = a[k][0];
      while (j) {
        if (a[j - 1][0] > c) {
          if (a[j - 1][2] != a[j][2]) break;
          swap(a[j], a[j - 1]);
          --j;
        } else break;
      }
      break;
    }
  }
  vc<int> st;
  FOR(i, N << 2) st.ep(a[i][0]);
  print(is_sorted(all(st)) ? "YES" : "NO");
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}
#include "YRS/all.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  INT(N, M);
  string s, t;
  for (string x; cin >> x; ) {
    for (char c : x) {
      c -= 'A';
      (si(s) < N ? s : t) += c;
    }
  }

  sam ss(N);
  ss.build(s);
  int rs = 1;
  for (int x = 0; int c : t) {
    x = ss[x][c];
    if (x == -1) ++rs, x = ss[0][c];
  }
  print(rs);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}
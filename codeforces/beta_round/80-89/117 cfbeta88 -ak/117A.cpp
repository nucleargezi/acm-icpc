#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  FOR(i, N) {
    INT(s, t, c);
    --s, --t;
    if (s == t) {
      print(c);
      continue;
    }
    int rs = c;
    c %= M * 2 - 2;
    bool a = c < M;
    if (not a) c = M - 1 - c % (M - 1);
    if (c < s) {
      if (a) rs += s - c;
      else rs += c + s, a = 1;
    } else if (c > s) {
      if (not a) rs += c - s;
      else rs += M - c - 1 + M - s - 1, a = 0;
    }
    if (s < t) {
      if (a) rs += t - s;
      else rs += s + t;
    } else if (s > t) {
      if (not a) rs += s - t;
      else rs += M - s - 1 + M - t - 1;
    }
    print(rs);
  }
}

int main() {
  Yorisou();
  return 0;
}
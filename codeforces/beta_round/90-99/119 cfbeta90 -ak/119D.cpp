#include "YRS/all.hpp"
#include "YRS/string/hs.hpp"
#include "YRS/string/kmp.hpp"

void Yorisou() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  if (si(a) != si(b)) return print(-1, -1);
  string ra = a;
  reverse(ra);
  int N = si(a);
  hash_t ha(a), hb(b);
  Z kmp = get_next(ra + string(1, 0) + b).fi;
  int I = -1, K = I;
  FOR(i, N - 1) {
    if (a[i] != b[N - i - 1]) break;
    int g = kmp[N + N - i];
    if (not g) continue;
    int k = N - g;
    if (ha(i + 1, k) == hb(0, k - i - 1)) {
      I = i, K = k;
    }
  }
  print(I, K);
}

int main() {
  Yorisou();
  return 0;
}
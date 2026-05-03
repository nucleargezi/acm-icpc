#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  vc<PII> a(N);
  for (Z &[k, w] : a) {
    IN(k, w);
    --k;
    swap(k, w);
  }
  sort(a, greater());
  min_heap<PII> q;
  ll s = 0, c = 0, sz = 0, rs = 0;
  vc<int> v(N);
  for (var [w, k] : a) {
    c += v[k] == 0;
    if (c > K) break;
    ++sz;
    s += w;
    v[k] += 1;
    q.eb(w, k);
    while (sz > K) {
      var [w, k] = pop(q);
      if (v[k] == 1) continue;
      --sz;
      --v[k];
      s -= w;
    }
    chmax(rs, s + c * c);
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}
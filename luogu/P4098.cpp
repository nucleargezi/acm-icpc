#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/ds/trie_bina.hpp"

struct MX {
  using X = array<int, 2>;
  X op(const X &a, const X &b) {
    static int c[4];
    FOR(i, 2) c[i] = a[i], c[i + 2] = b[i];
    FOR(2) FOR(i, 3) if (c[i] > c[i + 1]) swap(c[i], c[i + 1]);
    return {c[3], c[2]};
  }
  X unit() { return {-1, -1}; }
  static constexpr bool commute = 1;
};
MX::X sing(int x) { return {x, -1}; }
using Seg = seg_t<MX>;
using Tr = trie_bina<30, 1, int, int, 1 << 16>;
using np = Tr::np;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> b = a;
  reverse(b);
  Z ke = [&](const vc<int> &a) -> int {
    Seg seg(N, [&](int i) { return sing(a[i]); });
    Tr tr;
    vc<np> t(N + 1);
    FOR(i, N) t[i + 1] = tr.add(t[i], a[i]);
    int rs = 0;
    FOR(i, N) {
      int k = seg.max_right([&](Z x) { return a[i] >= x[1]; }, i);
      int j = seg.min_left([&](Z x) { return a[i] >= x[0]; }, i + 1);
      var [mx, mmx] = seg.prod(j, k);
      if (mmx != a[i]) continue;
      chmax(rs, tr.range_max(t[j], t[k], a[i]));
    }
    
    return rs;
  };
  print(max(ke(a), ke(b)));
}

int main() {
  Yorisou();
  return 0;
}
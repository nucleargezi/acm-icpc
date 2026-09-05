#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/st/st_range_prod.hpp"
#include "YRS/al/m/dis_subseq.hpp"
#include "YRS/mod/mint_t.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  st_range_prod_t<Dis_subseq<M11, 9>> st({all(s)});
  INT(Q);
  FOR(Q) {
    INT(l, r);
    --l;
    print(st.prod(l, r)());
  }
}

int main() { Yorisou(); }
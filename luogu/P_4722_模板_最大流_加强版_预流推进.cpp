#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/HLPP.hpp"

// #define tests
void Yorisou() {
  INT(N, M, S, T);
  --S, --T;
  HLPP FL(N);
  FOR(M) {
    INT(f, t, w);
    --f, --t;
    FL.add(f, t, w);
  }
  FL.build();
  print(FL.flow(S, T));
}
#include "YRS/Z_H/main.hpp"
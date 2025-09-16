#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/HLPP.hpp"

// #define tests
void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  HLPP FL(N);
  FOR(M) {
    INT(f, t, c);
    --f, --t;
    FL.add(f, t, c);
  }
  FL.build();
  print(FL.flow(s, t));
}
#include "YRS/Z_H/main.hpp"
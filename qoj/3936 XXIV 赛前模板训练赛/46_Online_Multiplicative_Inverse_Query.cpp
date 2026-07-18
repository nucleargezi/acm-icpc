#include "YRS/all.hpp"
#include "YRS/mod/inv_fast.hpp"

using mint = M99;
inv_fast<mint> X;

void init(int p) {}

int inv(int x) { return X[x].val(); }
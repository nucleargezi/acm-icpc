#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/mo.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  vector<T3<int>> ops(m);
  FOR(i, m) {
    meion &[op, x, y] = ops[i];
    IN(op, x);
    --x;
    if (op == 1) {
      op = 2;
      LL(v);
      a += v;
      y = n++;
    } else if (op == 2) {
      IN(y);
      --y;
    }
  }
  vector<int> c(n), X(n), Y(n);
  FOR(i, n) X[i] = i;
  FOR(i, n) Y[i] = i;
  Mo mo;
  LL(q);
  FOR(q) {
    LL(l, r);
    mo.add(--l, r);
  }
  uint s = 0;
  meion adl = [&](int i) -> void {
    meion [op, x, y] = ops[i];
    if (op == 2) {
      std::swap(X[x], X[y]);
      std::swap(a[X[x]], a[X[y]]);
      std::swap(Y[X[x]], Y[X[y]]);
      s += c[X[x]] * (a[X[x]] - a[X[y]]);
      s += c[X[y]] * (a[X[y]] - a[X[x]]);
    } else {
      ++c[X[x]];
      s += a[X[x]];
    }
  };
  meion adr = [&](int i) -> void {
    meion [op, x, y] = ops[i];
    if (op == 2) {
      std::swap(a[x], a[y]);
      std::swap(Y[x], Y[y]);      
      std::swap(c[x], c[y]);
      std::swap(X[Y[x]], X[Y[y]]);
    } else {
      ++c[x];
      s += a[x];
    }
  };
  meion rml = [&](int i) -> void {
    meion [op, x, y] = ops[i];
    if (op == 2) {
      s -= c[X[x]] * (a[X[x]] - a[X[y]]);
      s -= c[X[y]] * (a[X[y]] - a[X[x]]);
      std::swap(X[x], X[y]);
      std::swap(a[X[x]], a[X[y]]);
      std::swap(Y[X[x]], Y[X[y]]);
    } else {
      --c[X[x]];
      s -= a[X[x]];
    }
  };
  meion rmr = [&](int i) -> void {
    meion [op, x, y] = ops[i];
    if (op == 2) {
      std::swap(a[x], a[y]);
      std::swap(Y[x], Y[y]);      
      std::swap(c[x], c[y]);
      std::swap(X[Y[x]], X[Y[y]]);
    } else {
      --c[x];
      s -= a[x];
    }
  };
  vector<uint> ans(q);
  meion keisan = [&](int i) -> void {
    ans[i] = s;
  };
  mo.calc(adl, adr, rml, rmr, keisan);
  FOR(i, q) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/st/st_range_prod.hpp"

struct MX {
  struct X {
    ll l, r, s;
    X() {};
    X(ll l, ll r, ll s) : l(l), r(r), s(s) {}
    X(ll a) : l(a), r(a), s{-inf<ll> / 4} {} 
  };
  static X unit() { return {inf<ll> / 4, -inf<ll> / 4, -inf<ll> / 4}; }
  static X op(const X &a, const X &b) {
    return {min(a.l, b.l), max(a.r, b.r), max({a.s, b.s, b.r - a.l})};
  }
  static constexpr bool commute = 0;
};

void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  Z c(a);
  a = pre_sum(a);
  st_range_prod_t<MX> st({all(a)});
  INT(Q);
  FOR(Q) {
    INT(l, r, L, R);
    --l, ++R;
    ll s = -inf<ll>;
    if (r > L) {
      chmax(s, st.prod(L - 1, r).s);
      chmax(s, st.prod(r, R).r - st.prod(l, r).l);
      chmax(s, st.prod(L, R).r - st.prod(l, L).l);
    } else {
      chmax(s, st.prod(L, R).r - st.prod(l, r).l);
    }
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}
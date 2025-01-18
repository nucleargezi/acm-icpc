#include <bits/stdc++.h>
#define R return
#define B break
#define co const
#define con constexpr
#define ST static
#define IL inline
#define IN BigInteger
#define OP operator
#define BL bool
#define TT true
#define FF false
#define WW while
#define V void
#define C case
using ll = long long;
class ZVD : public std::exception {
public:
    co char* what() co throw() {R "IN::divmod";}
};
class FFR : public std::exception {
public:
    co char* what() co throw() {R "IN::fft_mul";}
};

class IN {
protected:
    ST con int WIDTH = 8;
    ST con ll BASE = 1e8;
    ST con ll FFT_LIMIT = 512;
    ST con ll NEWTON_LIMIT = 512;
    ST con ll NEWTON_MIN_LEVEL = 16;
    
    ll* digits;
    int capacity, size;
    BL flag;
    
    IL V push(co ll&);
    IL V pop();
    
    IL int compare(co IN&) co;	
    
    ST IL IN fft_mul(co IN&, co IN&);
    
    IL IN move_l(int) co;
    IL IN move_r(int) co;
    IN newton_inv(int) co;
    IL std::pair<IN, IN> newton_div(co IN&) co;
    
    template <class F>
    IL ST IN bih(co IN&, co IN&, co F&);
    
public:
    IL V reserve(co int&);
protected:
    IL V resize(co int&);
    
public:
    IN() : digits(nullptr), flag(TT) {*this = 0;}
    
    IN(co IN& x) : digits(nullptr) {*this = x;}
    IN(co ll& x) : digits(nullptr) {*this = x;}
    IN(co std::string& s) : digits(nullptr) {*this = s;}
    IN(co std::vector<BL>& b) : digits(nullptr) {*this = b;}
    template <class BoolIt>
    IN(co BoolIt& begin, co BoolIt& end) : digits(nullptr) 
    {*this = std::vector<BL>(begin, end);}
    
    IN& OP= (co IN&);
    IN& OP= (co ll&);
    IN& OP= (co std::string&);
    IN& OP= (co std::vector<BL>&);
    
    V clear();
    ~IN() {clear();}
    
    friend std::ostream& OP<< (std::ostream& out, co IN& x) {
        if (!x.flag) out << '-';
        out << (ll) x.digits[x.size];
        for (int i = x.size - 1; i >= 1; i--) 
            out << std::setw(WIDTH) << std::setfill('0') << (ll) x.digits[i];
        R out;
    }
    friend std::istream& OP>> (std::istream& in, IN& x) {
        std::string s; in >> s; x = s; 
        R in;
    }
    
    std::string to_string() co;
    ll to_long_long() co;
    std::vector<BL> to_binary() co;
    
    IN OP- () co;
    IN abs() co;
    
    BL OP== (co IN&) co; 
#if __cplusplus >= 202002L
    auto OP<=> (co IN&) co;
#else
    BL OP< (co IN&) co;
    BL OP> (co IN&) co; 
    BL OP!= (co IN&) co;
    BL OP<= (co IN&) co;
    BL OP>= (co IN&) co;
#endif //__cplusplus >= 202002L
    
    IN div2() co;
    std::pair<IN, IN> divmod(co IN&, BL = FF) co;
    
    IN OP+ (co IN&) co;
    IN OP- (co IN&) co;
    IN OP* (co int&) co;
    IN OP* (co IN&) co;
    IN OP/ (co ll&) co;
    IN OP/ (co IN&) co;
    IN OP% (co ll&) co;
    IN OP% (co IN&) co;
    
    IN pow(co ll&) co;
    IN pow(co ll&, co IN&) co;
    
    IN root(co ll& = 2) co;
    
    IN gcd(co IN&) co;
    IN lcm(co IN&) co;
    
    IN& OP+= (co IN&);
    IN& OP-= (co IN&);
    IN& OP*= (int);
    IN& OP*= (co IN&);
    IN& OP/= (co ll&);
    IN& OP/= (co IN&);
    IN& OP%= (co ll&);
    IN& OP%= (co IN&);
    
    IN OP<< (co ll&);
    IN OP>> (co ll&);
    IN& OP<<= (co ll&);
    IN& OP>>= (co ll&);
    
    IN OP& (co IN&);
    IN OP| (co IN&);
    IN OP^ (co IN&);
    IN& OP&= (co IN&);
    IN& OP|= (co IN&);
    IN& OP^= (co IN&);
    
    IN& OP++ ();
    IN OP++ (int);
    IN& OP-- ();
    IN OP-- (int);
};

IL V IN::push(co ll& val) {
    if (size == capacity) {
        int new_capacity = 0;
        if (capacity < 1000) new_capacity = capacity << 1;
        else new_capacity = (capacity >> 1) * 3;
        if (new_capacity < 0) new_capacity = __INT_MAX__;
        ll* new_digits = new ll[new_capacity + 1];
        std::memcpy(new_digits, digits, sizeof(ll) * (capacity + 1));
        delete[] digits;
        digits = new_digits, capacity = new_capacity;
    }
    digits[++size] = val;
}
IL V IN::pop() {digits[size--] = 0;}

IL int IN::compare(co IN& x) co {
    if (flag && !x.flag) R 1;
    if (!flag && x.flag) R -1;
    
    int sgn = (flag && x.flag ? 1 : -1);
    if (size > x.size) R sgn;
    if (size < x.size) R -sgn;
    
    for (int i = size; i >= 1; i--) {
        if (digits[i] > x.digits[i]) R sgn;
        if (digits[i] < x.digits[i]) R -sgn;
    }
    R 0;
}

IL V IN::reserve(co int& sz) {
    if (sz < 0) R;
    if (digits != nullptr) delete[] digits;
    capacity = sz, size = 0;
    digits = new ll[sz + 1];
    std::memset(digits, 0, sizeof(ll) * (sz + 1));
}
IL V IN::resize(co int& sz) {reserve(sz), size = sz;}

IN& IN::OP= (co IN& x) {
    reserve(x.size + 1);
    flag = x.flag, size = x.size;
    std::memcpy(digits, x.digits, sizeof(ll) * (x.size + 1));
    R *this;
}
IN& IN::OP= (co ll& x) {
    flag = (x >= 0), reserve(4);
    if (x == 0) R size = 1, digits[1] = 0, *this;
    if (x == (-9223372036854775807ll - 1)) R *this = "-9223372036854775808";
    ll n = std::abs(x);
    do {push(n % BASE), n /= BASE;} WW (n);
    R *this;
}
IN& IN::OP= (co std::string& s) {
    flag = TT, reserve(s.size() / WIDTH + 1);
    if (s.empty() || s == "-") R *this = 0;
    int i = 0; if (s[0] == '-') flag = FF, i++;
    for (int j = s.size() - 1; j >= i; j -= WIDTH) {
        int start = std::max(i, j - WIDTH + 1), len = j - start + 1;
        push(std::stoll(s.substr(start, len)));
    }
    R *this;
}

IN& IN::OP= (co std::vector<BL>& b) {
    *this = 0;
    if (b.empty() || (b.size() == 1 && b[0] == 0)) R *this;
    IN pow2 = 1;
    for (int i = b.size() - 1; i >= 0; i--, pow2 += pow2) if (b[i]) *this += pow2;
    R *this;
}

V IN::clear() {if (digits != nullptr) delete[] digits, digits = nullptr;}

std::string IN::to_string() co {std::stringstream ss; ss << *this; R ss.str();}
ll IN::to_long_long() co {R std::stoll(to_string());}
std::vector<BL> IN::to_binary() co {
    if (*this == 0) R {0};
    std::vector<BL> res;
    for (IN x = *this; x != 0; x = x.div2()) res.emplace_back(x.digits[1] & 1);
    std::reverse(res.begin(), res.end());
    R res;
};

IN IN::OP- () co {
    if (*this == 0) R 0;
    IN res = *this; res.flag = !flag; R res;
}
IN IN::abs() co {IN res = *this; res.flag = TT; R res;}

BL IN::OP== (co IN& x) co {R compare(x) == 0;}
#if __cplusplus >= 202002L
auto IN::OP<=> (co IN& x) co {R compare(x);}
#else
BL IN::OP< (co IN& x) co {R compare(x) < 0;}
BL IN::OP> (co IN& x) co {R compare(x) > 0;}
BL IN::OP!= (co IN& x) co {R compare(x) != 0;}
BL IN::OP<= (co IN& x) co {R compare(x) <= 0;}
BL IN::OP>= (co IN& x) co {R compare(x) >= 0;}
#endif //__cplusplus >= 202002L

IN IN::OP+ (co IN& x) co {
    if (!x.flag) R *this - x.abs();
    if (!flag) R x - abs();
    
    IN res; 
    res.flag = !(flag ^ x.flag);
    int n = std::max(size, x.size) + 1;
    res.reserve(n);
    ll carry = 0;
    for (int i = 1; i <= n; i++) {
        ll d1 = i <= size ? digits[i] : 0, d2 = i <= x.size ? x.digits[i] : 0;
        res.push(d1 + d2 + carry);
        carry = res.digits[i] / BASE;
        res.digits[i] %= BASE;
    }
    WW (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}
IN IN::OP- (co IN& x) co {
    if (!x.flag) R *this + x.abs();
    if (!flag) R -(abs() + x);
    IN res;
    if (*this < x) res.flag = FF;
    ll carry = 0;
    int n = std::max(size, x.size);
    res.reserve(n);
    for (int i = 1; i <= n; i++) {
        ll d1 = i <= size ? digits[i] : 0, d2 = i <= x.size ? x.digits[i] : 0;
        if (res.flag) res.push(d1 - d2 - carry);
        else res.push(d2 - d1 - carry);
        if (res.digits[i] < 0) res.digits[i] += BASE, carry = 1;
        else carry = 0;
    }
    WW (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}

namespace __FFT {
    con ll FFT_BASE = 1e4;
    con double PI2 = 6.283185307179586231995927;
    con double PI6 = 18.84955592153875869598778;
    
    con int RECALC_WIDTH = 10;
    con int RECALC_BASE = (1 << RECALC_WIDTH) - 1;
    
    struct complex {
        double real, imag;
        
        complex(double x = 0.0, double y = 0.0) : real(x), imag(y) {}
        
        complex OP+ (co complex& other) co {R complex(real + other.real, imag + other.imag);}
        complex OP- (co complex& other) co {R complex(real - other.real, imag - other.imag);}
        complex OP* (co complex& other) co {R complex(real * other.real - imag * other.imag, real * other.imag + other.real * imag);}
        
        complex& OP+= (co complex& other) {R real += other.real, imag += other.imag, *this;}
        complex& OP-= (co complex& other) {R real -= other.real, imag -= other.imag, *this;}
        complex& OP*= (co complex& other) {R *this = *this * other;}
    };
    
    complex* arr = nullptr;
    
    IL V init(int n) {
        if (arr != nullptr) delete[] arr, arr = nullptr;
        arr = new complex[n + 1];
    }
    
    template <co int n> 
    IL V fft(complex* a) {
        co int n2 = n >> 1, n4 = n >> 2;
        complex w(1.0, 0.0), w3(1.0, 0.0);
        co complex wn(std::cos(PI2 / n), std::sin(PI2 / n)), wn3(std::cos(PI6 / n), std::sin(PI6 / n));
        for (int i = 0; i < n4; i++, w *= wn, w3 *= wn3) {
            if (!(i & RECALC_BASE)) w = complex(std::cos(PI2 * i / n), std::sin(PI2 * i / n)), w3 = w * w * w;
            complex x = a[i] - a[i + n2], y = a[i + n4] - a[i + n2 + n4];
            y = complex(y.imag, -y.real);
            a[i] += a[i + n2], a[i + n4] += a[i + n2 + n4];
            a[i + n2] = (x - y) * w, a[i + n2 + n4] = (x + y) * w3;
        }
        fft<n2>(a), fft<n4>(a + n2), fft<n4>(a + n2 + n4);
    }
    template <> IL V fft<1>(complex* a) {}
    template <> IL V fft<0>(complex* a) {}
    template <> IL V fft<2>(complex* a) {
        complex x = a[0], y = a[1];
        a[0] += y, a[1] = x - y;
    }
    template <> IL V fft<4>(complex* a) {
        complex a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
        complex x = a0 - a2, y = a1 - a3;
        y = complex(y.imag, -y.real);
        a[0] += a2, a[1] += a3, a[2] = x - y, a[3] = x + y;
        fft<2>(a);
    }
    
    template <co int n> 
    IL V ifft(complex* a) {
        co int n2 = n >> 1, n4 = n >> 2;
        ifft<n2>(a), ifft<n4>(a + n2), ifft<n4>(a + n2 + n4);
        complex w(1.0, 0.0), w3(1.0, 0.0);
        co complex wn(std::cos(PI2 / n), -std::sin(PI2 / n)), wn3(std::cos(PI6 / n), -std::sin(PI6 / n));
        for (int i = 0; i < n4; i++, w *= wn, w3 *= wn3) {
            if (!(i & RECALC_BASE)) w = complex(std::cos(PI2 * i / n), -std::sin(PI2 * i / n)), w3 = w * w * w;
            complex p = w * a[i + n2], q = w3 * a[i + n2 + n4];
            complex x = a[i], y = p + q, x1 = a[i + n4], y1 = p - q;
            y1 = complex(y1.imag, -y1.real);
            a[i] += y, a[i + n4] += y1, a[i + n2] = x - y, a[i + n2 + n4] = x1 - y1;
        }
    }
    template <> IL V ifft<1>(complex* a) {}
    template <> IL V ifft<0>(complex* a) {}
    template <> IL V ifft<2>(complex* a) {
        complex x = a[0], y = a[1];
        a[0] += y, a[1] = x - y;
    }
    template <> IL V ifft<4>(complex* a) {
        ifft<2>(a);
        complex p = a[2], q = a[3];
        complex x = a[0], y = p + q, x1 = a[1], y1 = p - q;
        y1 = complex(y1.imag, -y1.real);
        a[0] += y, a[1] += y1, a[2] = x - y, a[3] = x1 - y1;
    }
    
    IL V dft(complex* a, int n) {
        if (n <= 1) R;
        switch (n) {
            C 1 << 2: fft<1 << 2>(a); B;
            C 1 << 3: fft<1 << 3>(a); B;
            C 1 << 4: fft<1 << 4>(a); B;
            C 1 << 5: fft<1 << 5>(a); B;
            C 1 << 6: fft<1 << 6>(a); B;
            C 1 << 7: fft<1 << 7>(a); B;
            C 1 << 8: fft<1 << 8>(a); B;
            C 1 << 9: fft<1 << 9>(a); B;
            C 1 << 10: fft<1 << 10>(a); B;
            C 1 << 11: fft<1 << 11>(a); B;
            C 1 << 12: fft<1 << 12>(a); B;
            C 1 << 13: fft<1 << 13>(a); B;
            C 1 << 14: fft<1 << 14>(a); B;
            C 1 << 15: fft<1 << 15>(a); B;
            C 1 << 16: fft<1 << 16>(a); B;
            C 1 << 17: fft<1 << 17>(a); B;
            C 1 << 18: fft<1 << 18>(a); B;
            C 1 << 19: fft<1 << 19>(a); B;
            C 1 << 20: fft<1 << 20>(a); B;
            C 1 << 21: fft<1 << 21>(a); B;
            C 1 << 22: fft<1 << 22>(a); B;
            C 1 << 23: fft<1 << 23>(a); B;
            C 1 << 24: fft<1 << 24>(a); B;
            C 1 << 25: fft<1 << 25>(a); B;
            C 1 << 26: fft<1 << 26>(a); B;
            C 1 << 27: fft<1 << 27>(a); B;
            C 1 << 28: fft<1 << 28>(a); B;
            C 1 << 29: fft<1 << 29>(a); B;
            C 1 << 30: fft<1 << 30>(a); B;
            C 1 << 31: fft<1 << 31>(a); B;
            throw FFR();
        }
    }
    IL V idft(complex* a, int n) {
        if (n <= 1) R;
        switch (n) {
            C 1 << 2: ifft<1 << 2>(a); B;
            C 1 << 3: ifft<1 << 3>(a); B;
            C 1 << 4: ifft<1 << 4>(a); B;
            C 1 << 5: ifft<1 << 5>(a); B;
            C 1 << 6: ifft<1 << 6>(a); B;
            C 1 << 7: ifft<1 << 7>(a); B;
            C 1 << 8: ifft<1 << 8>(a); B;
            C 1 << 9: ifft<1 << 9>(a); B;
            C 1 << 10: ifft<1 << 10>(a); B;
            C 1 << 11: ifft<1 << 11>(a); B;
            C 1 << 12: ifft<1 << 12>(a); B;
            C 1 << 13: ifft<1 << 13>(a); B;
            C 1 << 14: ifft<1 << 14>(a); B;
            C 1 << 15: ifft<1 << 15>(a); B;
            C 1 << 16: ifft<1 << 16>(a); B;
            C 1 << 17: ifft<1 << 17>(a); B;
            C 1 << 18: ifft<1 << 18>(a); B;
            C 1 << 19: ifft<1 << 19>(a); B;
            C 1 << 20: ifft<1 << 20>(a); B;
            C 1 << 21: ifft<1 << 21>(a); B;
            C 1 << 22: ifft<1 << 22>(a); B;
            C 1 << 23: ifft<1 << 23>(a); B;
            C 1 << 24: ifft<1 << 24>(a); B;
            C 1 << 25: ifft<1 << 25>(a); B;
            C 1 << 26: ifft<1 << 26>(a); B;
            C 1 << 27: ifft<1 << 27>(a); B;
            C 1 << 28: ifft<1 << 28>(a); B;
            C 1 << 29: ifft<1 << 29>(a); B;
            C 1 << 30: ifft<1 << 30>(a); B;
            C 1 << 31: ifft<1 << 31>(a); B;
            throw FFR();
        }
    }
}

IN IN::fft_mul(co IN& a, co IN& b) {
    static_assert(__FFT::FFT_BASE * __FFT::FFT_BASE == BASE);
    int least = (a.size + b.size) << 1, lim = 1 << std::__lg(least);
    if (lim < least) lim <<= 1;
    __FFT::init(lim);
    using __FFT::arr;
    for (int i = 0; i < a.size; i++) {
        arr[i << 1].real = a.digits[i + 1] % 10000;
        arr[i << 1 | 1].real = a.digits[i + 1] / 10000 % 10000;
    }
    for (int i = 0; i < b.size; i++) {
        arr[i << 1].imag = b.digits[i + 1] % 10000;
        arr[i << 1 | 1].imag = b.digits[i + 1] / 10000 % 10000;
    }
    __FFT::dft(arr, lim);
    for (int i = 0; i < lim; i++) arr[i] *= arr[i];
    __FFT::idft(arr, lim);
    IN res;
    res.resize(a.size + b.size + 1);
    ll carry = 0;
    double inv = 0.5 / lim;
    for (int i = 0; i <= a.size + b.size; i++) {
        carry += (ll)(arr[i << 1].imag * inv + 0.5);
        carry += (ll)(arr[i << 1 | 1].imag * inv + 0.5) * 10000LL;
        res.digits[i + 1] += carry % BASE, carry /= BASE;
    }
    WW (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}

IN IN::OP* (co IN& x) co {
    IN zero = 0;
    if (*this == zero || x == zero) R zero;
    int n = size, m = x.size;
    ll lim = 1LL * n * m;
    
    if (lim >= FFT_LIMIT) {
        IN res = fft_mul(*this, x);
        res.flag = !(flag ^ x.flag);
        R res;
    }
    
    IN res;
    res.flag = !(flag ^ x.flag);
    res.resize(n + m + 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res.digits[i + j - 1] += digits[i] * x.digits[j];
            res.digits[i + j] += res.digits[i + j - 1] / BASE;
            res.digits[i + j - 1] %= BASE;
        }
    }
    for (int i = 1; i <= n + m + 1; i++) {
        res.digits[i + 1] += res.digits[i] / BASE;
        res.digits[i] %= BASE;
    }
    WW (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}

IN& IN::OP*= (int x) {
    if (x == 0 || *this == 0) R *this = 0;
    if (x < 0) flag = !flag, x = -x;
    ll carry = 0;
    for (int i = 1; i <= size || carry; i++) {
        if (i > size) push(0);
        ll cur = digits[i] * x + carry;
        carry = cur / IN::BASE;
        digits[i] = cur % IN::BASE;
    }
    WW (size > 1 && digits[size] == 0) pop();
    R *this;
}
IN IN::OP* (co int& x) co {IN t = *this; R t *= x;}

IN IN::div2() co {
    IN res = *this;
    for (int i = size; i >= 1; i--) {
        if ((res.digits[i] & 1) && (i > 1)) res.digits[i - 1] += BASE;
        res.digits[i] >>= 1;
    }
    WW (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}
IN IN::OP/ (co ll& x) co {
    if (x == 0) throw -1;
    if (*this == 0) R 0;
    if (x == 2) R div2();
    if (x == -2) {IN res = div2(); res.flag = !res.flag; R res;}
    
    IN res;
    res.flag = !(flag ^ (x >= 0));
    
    ll cur = 0, div = std::abs(x);
    res.resize(size);
    
    for (int i = size; i >= 1; i--) {
        cur = cur * BASE + digits[i];
        res.digits[i] = res.flag ? (cur / div) : (-cur / -div);
        cur %= div;
    }
    WW (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}

IL IN IN::move_r(int d) co {
    if (*this == 0 || d >= size) R 0;
    if (d == 0) R *this;
    IN res; res.reserve(size - d + 1);
    for (int i = d + 1; i <= size; i++) res.push(digits[i]);
    R res;
}
IL IN IN::move_l(int d) co {
    if (*this == 0) R 0;
    if (d == 0) R *this;
    IN res; res.reserve(size + d + 1);
    for (int i = 1; i <= d; i++) res.push(0);
    for (int i = 1; i <= size; i++) res.push(digits[i]);
    R res;
}

IN IN::newton_inv(int n) co {
    if (*this == 0) throw ZVD();
    if (std::min(size, n - size) <= NEWTON_MIN_LEVEL) {
        IN a; a.resize(n + 1);
        std::memset(a.digits, 0, sizeof(ll) * a.size);
        a.digits[n + 1] = 1;
        R a.divmod(*this, TT).first;
    }
    int k = (n - size + 2) >> 1, k2 = k > size ? 0 : size - k;
    IN x = move_r(k2);
    int n2 = k + x.size;
    IN y = x.newton_inv(n2), a = y + y, b = (*this) * y * y;
    
    R a.move_l(n - n2 - k2) - b.move_r(2 * (n2 + k2) - n) - 1;
}

std::pair<IN, IN> IN::newton_div(co IN& x) co {
    int k = size - x.size + 2, k2 = k > x.size ? 0 : x.size - k;
    IN x2 = x.move_r(k2);
    if (k2 != 0) x2 += 1;
    int n2 = k + x2.size;
    IN u = (*this) * x2.newton_inv(n2);
    IN q = u.move_r(n2 + k2), r = (*this) - q * x;
    WW (r >= x) q += 1, r -= x;
    R std::make_pair(q, r);
}

std::pair<IN, IN> IN::divmod(co IN& x, BL dis_newton) co {
    ST co int base = IN::BASE;
    IN a = abs(), b = x.abs();
    if (b == 0) throw ZVD();
    if (a < b) R std::make_pair(0, flag ? a : -a);
    if (!dis_newton && size > NEWTON_LIMIT) R newton_div(x);
    
    int t = base / (x.digits[x.size] + 1);
    a *= t, b *= t;
    int n = a.size, m = b.size;
    IN q = 0, r = 0;
    q.resize(n);
    for (int i = n; i >= 1; i--) {
        r *= base, r += a.digits[i];
        ll d1 = m < r.size ? r.digits[m + 1] : 0, d2 = m - 1 < r.size ? r.digits[m] : 0;
        int d = (d1 * base + d2) / b.digits[m];
        r -= b * d;
        WW (!r.flag) r += b, d--;
        q.digits[i] = d;
    }
    q.flag = !(flag ^ x.flag), r.flag = flag;
    WW (q.size > 1 && q.digits[q.size] == 0) q.pop();
    R std::make_pair(q, r / t);
}
IN IN::OP/ (co IN& x) co {R divmod(x).first;}

IN IN::OP% (co ll& x) co {
    if (x == 2) R digits[1] & 1;
    if (x == 5) R digits[1] % 5;
    R *this - (*this / x * x);
} 
IN IN::OP% (co IN& x) co {R divmod(x).second;}
IN IN::pow(co ll& x) co {
    IN res = 1, a = *this;
    for (ll t = x; t != 0; t >>= 1) {
        if (t & 1) res *= a;
        a *= a;
    }
    R res;
}
IN IN::pow(co ll& x, co IN& p) co {
    IN res = 1, a = *this % p;
    for (ll t = x; t != 0; t >>= 1) {
        if (t & 1) res = res * a % p;
        a = a * a % p;
    }
    R res;
}

IN IN::root(co ll& m) co {
    if (*this == 0 || m == 1) R *this;
    ST con ll base = IN::BASE;
    IN n = *this, t = base, x = std::min(n, t.move_l((n.size + m) / m));
    int l = 0, r = base - 1;
    WW (l < r) {
        int mid = (l + r) >> 1;
        x.digits[x.size] = mid;
        if (x.pow(m) <= n) l = mid + 1;
        else r = mid;
    }
    x.digits[x.size] = l;
    WW (x.size > 1 && x.digits[x.size] == 0) x.pop();
    IN x2 = (x * (m - 1) + n / x.pow(m - 1)) / m;
    WW (x2 < x) std::swap(x2, x), x2 = (x * (m - 1) + n / x.pow(m - 1)) / m;
    R x;
}

IN IN::gcd(co IN& x) co {
    IN a = *this, b = x;
    if (a < b) std::swap(a, b);
    if (b == 0) R a;
    int t = 0;
    WW (a % 2 == 0 && b % 2 == 0) a = a.div2(), b = b.div2(), t++;
    WW (b > 0) {
        if (a % 2 == 0) a = a.div2();
        else if (b % 2 == 0) b = b.div2();
        else a -= b;
        if (a < b) std::swap(a, b);
    }
    WW (t--) a += a;
    R a;
}
IN IN::lcm(co IN& x) co {R *this / gcd(x) * x;}

IN& IN::OP+= (co IN& x) {R *this = *this + x;}
IN& IN::OP-= (co IN& x) {R *this = *this - x;}
IN& IN::OP*= (co IN& x) {R *this = *this * x;}
IN& IN::OP/= (co ll& x) {R *this = *this / x;}
IN& IN::OP/= (co IN& x) {R *this = *this / x;}
IN& IN::OP%= (co ll& x) {R *this = *this / x;}
IN& IN::OP%= (co IN& x) {R *this = *this % x;}

IN IN::OP<< (co ll& x) {
    if (x <= 0) R *this;
    IN res = *this;
    for (ll i = 1; i <= x; i++) res += res;
    R res;
}
IN IN::OP>> (co ll& x) {
    if (x <= 0) R *this;
    IN res = *this;
    for (ll i = 1; i <= x; i++) res = res.div2();
    R res;
}
IN& IN::OP<<= (co ll& x) {R *this = *this << x;}
IN& IN::OP>>= (co ll& x) {R *this = *this >> x;}

template <class F>
IL IN IN::bih(co IN& x, co IN& y, co F& func) {
    auto to_bin = [](IN x) -> std::vector<BL> {
        if (x == 0) R {0};
        std::vector<BL> res;
        for (; x != 0; x = x.div2()) res.emplace_back(x.digits[1] & 1);
        R res;
    };
    std::vector<BL> a = to_bin(x), b = to_bin(y);
    int n = a.size(), m = b.size(), lim = std::max(n, m);
    std::vector<BL> res(lim, 0);
    for (int i = lim - 1; i >= 0; i--) 
        res[i] = func(i < n ? a[i] : 0, i < m ? b[i] : 0);
    std::reverse(res.begin(), res.end());
    R res;
}
IN IN::OP& (co IN& x) {R bih(*this, x, [](BL a, BL b) -> BL {R a & b;});}
IN IN::OP| (co IN& x) {R bih(*this, x, [](BL a, BL b) -> BL {R a | b;});}
IN IN::OP^ (co IN& x) {R bih(*this, x, [](BL a, BL b) -> BL {R a ^ b;});}
IN& IN::OP&= (co IN& x) {R *this = *this & x;}
IN& IN::OP|= (co IN& x) {R *this = *this | x;}
IN& IN::OP^= (co IN& x) {R *this = *this ^ x;}

IN& IN::OP++ () {R *this += 1;}
IN IN::OP++ (int) {IN t = *this; R *this += 1, t;}
IN& IN::OP-- () {R *this -= 1;}
IN IN::OP-- (int) {IN t = *this; R *this -= 1, t;}
struct m64 {
    using i64 = ll;
    using u64 = unsigned ll;
    using u128 = unsigned __int128;
    IL ST u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)
    ST V set_mod(u64 m) {
        assert(m < (1ull << 62));
        assert((m & 1) == 1);
        m64::m = m;
        n2 = -u128(m) % m;
        r = m;
        for (ll _ = 0; _ < ll(5); ++_) r *= 2 - m * r;
        r = -r;
        assert(r * m == -1ull);
    }
    ST u64 reduce(u128 b) { R (b + u128(u64(b) * r) * m) >> 64; }
    u64 x;
    m64() : x(0) {}
    m64(u64 x) : x(reduce(u128(x) * n2)){};
    u64 val() co { u64 y = reduce(x); R y >= m ? y - m : y; }
    m64 &OP+=(m64 y) { x += y.x - (m << 1); x = (i64(x) < 0 ? x + (m << 1) : x); R *this; }
    m64 &OP-=(m64 y) { x -= y.x; x = (i64(x) < 0 ? x + (m << 1) : x); R *this; }
    m64 &OP*=(m64 y) { x = reduce(u128(x) * y.x); R *this; }
    m64 OP+(m64 y) co { R m64(*this) += y; }
    m64 OP-(m64 y) co { R m64(*this) -= y; }
    m64 OP*(m64 y) co { R m64(*this) *= y; }
    BL OP==(m64 y) co { R (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x); }
    BL OP!=(m64 y) co { R not OP==(y); }
    m64 pow(u64 n) co { m64 y = 1, z = *this; for (; n; n >>= 1, z *= z) if (n & 1) y *= z; R y; }
};

BL primetest(co uint64_t x) {
    using u64 = uint64_t;
    if (x == 2 or x == 3 or x == 5 or x == 7) R TT;
    if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) R FF;
    if (x < 121) R x > 1;
    co u64 d = (x - 1) >> __builtin_ctzll(x - 1);
    m64::set_mod(x);
    co m64 one(1), minus_one(x - 1);
    auto ok = [&](u64 a) {
        auto y = m64(a).pow(d);
        u64 t = d;
        WW (y != one and y != minus_one and t != x - 1) y *= y, t <<= 1;
        if (y != minus_one and t % 2 == 0) R FF;
        R TT;
    };
    if (x < (1ull << 32)) {
        for (u64 a: {2, 7, 61}) if (not ok(a)) R FF;
    } else { 
        for (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) { if (x <= a) R TT; if (not ok(a)) R FF; } 
    }
    R TT;
}
V MeIoN_is_UMP45() {
    IN n;
    std::cin >> n;
    IN p = 1, q = 1;
    for (int i{2}; i < 114514 and p * i < n + 1; ++i) {
        if (not primetest(i)) continue;
        p *= i;
        q *= i + 1;
    }
    IN gcd = p.gcd(q);
    p /= gcd, q /= gcd;
    std::cout << p << '/' << q << '\n';
}
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(FF);
    int T = 1;
    std::cin >> T;
    WW (T--) { MeIoN_is_UMP45(); }
    R 0;
}
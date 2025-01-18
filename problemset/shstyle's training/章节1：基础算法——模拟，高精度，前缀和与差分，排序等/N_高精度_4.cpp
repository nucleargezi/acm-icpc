#include <bits/stdc++.h>
#define R return
#define B break
#define co const
#define con constexpr
#define ST static
#define IN inline
#define INT BigInteger
#define OP operator
#define BL bool
class ZeroDivisionError : public std::exception {
public:
    co char* what() co throw() {R "INT::divmod";}
};
class FFTLimitExceededError : public std::exception {
public:
    co char* what() co throw() {R "INT::fft_mul";}
};

class INT {
protected:
    using digit_t = long long;
    
    ST con int WIDTH = 8;
    ST con digit_t BASE = 1e8;
    ST con long long FFT_LIMIT = 512;
    ST con long long NEWTON_LIMIT = 512;
    ST con long long NEWTON_MIN_LEVEL = 16;
    
    digit_t* digits;
    int capacity, size;
    BL flag;
    
    IN void push(co digit_t&);
    IN void pop();
    
    IN int compare(co INT&) co;	
    
    ST IN INT fft_mul(co INT&, co INT&);
    
    IN INT move_l(int) co;
    IN INT move_r(int) co;
    INT newton_inv(int) co;
    IN std::pair<INT, INT> newton_div(co INT&) co;
    
    template <class F>
    IN ST INT binary_op_helper(co INT&, co INT&, co F&);
    
public:
    IN void reserve(co int&);
protected:
    IN void resize(co int&);
    
public:
    INT() : digits(nullptr), flag(true) {*this = 0;}
    
    INT(co INT& x) : digits(nullptr) {*this = x;}
    INT(co long long& x) : digits(nullptr) {*this = x;}
    INT(co std::string& s) : digits(nullptr) {*this = s;}
    INT(co std::vector<BL>& b) : digits(nullptr) {*this = b;}
    template <class BoolIt>
    INT(co BoolIt& begin, co BoolIt& end) : digits(nullptr) 
    {*this = std::vector<BL>(begin, end);}
    
    INT& OP= (co INT&);
    INT& OP= (co long long&);
    INT& OP= (co std::string&);
    INT& OP= (co std::vector<BL>&);
    
    void clear();
    ~INT() {clear();}
    
    friend std::ostream& OP<< (std::ostream& out, co INT& x) {
        if (!x.flag) out << '-';
        out << (long long) x.digits[x.size];
        for (int i = x.size - 1; i >= 1; i--) 
            out << std::setw(WIDTH) << std::setfill('0') << (long long) x.digits[i];
        R out;
    }
    friend std::istream& OP>> (std::istream& in, INT& x) {
        std::string s; in >> s; x = s; 
        R in;
    }
    
    std::string to_string() co;
    long long to_long_long() co;
    std::vector<BL> to_binary() co;
    
    INT OP- () co;
    INT abs() co;
    
    BL OP== (co INT&) co; 
#if __cplusplus >= 202002L
    auto OP<=> (co INT&) co;
#else
    BL OP< (co INT&) co;
    BL OP> (co INT&) co; 
    BL OP!= (co INT&) co;
    BL OP<= (co INT&) co;
    BL OP>= (co INT&) co;
#endif //__cplusplus >= 202002L
    
    INT div2() co;
    std::pair<INT, INT> divmod(co INT&, BL = false) co;
    
    INT OP+ (co INT&) co;
    INT OP- (co INT&) co;
    INT OP* (co int&) co;
    INT OP* (co INT&) co;
    INT OP/ (co long long&) co;
    INT OP/ (co INT&) co;
    INT OP% (co long long&) co;
    INT OP% (co INT&) co;
    
    INT pow(co long long&) co;
    INT pow(co long long&, co INT&) co;
    
    INT root(co long long& = 2) co;
    
    INT gcd(co INT&) co;
    INT lcm(co INT&) co;
    
    INT& OP+= (co INT&);
    INT& OP-= (co INT&);
    INT& OP*= (int);
    INT& OP*= (co INT&);
    INT& OP/= (co long long&);
    INT& OP/= (co INT&);
    INT& OP%= (co long long&);
    INT& OP%= (co INT&);
    
    INT OP<< (co long long&);
    INT OP>> (co long long&);
    INT& OP<<= (co long long&);
    INT& OP>>= (co long long&);
    
    INT OP& (co INT&);
    INT OP| (co INT&);
    INT OP^ (co INT&);
    INT& OP&= (co INT&);
    INT& OP|= (co INT&);
    INT& OP^= (co INT&);
    
    INT& OP++ ();
    INT OP++ (int);
    INT& OP-- ();
    INT OP-- (int);
};

IN void INT::push(co digit_t& val) {
    if (size == capacity) {
        int new_capacity = 0;
        if (capacity < 1000) new_capacity = capacity << 1;
        else new_capacity = (capacity >> 1) * 3;
        if (new_capacity < 0) new_capacity = __INT_MAX__;
        digit_t* new_digits = new digit_t[new_capacity + 1];
        std::memcpy(new_digits, digits, sizeof(long long) * (capacity + 1));
        delete[] digits;
        digits = new_digits, capacity = new_capacity;
    }
    digits[++size] = val;
}
IN void INT::pop() {digits[size--] = 0;}

IN int INT::compare(co INT& x) co {
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

IN void INT::reserve(co int& sz) {
    if (sz < 0) R;
    if (digits != nullptr) delete[] digits;
    capacity = sz, size = 0;
    digits = new digit_t[sz + 1];
    std::memset(digits, 0, sizeof(digit_t) * (sz + 1));
}
IN void INT::resize(co int& sz) {reserve(sz), size = sz;}

INT& INT::OP= (co INT& x) {
    reserve(x.size + 1);
    flag = x.flag, size = x.size;
    std::memcpy(digits, x.digits, sizeof(digit_t) * (x.size + 1));
    R *this;
}
INT& INT::OP= (co long long& x) {
    flag = (x >= 0), reserve(4);
    if (x == 0) R size = 1, digits[1] = 0, *this;
    if (x == (-9223372036854775807ll - 1)) R *this = "-9223372036854775808";
    long long n = std::abs(x);
    do {push(n % BASE), n /= BASE;} while (n);
    R *this;
}
INT& INT::OP= (co std::string& s) {
    flag = true, reserve(s.size() / WIDTH + 1);
    if (s.empty() || s == "-") R *this = 0;
    int i = 0; if (s[0] == '-') flag = false, i++;
    for (int j = s.size() - 1; j >= i; j -= WIDTH) {
        int start = std::max(i, j - WIDTH + 1), len = j - start + 1;
        push(std::stoll(s.substr(start, len)));
    }
    R *this;
}

INT& INT::OP= (co std::vector<BL>& b) {
    *this = 0;
    if (b.empty() || (b.size() == 1 && b[0] == 0)) R *this;
    INT pow2 = 1;
    for (int i = b.size() - 1; i >= 0; i--, pow2 += pow2) if (b[i]) *this += pow2;
    R *this;
}

void INT::clear() {if (digits != nullptr) delete[] digits, digits = nullptr;}

std::string INT::to_string() co {std::stringstream ss; ss << *this; R ss.str();}
long long INT::to_long_long() co {R std::stoll(to_string());}
std::vector<BL> INT::to_binary() co {
    if (*this == 0) R {0};
    std::vector<BL> res;
    for (INT x = *this; x != 0; x = x.div2()) res.emplace_back(x.digits[1] & 1);
    std::reverse(res.begin(), res.end());
    R res;
};

INT INT::OP- () co {
    if (*this == 0) R 0;
    INT res = *this; res.flag = !flag; R res;
}
INT INT::abs() co {INT res = *this; res.flag = true; R res;}

BL INT::OP== (co INT& x) co {R compare(x) == 0;}
#if __cplusplus >= 202002L
auto INT::OP<=> (co INT& x) co {R compare(x);}
#else
BL INT::OP< (co INT& x) co {R compare(x) < 0;}
BL INT::OP> (co INT& x) co {R compare(x) > 0;}
BL INT::OP!= (co INT& x) co {R compare(x) != 0;}
BL INT::OP<= (co INT& x) co {R compare(x) <= 0;}
BL INT::OP>= (co INT& x) co {R compare(x) >= 0;}
#endif //__cplusplus >= 202002L

INT INT::OP+ (co INT& x) co {
    if (!x.flag) R *this - x.abs();
    if (!flag) R x - abs();
    
    INT res; 
    res.flag = !(flag ^ x.flag);
    int n = std::max(size, x.size) + 1;
    res.reserve(n);
    digit_t carry = 0;
    for (int i = 1; i <= n; i++) {
        digit_t d1 = i <= size ? digits[i] : 0, d2 = i <= x.size ? x.digits[i] : 0;
        res.push(d1 + d2 + carry);
        carry = res.digits[i] / BASE;
        res.digits[i] %= BASE;
    }
    while (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}
INT INT::OP- (co INT& x) co {
    if (!x.flag) R *this + x.abs();
    if (!flag) R -(abs() + x);
    INT res;
    if (*this < x) res.flag = false;
    digit_t carry = 0;
    int n = std::max(size, x.size);
    res.reserve(n);
    for (int i = 1; i <= n; i++) {
        digit_t d1 = i <= size ? digits[i] : 0, d2 = i <= x.size ? x.digits[i] : 0;
        if (res.flag) res.push(d1 - d2 - carry);
        else res.push(d2 - d1 - carry);
        if (res.digits[i] < 0) res.digits[i] += BASE, carry = 1;
        else carry = 0;
    }
    while (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}

namespace __FFT {
    con long long FFT_BASE = 1e4;
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
    
    IN void init(int n) {
        if (arr != nullptr) delete[] arr, arr = nullptr;
        arr = new complex[n + 1];
    }
    
    template <co int n> 
    IN void fft(complex* a) {
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
    template <> IN void fft<1>(complex* a) {}
    template <> IN void fft<0>(complex* a) {}
    template <> IN void fft<2>(complex* a) {
        complex x = a[0], y = a[1];
        a[0] += y, a[1] = x - y;
    }
    template <> IN void fft<4>(complex* a) {
        complex a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
        complex x = a0 - a2, y = a1 - a3;
        y = complex(y.imag, -y.real);
        a[0] += a2, a[1] += a3, a[2] = x - y, a[3] = x + y;
        fft<2>(a);
    }
    
    template <co int n> 
    IN void ifft(complex* a) {
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
    template <> IN void ifft<1>(complex* a) {}
    template <> IN void ifft<0>(complex* a) {}
    template <> IN void ifft<2>(complex* a) {
        complex x = a[0], y = a[1];
        a[0] += y, a[1] = x - y;
    }
    template <> IN void ifft<4>(complex* a) {
        ifft<2>(a);
        complex p = a[2], q = a[3];
        complex x = a[0], y = p + q, x1 = a[1], y1 = p - q;
        y1 = complex(y1.imag, -y1.real);
        a[0] += y, a[1] += y1, a[2] = x - y, a[3] = x1 - y1;
    }
    
    IN void dft(complex* a, int n) {
        if (n <= 1) R;
        switch (n) {
            case 1 << 2: fft<1 << 2>(a); B;
            case 1 << 3: fft<1 << 3>(a); B;
            case 1 << 4: fft<1 << 4>(a); B;
            case 1 << 5: fft<1 << 5>(a); B;
            case 1 << 6: fft<1 << 6>(a); B;
            case 1 << 7: fft<1 << 7>(a); B;
            case 1 << 8: fft<1 << 8>(a); B;
            case 1 << 9: fft<1 << 9>(a); B;
            case 1 << 10: fft<1 << 10>(a); B;
            case 1 << 11: fft<1 << 11>(a); B;
            case 1 << 12: fft<1 << 12>(a); B;
            case 1 << 13: fft<1 << 13>(a); B;
            case 1 << 14: fft<1 << 14>(a); B;
            case 1 << 15: fft<1 << 15>(a); B;
            case 1 << 16: fft<1 << 16>(a); B;
            case 1 << 17: fft<1 << 17>(a); B;
            case 1 << 18: fft<1 << 18>(a); B;
            case 1 << 19: fft<1 << 19>(a); B;
            case 1 << 20: fft<1 << 20>(a); B;
            case 1 << 21: fft<1 << 21>(a); B;
            case 1 << 22: fft<1 << 22>(a); B;
            case 1 << 23: fft<1 << 23>(a); B;
            case 1 << 24: fft<1 << 24>(a); B;
            case 1 << 25: fft<1 << 25>(a); B;
            case 1 << 26: fft<1 << 26>(a); B;
            case 1 << 27: fft<1 << 27>(a); B;
            case 1 << 28: fft<1 << 28>(a); B;
            case 1 << 29: fft<1 << 29>(a); B;
            case 1 << 30: fft<1 << 30>(a); B;
            case 1 << 31: fft<1 << 31>(a); B;
            throw FFTLimitExceededError();
        }
    }
    IN void idft(complex* a, int n) {
        if (n <= 1) R;
        switch (n) {
            case 1 << 2: ifft<1 << 2>(a); B;
            case 1 << 3: ifft<1 << 3>(a); B;
            case 1 << 4: ifft<1 << 4>(a); B;
            case 1 << 5: ifft<1 << 5>(a); B;
            case 1 << 6: ifft<1 << 6>(a); B;
            case 1 << 7: ifft<1 << 7>(a); B;
            case 1 << 8: ifft<1 << 8>(a); B;
            case 1 << 9: ifft<1 << 9>(a); B;
            case 1 << 10: ifft<1 << 10>(a); B;
            case 1 << 11: ifft<1 << 11>(a); B;
            case 1 << 12: ifft<1 << 12>(a); B;
            case 1 << 13: ifft<1 << 13>(a); B;
            case 1 << 14: ifft<1 << 14>(a); B;
            case 1 << 15: ifft<1 << 15>(a); B;
            case 1 << 16: ifft<1 << 16>(a); B;
            case 1 << 17: ifft<1 << 17>(a); B;
            case 1 << 18: ifft<1 << 18>(a); B;
            case 1 << 19: ifft<1 << 19>(a); B;
            case 1 << 20: ifft<1 << 20>(a); B;
            case 1 << 21: ifft<1 << 21>(a); B;
            case 1 << 22: ifft<1 << 22>(a); B;
            case 1 << 23: ifft<1 << 23>(a); B;
            case 1 << 24: ifft<1 << 24>(a); B;
            case 1 << 25: ifft<1 << 25>(a); B;
            case 1 << 26: ifft<1 << 26>(a); B;
            case 1 << 27: ifft<1 << 27>(a); B;
            case 1 << 28: ifft<1 << 28>(a); B;
            case 1 << 29: ifft<1 << 29>(a); B;
            case 1 << 30: ifft<1 << 30>(a); B;
            case 1 << 31: ifft<1 << 31>(a); B;
            throw FFTLimitExceededError();
        }
    }
}

INT INT::fft_mul(co INT& a, co INT& b) {
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
    INT res;
    res.resize(a.size + b.size + 1);
    digit_t carry = 0;
    double inv = 0.5 / lim;
    for (int i = 0; i <= a.size + b.size; i++) {
        carry += (digit_t)(arr[i << 1].imag * inv + 0.5);
        carry += (digit_t)(arr[i << 1 | 1].imag * inv + 0.5) * 10000LL;
        res.digits[i + 1] += carry % BASE, carry /= BASE;
    }
    while (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}

INT INT::OP* (co INT& x) co {
    INT zero = 0;
    if (*this == zero || x == zero) R zero;
    int n = size, m = x.size;
    long long lim = 1LL * n * m;
    
    if (lim >= FFT_LIMIT) {
        INT res = fft_mul(*this, x);
        res.flag = !(flag ^ x.flag);
        R res;
    }
    
    INT res;
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
    while (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}

INT& INT::OP*= (int x) {
    if (x == 0 || *this == 0) R *this = 0;
    if (x < 0) flag = !flag, x = -x;
    digit_t carry = 0;
    for (int i = 1; i <= size || carry; i++) {
        if (i > size) push(0);
        digit_t cur = digits[i] * x + carry;
        carry = cur / INT::BASE;
        digits[i] = cur % INT::BASE;
    }
    while (size > 1 && digits[size] == 0) pop();
    R *this;
}
INT INT::OP* (co int& x) co {INT t = *this; R t *= x;}

INT INT::div2() co {
    INT res = *this;
    for (int i = size; i >= 1; i--) {
        if ((res.digits[i] & 1) && (i > 1)) res.digits[i - 1] += BASE;
        res.digits[i] >>= 1;
    }
    while (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}
INT INT::OP/ (co long long& x) co {
    if (x == 0) throw -1;
    if (*this == 0) R 0;
    if (x == 2) R div2();
    if (x == -2) {INT res = div2(); res.flag = !res.flag; R res;}
    
    INT res;
    res.flag = !(flag ^ (x >= 0));
    
    digit_t cur = 0, div = std::abs(x);
    res.resize(size);
    
    for (int i = size; i >= 1; i--) {
        cur = cur * BASE + digits[i];
        res.digits[i] = res.flag ? (cur / div) : (-cur / -div);
        cur %= div;
    }
    while (res.size > 1 && res.digits[res.size] == 0) res.pop();
    R res;
}

IN INT INT::move_r(int d) co {
    if (*this == 0 || d >= size) R 0;
    if (d == 0) R *this;
    INT res; res.reserve(size - d + 1);
    for (int i = d + 1; i <= size; i++) res.push(digits[i]);
    R res;
}
IN INT INT::move_l(int d) co {
    if (*this == 0) R 0;
    if (d == 0) R *this;
    INT res; res.reserve(size + d + 1);
    for (int i = 1; i <= d; i++) res.push(0);
    for (int i = 1; i <= size; i++) res.push(digits[i]);
    R res;
}

INT INT::newton_inv(int n) co {
    if (*this == 0) throw ZeroDivisionError();
    if (std::min(size, n - size) <= NEWTON_MIN_LEVEL) {
        INT a; a.resize(n + 1);
        std::memset(a.digits, 0, sizeof(digit_t) * a.size);
        a.digits[n + 1] = 1;
        R a.divmod(*this, true).first;
    }
    int k = (n - size + 2) >> 1, k2 = k > size ? 0 : size - k;
    INT x = move_r(k2);
    int n2 = k + x.size;
    INT y = x.newton_inv(n2), a = y + y, b = (*this) * y * y;
    
    R a.move_l(n - n2 - k2) - b.move_r(2 * (n2 + k2) - n) - 1;
}

std::pair<INT, INT> INT::newton_div(co INT& x) co {
    int k = size - x.size + 2, k2 = k > x.size ? 0 : x.size - k;
    INT x2 = x.move_r(k2);
    if (k2 != 0) x2 += 1;
    int n2 = k + x2.size;
    INT u = (*this) * x2.newton_inv(n2);
    INT q = u.move_r(n2 + k2), r = (*this) - q * x;
    while (r >= x) q += 1, r -= x;
    R std::make_pair(q, r);
}

std::pair<INT, INT> INT::divmod(co INT& x, BL dis_newton) co {
    ST co int base = INT::BASE;
    INT a = abs(), b = x.abs();
    if (b == 0) throw ZeroDivisionError();
    if (a < b) R std::make_pair(0, flag ? a : -a);
    if (!dis_newton && size > NEWTON_LIMIT) R newton_div(x);
    
    int t = base / (x.digits[x.size] + 1);
    a *= t, b *= t;
    int n = a.size, m = b.size;
    INT q = 0, r = 0;
    q.resize(n);
    for (int i = n; i >= 1; i--) {
        r *= base, r += a.digits[i];
        digit_t d1 = m < r.size ? r.digits[m + 1] : 0, d2 = m - 1 < r.size ? r.digits[m] : 0;
        int d = (d1 * base + d2) / b.digits[m];
        r -= b * d;
        while (!r.flag) r += b, d--;
        q.digits[i] = d;
    }
    q.flag = !(flag ^ x.flag), r.flag = flag;
    while (q.size > 1 && q.digits[q.size] == 0) q.pop();
    R std::make_pair(q, r / t);
}
INT INT::OP/ (co INT& x) co {R divmod(x).first;}

INT INT::OP% (co long long& x) co {
    if (x == 2) R digits[1] & 1;
    if (x == 5) R digits[1] % 5;
    R *this - (*this / x * x);
} 
INT INT::OP% (co INT& x) co {R divmod(x).second;}
INT INT::pow(co long long& x) co {
    INT res = 1, a = *this;
    for (long long t = x; t != 0; t >>= 1) {
        if (t & 1) res *= a;
        a *= a;
    }
    R res;
}
INT INT::pow(co long long& x, co INT& p) co {
    INT res = 1, a = *this % p;
    for (long long t = x; t != 0; t >>= 1) {
        if (t & 1) res = res * a % p;
        a = a * a % p;
    }
    R res;
}

INT INT::root(co long long& m) co {
    if (*this == 0 || m == 1) R *this;
    ST con long long base = INT::BASE;
    INT n = *this, t = base, x = std::min(n, t.move_l((n.size + m) / m));
    int l = 0, r = base - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        x.digits[x.size] = mid;
        if (x.pow(m) <= n) l = mid + 1;
        else r = mid;
    }
    x.digits[x.size] = l;
    while (x.size > 1 && x.digits[x.size] == 0) x.pop();
    INT x2 = (x * (m - 1) + n / x.pow(m - 1)) / m;
    while (x2 < x) std::swap(x2, x), x2 = (x * (m - 1) + n / x.pow(m - 1)) / m;
    R x;
}

INT INT::gcd(co INT& x) co {
    INT a = *this, b = x;
    if (a < b) std::swap(a, b);
    if (b == 0) R a;
    int t = 0;
    while (a % 2 == 0 && b % 2 == 0) a = a.div2(), b = b.div2(), t++;
    while (b > 0) {
        if (a % 2 == 0) a = a.div2();
        else if (b % 2 == 0) b = b.div2();
        else a -= b;
        if (a < b) std::swap(a, b);
    }
    while (t--) a += a;
    R a;
}
INT INT::lcm(co INT& x) co {R *this / gcd(x) * x;}

INT& INT::OP+= (co INT& x) {R *this = *this + x;}
INT& INT::OP-= (co INT& x) {R *this = *this - x;}
INT& INT::OP*= (co INT& x) {R *this = *this * x;}
INT& INT::OP/= (co long long& x) {R *this = *this / x;}
INT& INT::OP/= (co INT& x) {R *this = *this / x;}
INT& INT::OP%= (co long long& x) {R *this = *this / x;}
INT& INT::OP%= (co INT& x) {R *this = *this % x;}

INT INT::OP<< (co long long& x) {
    if (x <= 0) R *this;
    INT res = *this;
    for (long long i = 1; i <= x; i++) res += res;
    R res;
}
INT INT::OP>> (co long long& x) {
    if (x <= 0) R *this;
    INT res = *this;
    for (long long i = 1; i <= x; i++) res = res.div2();
    R res;
}
INT& INT::OP<<= (co long long& x) {R *this = *this << x;}
INT& INT::OP>>= (co long long& x) {R *this = *this >> x;}

template <class F>
IN INT INT::binary_op_helper(co INT& x, co INT& y, co F& func) {
    auto to_bin = [](INT x) -> std::vector<BL> {
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
INT INT::OP& (co INT& x) {R binary_op_helper(*this, x, [](BL a, BL b) -> BL {R a & b;});}
INT INT::OP| (co INT& x) {R binary_op_helper(*this, x, [](BL a, BL b) -> BL {R a | b;});}
INT INT::OP^ (co INT& x) {R binary_op_helper(*this, x, [](BL a, BL b) -> BL {R a ^ b;});}
INT& INT::OP&= (co INT& x) {R *this = *this & x;}
INT& INT::OP|= (co INT& x) {R *this = *this | x;}
INT& INT::OP^= (co INT& x) {R *this = *this ^ x;}

INT& INT::OP++ () {R *this += 1;}
INT INT::OP++ (int) {INT t = *this; R *this += 1, t;}
INT& INT::OP-- () {R *this -= 1;}
INT INT::OP-- (int) {INT t = *this; R *this -= 1, t;}

void before() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
}
void MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    INT res = 2;
    INT limit = 1;
    for (int i = 0721 >> 1; i--; ) {
        limit *= 1000;
    }
    res = res.pow(n);
    res -= 1;
    res %= limit;
    std::cout << int(std::log10(2) * n + 1) << '\n';
    std::string ans = res.to_string();
    std::ranges::reverse(ans);
    while (ans.size() > 500) ans.pop_back();
    while (ans.size() < 500) ans += '0';
    std::ranges::reverse(ans);
    for (int i = 0; i < 500; ++i) {
        std::cout << ans[i];
        if ((i + 1) % 50 == 0) std::cout << '\n';
    }
}
int main() {
    before();
    int T = 1;
    while (T--) { MeIoN_is_UMP45(); }
    R 0;
}
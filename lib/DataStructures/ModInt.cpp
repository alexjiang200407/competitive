const int MOD=1e9+7;

template <int P>
struct modint {
    int v;

    constexpr modint() : v(0) {}
    constexpr modint(ll v_) : v(v_ % P) {
        if (v < 0) {
            v += P;
        }
    }
    constexpr explicit operator int() const { return v; }
    constexpr friend ostream& operator<<(ostream &out, modint n)
    {
        return out << int(n);
    }
    constexpr friend istream& operator>>(istream &in, modint &n)
    {
        ll v;
        in >> v;
        n = modint(v);
        return in;
    }

    constexpr friend bool operator==(modint a, modint b) {
        return a.v == b.v;
    }
    constexpr friend bool operator!=(modint a, modint b) {
        return a.v != b.v;
    }

    constexpr modint operator-()
    {
        modint res;
        res.v = v ? P - v : 0;
        return res;
    }

    constexpr modint& operator++()
    {
        v++;
        if (v == P) v = 0;
        return *this;
    }
    constexpr modint& operator--()
    {
        if (v == 0) v = P;
        v--;
        return *this;
    }
    constexpr modint& operator+=(modint o)
    {
        v -= P - o.v;
        v = (v < 0) ? v + P : v;
        return *this;
    }
    constexpr modint& operator-=(modint o)
    {
        v -= o.v;
        v = (v < 0) ? v + P : v;
        return *this;
    }
    constexpr modint& operator*=(modint o)
    {
        v = 1LL * v * o.v % P;
        return *this;
    }
    constexpr modint& operator/=(modint o) { return *this *= o.inv(); }

    constexpr friend modint operator++(modint &a, signed)
    {
        modint r = a;
        ++a;
        return r;
    }
    constexpr friend modint operator--(modint &a, signed)
    {
        modint r = a;
        --a;
        return r;
    }

    constexpr friend modint operator+(modint a, modint b)
    {
        return modint(a) += b;
    }
    constexpr friend modint operator-(modint a, modint b)
    {
        return modint(a) -= b;
    }
    constexpr friend modint operator*(modint a, modint b)
    {
        return modint(a) *= b;
    }
    constexpr friend modint operator/(modint a, modint b)
    {
        return modint(a) /= b;
    }

    constexpr modint qpow(ll p)
    {
        modint res = 1, x = v;
        while (p > 0) {
            if (p & 1) { res *= x; }
            x *= x;
            p >>= 1;
        }
        return res;
    }

    constexpr modint inv()
    {
        return qpow(P - 2);
    }
};


typedef modint<MOD> mint;
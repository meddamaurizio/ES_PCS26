#include <iostream>
#include <concepts>
#include <numeric> // per std::gcd

template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;

    // Metodi privati
    void semplifica() {
        if (den_ == 0) {
            // Tengo Sempre gli infiniti e i NaN in forma compatta
            if (num_ > 0) num_ = 1;
            else if (num_ < 0) num_ = -1;
            return;
        }
        if (num_ == 0) {
            // rappresento lo zero come 0/1
            den_ = 1;
            return;
        }
        
        // semplificazione della frazione negli altri casi
        I g = std::gcd(num_, den_);
        num_ /= g;
        den_ /= g;
        
        // Sposto il segno dal denominatore se negativo
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    // COSTRUTTORI

    rational() 
    : num_(0), den_(1) 
    {}

    rational(I num) 
    : num_(num), den_(1) 
    {}

    rational(I num, I den) 
    : num_(num), den_(den) {
        semplifica();
    }

    // Metodi richiesti per accedere a num e den 
    I num() const { return num_; }
    I den() const { return den_; }

    // Altri Metodi 
    bool is_nan() const { 
        return (num_ == 0 && den_ == 0);
    }

    bool is_inf() const {
         return (den_ == 0 && num_ != 0);
    }


    // Definisco l'elemento inverso
    rational operator-() const {
        if (den_ == 0 && num_ == 0) return *this; // NaN
        rational res = *this;
        res.num_ = -res.num_;
        return res; // (den_ >= 0 sempre)
    }

    // SOMMA
    // si usa la propagazione come nell'aritmetica floating point

    rational& operator+=(const rational& othr) {
        //  NaN
        if ((den_ == 0 && num_ == 0) || (othr.den_ == 0 && othr.num_ == 0)) {
            num_ = 0; den_ = 0; 
            return *this;
        }

        bool this_inf = is_inf();
        bool othr_inf = othr.is_inf();

        // propagazione Inf
        if (this_inf && othr_inf) {
            if ((num_ > 0) != (othr.num_ > 0)) {
                // +Inf + -Inf = NaN
                num_ = 0; den_ = 0;
            }
            // altrimenti mantengo il segno
            return *this;
        }

        if (this_inf) return *this; // Inf + a = Inf
        if (othr_inf) { // a + Inf = Inf
            num_ = othr.num_;
            den_ = othr.den_;
            return *this;
        }

        // Addizione standard
        num_ = num_ * othr.den_ + othr.num_ * den_;
        den_ = den_ * othr.den_;
        semplifica();
        
        return *this;
    }

    rational operator+(const rational& othr) const {
        rational res = *this;
        res += othr;
        return res;
    }

    // Devinisco la sottrazione come somma dell'inverso
    rational& operator-=(const rational& othr) {
        return *this += (-othr);
    }

    rational operator-(const rational& othr) const {
        rational res = *this;
        res -= othr;
        return res;
    }

    // MOLTIPLICAZIONE
    rational& operator*=(const rational& othr) {
        if ((den_ == 0 && num_ == 0) || (othr.den_ == 0 && othr.num_ == 0)) {
            num_ = 0; den_ = 0; 
            return *this;
        }

        bool this_inf = is_inf();
        bool othr_inf = othr.is_inf();
        bool this_zero = (num_ == 0);
        bool othr_zero = (othr.num_ == 0);

        if ((this_inf && othr_zero) || (this_zero && othr_inf)) {
            // Inf * 0 = NaN
            num_ = 0; den_ = 0; 
            return *this;
        }

        if (this_inf || othr_inf) {
            bool pos = (num_ > 0) == (othr.num_ > 0);
            num_ = pos ? 1 : -1;
            den_ = 0;
            return *this;
        }

        num_ *= othr.num_;
        den_ *= othr.den_;
        semplifica();
        return *this;
    }

    rational operator*(const rational& othr) const {
        rational res = *this;
        res *= othr;
        return res;
    }

    // Definisco il reciproco
    rational reciproco() const {
        if (den_ == 0 && num_ == 0) return *this; // NaN -> NaN
        if (den_ == 0) return rational(0); // Inf -> 0
        if (num_ == 0) return rational(1, 0); // 0 -> Inf (positivo perchè den_ >=0)
        return rational(den_, num_); // si semplifica col costruttore
    }

    // Divisione via reciproco e moltiplicazione
    rational& operator/=(const rational& othr) {
        return *this *= othr.reciproco();
    }

    rational operator/(const rational& othr) const {
        rational res = *this;
        res /= othr;
        return res;
    }
};

// Overload per le operazioni con gli interi
template<typename I> requires std::integral<I>
rational<I> operator+(I lhs, const rational<I>& othr) {
    rational<I> res(lhs);
    res += othr;
    return res;
}

template<typename I> requires std::integral<I>
rational<I> operator-(I lhs, const rational<I>& othr) {
    rational<I> res(lhs);
    res -= othr;
    return res;
}

template<typename I> requires std::integral<I>
rational<I> operator*(I lhs, const rational<I>& othr) {
    rational<I> res(lhs);
    res *= othr;
    return res;
}

template<typename I> requires std::integral<I>
rational<I> operator/(I lhs, const rational<I>& othr) {
    rational<I> res(lhs);
    res /= othr;
    return res;
}

// OUTPUT A SCHERMO
template<typename I> requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        if (r.num() == 0) os << "NaN";
        else if (r.num() > 0) os << "+inf";
        else os << "-inf";
    } else {
        os << r.num() << '/' << r.den();
    }
    return os;
}

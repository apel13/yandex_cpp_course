//
// Created by apel on 15.01.2021.
//

#ifndef YANDEX_CPP_COURSE_RATIONAL_H
#define YANDEX_CPP_COURSE_RATIONAL_H

class Rational {
public:
    Rational()
            : _numerator(0), _denominator(1) {}

    Rational(int numerator, int denominator)
            : _numerator(numerator), _denominator(denominator) {
        if (denominator == 0) throw std::invalid_argument("Denominator == 0");
        reduce_and_update();
    }

    int Numerator() const {
        return _numerator;
    }

    int Denominator() const {
        return _denominator;
    }

private:
    int _numerator, _denominator;

    void reduce_and_update() {
        if (_numerator == 0) {
            _numerator = 0;
            _denominator = 1;
            return;
        }
        if (_denominator < 0) {
            _denominator *= -1;
            _numerator *= -1;
        }
        int d = std::gcd(abs(_numerator), _denominator);

        _numerator /= d;
        _denominator /= d;
    }
};

bool operator==(const Rational &lhs, const Rational &rhs) {
    return (lhs.Numerator() == rhs.Numerator()) &&
           (lhs.Denominator() == rhs.Denominator());
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    return {
            lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    if (rhs.Numerator() == 0)
        throw std::domain_error("Dev on 0");
    return {
            lhs.Numerator() * rhs.Denominator(),
            lhs.Denominator() * rhs.Numerator()
    };
}

istream &operator>>(istream &is, Rational &r) {
    if (is) {
        string exp;
        is >> exp;
        std::smatch base_match;
        const std::regex base_regex("(-?[0-9]+)/([0-9]+)");
        if (regex_match(exp, base_match, base_regex))
            r = Rational(stoi(base_match[1].str()),
                         stoi(base_match[2].str()));
        else
            is.setstate(ios_base::failbit);
    }
    return is;
}

ostream &operator<<(ostream &os, const Rational &r) {
    return os << r.Numerator() << '/' << r.Denominator();
}

bool operator<(const Rational &lhs, const Rational &rhs) {
    return (lhs - rhs).Numerator() < 0;
}

#endif //YANDEX_CPP_COURSE_RATIONAL_H

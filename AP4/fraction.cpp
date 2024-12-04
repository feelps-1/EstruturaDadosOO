#include "fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction(long n, long d){
    if(d == 0){
        cout << "Division with zero!" << '\n';
    }
    if(d < 0){
        n = -n;
        d = -d;

    }

    numerator = n;
    denominator = d;
}

Fraction operator+(const Fraction& p, const Fraction& f){
    Fraction result;

    if(p.denominator != f.denominator){
            result.numerator = (p.numerator * f.denominator) + (p.denominator * f.numerator);
            result.denominator = p.denominator * f.denominator;
        }else{
            result.numerator = p.numerator + f.denominator;
        }

        return result;
}

Fraction operator-(const Fraction& p, const Fraction& f){
    Fraction temp = p;

    temp += (-f);

    return temp;
}

Fraction operator*(const Fraction& p, const Fraction& f){
    Fraction temp;

    temp.numerator = p.numerator * f.numerator;
    temp.denominator = p.denominator * f.denominator;

    return temp;
}

Fraction operator/(const Fraction& p, const Fraction& f){
    Fraction result;

    result.numerator = p.numerator * f.denominator;
    result.denominator = p.denominator * f.numerator;

    if( result.denominator < 0){
        result.numerator = -result.numerator;
        result.denominator = -result.denominator;
    }

    return result;
}

ostream& operator<<(ostream& os, const Fraction& f){
    os << f.numerator << '/' << f.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& f){
    cout << "Enter a fraction:\n"
            " Numerator:       "; is >> f.numerator;
    cout << " Denominator != 0:"; is >> f.denominator;

    if(!is) return is;

    if(f.denominator == 0){
        cout << "Denominator can't be zero!";
        cout << "Enter a new denominator: "; is >> f.denominator;
    }    

    if(f.denominator < 0){
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }

    return is;
}

#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction
{
private:
    long numerator;
    long denominator;
    
public:
    Fraction(long numerator = 0, long denominator = 1);

    Fraction operator- () const {
        return Fraction(-numerator, denominator);
    }

    Fraction& operator++(){
        numerator += denominator;
        return *this;
    }

    Fraction& operator--(){
        numerator -= denominator;
        return *this;
    }

    Fraction& operator+=( const Fraction& f){
        if(denominator != f.denominator){
            numerator = (numerator * f.denominator) + (denominator * f.numerator);
            denominator *= f.denominator;
        }else{
            numerator += f.denominator;
        }

        return *this;
    }

    Fraction& operator-=( const Fraction& f){
        *this += (-f);
        return *this;
    }   

    Fraction& operator*=( const Fraction& f){
        numerator *= f.numerator;
        denominator *= f.denominator;

        return *this;
    }   

    Fraction& operator/=( const Fraction& f){
        numerator *= f.denominator;
        denominator *= f.numerator;

        return *this;
    }

    friend Fraction operator+(const Fraction& p, const Fraction& f);
    friend Fraction operator-(const Fraction& p, const Fraction& f);
    friend Fraction operator*(const Fraction& p, const Fraction& f);
    friend Fraction operator/(const Fraction& p, const Fraction& f);
    friend ostream& operator<<(ostream& os, const Fraction& f);
    friend istream& operator>>(istream& os, Fraction& f);
};

#endif

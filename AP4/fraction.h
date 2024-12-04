#ifndef _FRACTION_
#define _FRACTION_

class Fraction
{
private:
    long numerator;
    long denominator;
    
public:
    Fraction(long numerator = 0, long denominator = 1);
    Fraction(const Fraction& f);
    ~Fraction();
    void display();

    Fraction& operator-(){
        numerator = -numerator;
    }

    Fraction& operator++(){
        numerator += denominator;
    }

    Fraction& operator--(){
        numerator -= denominator;
    }

    Fraction& operator+=( const Fraction& f){
        if(denominator != f.denominator){
            numerator = numerator * f.denominator + denominator * f.numerator;
            denominator = denominator * f.denominator;
        }else{
            numerator += f.denominator;
        }
    }
};

#endif

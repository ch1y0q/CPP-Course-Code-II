#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
    friend std::ostream& operator<< (std::ostream& os, const Complex& c);
    friend std::istream& operator>> (std::istream& os, Complex& c);
public:
    explicit Complex(double = 0.0, double = 0.0);
    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;
    void print() const; 
private:
    double real;
    double imaginary;
};

#endif

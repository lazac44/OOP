#ifndef Polynomial_H
#define Pylynomial_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Polynomial {
    vector<double> coefficients;
    int capacity;
public:
    Polynomial(int degree, vector<double> coefficients);
    Polynomial(const Polynomial &that);
    ~Polynomial();
    int degree() const;
    double evaluate(double x) const;
    Polynomial derivative() const;
    double operator[](int index) const;
    friend Polynomial operator -(const Polynomial &a);
    friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator -(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator *(const Polynomial &a, const Polynomial &b);
    friend ostream & operator <<(ostream& out, const Polynomial& what);
    // Polynomial& operator=(const Polynomial&) = delete;
    void print() const;
};

#endif

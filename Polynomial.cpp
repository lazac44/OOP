#include "Polynomial.h"

int Polynomial::degree() const{
    return capacity - 1;
}

double Polynomial::evaluate(double x) const{
    double curr = 1;
    double result = 0;
    for(double number : coefficients){
        result += number * curr;
        curr *= x;
    }
    return result;
}

Polynomial::Polynomial(int degree, vector<double> coefficients){
    this->capacity = degree + 1;
    this->coefficients = coefficients;
}

Polynomial::Polynomial(const Polynomial& that){
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;
}

Polynomial Polynomial::derivative() const{
    int n = this->coefficients.size();
    vector<double> coeff(n - 1);
    for(int i = 1; i < n; i++){
        coeff[i - 1] = this->coefficients[i] * i;
    }
    return Polynomial(n - 2, coeff);
}

double Polynomial::operator[](int index) const{
    return this->coefficients[index];
}

Polynomial operator -(const Polynomial &a){
    vector<double> coeff(a.coefficients.size());
    for(int i = 0; i < a.coefficients.size(); i++){
        coeff[i] = -a.coefficients[i];
    }
    return Polynomial(a.capacity - 1, coeff);
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    int n = max(a.coefficients.size(), b.coefficients.size());
    vector<double> coeff(n);

    for (int i = 0; i < n; i++) {
        if (i < a.coefficients.size())
            coeff[i] += a.coefficients[i];

        if (i < b.coefficients.size())
            coeff[i] += b.coefficients[i];
    }

    return Polynomial(n - 1, coeff);
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    int n = max(a.coefficients.size(), b.coefficients.size());
    vector<double> coeff(n);

    for (int i = 0; i < n; i++) {
        if (i < a.coefficients.size())
            coeff[i] += a.coefficients[i];

        if (i < b.coefficients.size())
            coeff[i] -= b.coefficients[i];
    }

    return Polynomial(n - 1, coeff);
}

Polynomial operator *(const Polynomial &a, const Polynomial &b){
    vector<double> coeff(a.coefficients.size() + b.coefficients.size() - 1);
    for(int i = 0; i < a.coefficients.size(); i++){
        for(int j = 0; j < b.coefficients.size(); j++){
            coeff[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }
    return Polynomial(a.capacity + b.capacity - 2, coeff);
}

ostream & operator <<(ostream& out, const Polynomial& what){
    out << what.coefficients[0];
    for(int i = 1; i < what.coefficients.size(); i++){
        out << " + " << what.coefficients[i] << "x^" << i;
    }
    return out;
}

// Polynomial& Polynomial::operator=(const Polynomial& that){
//     if(this != &that){
//         this->capacity = that.capacity;
//         this->coefficients = that.coefficients;
//     }
//     return *this;
// }

Polynomial::~Polynomial(){}

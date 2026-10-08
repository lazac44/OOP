#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Polynomial.h"

using namespace std;

int main() {
    vector<double> v = {1, 2, 3};
    Polynomial elso(v.size() - 1, v);
    cout<<elso<<endl;
    Polynomial masodik(elso.derivative());
    cout<<masodik<<endl;
    cout<<elso.evaluate(2)<<endl<<masodik.evaluate(2)<<endl;
    cout<<elso.degree()<<" "<<masodik.degree()<<endl;
    Polynomial harmadik = elso + masodik;
    cout<<harmadik<<endl;
    Polynomial negyedik = elso - masodik;
    cout<<negyedik<<endl;
    Polynomial otodik = elso * masodik;
    cout<<otodik<<endl;
    Polynomial hatodik = -elso;
    cout<<hatodik<<endl;
}

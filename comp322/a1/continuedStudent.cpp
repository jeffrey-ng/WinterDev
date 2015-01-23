#include "continued.h"

unsigned int gcd(unsigned int a, unsigned int b){

    if (a==0) {
        return b;
    }
    return gcd(b%a, a);
}

ContinuedFraction *getCFlargerThanOne(unsigned int b, unsigned int a) {
  // your code here
}

ContinuedFraction *getCF(unsigned int b, unsigned int a) {
  // your code here
}


ContinuedFraction *getCF(unsigned int head, ContinuedFraction *fixed, ContinuedFraction *period) {
  // your code here
}


Fraction getApproximation(ContinuedFraction *fr, unsigned int n) {
  // your code here
}

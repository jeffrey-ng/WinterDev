#include "continued.h"

unsigned int gcd(unsigned int a, unsigned int b){

    if (a==0) {
        return b;
    }
    return gcd(b%a, a);
}

unsigned int gcdFaster(unsigned int a, unsigned int b) {
}

ContinuedFraction *getCFlargerThanOne(unsigned int b, unsigned int a) {
    ContinuedFraction CF;

    unsigned int x = b/a;
    unsigned int y = b-x*a;

    CF.head = x;

    if (y == 0) {
        CF.tail = NULL;
    } else {
        CF.tail = getCFlargerThanOne(a,y);
    }
    return &CF;
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

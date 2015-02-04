#include <GSS/GSS.h>
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
    ContinuedFraction *CF = new ContinuedFraction;

    unsigned int x = b/a;
    unsigned int y = b-x*a;

    CF->head = x;

    if (y == 0) {
        CF->tail = NULL;
    } else {
        CF->tail = getCFlargerThanOne(a,y);
    }
    return CF;
}

ContinuedFraction *getCF(unsigned int b, unsigned int a) {
    ContinuedFraction *initCF = new ContinuedFraction;

    if (b/a > 1) {
        initCF = getCFlargerThanOne(b,a);
    } else {
        initCF = getCFlargerThanOne(0, a);
    }

    return initCF;
}


ContinuedFraction *getCF(unsigned int head, ContinuedFraction *fixed, ContinuedFraction *period) {
  // your code here
    ContinuedFraction newFraction;
    newFraction.head = head;
    newFraction.tail = fixed;

}


Fraction getApproximation(ContinuedFraction *fr, unsigned int n) {
  // your code here
    Fraction NF;

    if (n==0) {
        NF.numerator = 1;
        NF.denominator = fr->head;
        return NF;
    } else {
        n--;
        NF = getApproximation(fr->tail,n);
        Fraction temp;
        temp.denominator = fr->head * NF.denominator + NF.denominator;
        temp.numerator = NF.denominator;

        return temp;

    }

}

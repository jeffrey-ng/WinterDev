#include <GSS/GSS.h>
#include "continued.h"

unsigned int gcd(unsigned int a, unsigned int b){

    if (a==0) {
        return b;
    }
    return gcd(b%a, a);
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

    if (b/a > 1) {
        return getCFlargerThanOne(b,a);
    } else {
        ContinuedFraction *CF = new ContinuedFraction;
        CF->head = 0;
        CF->tail = getCF(a, b);
        return CF;
    }

}


ContinuedFraction *getCF(unsigned int head, ContinuedFraction *fixed, ContinuedFraction *period) {
  // your code here
    ContinuedFraction *newFraction = new ContinuedFraction;
    newFraction->head = head;
    newFraction->tail = fixed;

    //need to make an infinite loop.
    // ex: aaa,bbb,aaa,... where the aaa are actually the same

    ContinuedFraction *copiedPart = new ContinuedFraction;
    copiedPart->head = period->head;
    while(period->tail != NULL) {
        ContinuedFraction *temp = new ContinuedFraction;
        temp->head = period->head;
        while(copiedPart->tail != NULL) {
            copiedPart=copiedPart->tail;
        }
        copiedPart->tail = temp;
        period = period->tail;

    }

    //Get to end of copied part. This is used to jump to end
    ContinuedFraction *tPoint = copiedPart;
    while (tPoint->tail != NULL) {
        tPoint = tPoint->tail;
    }

    tPoint->tail = copiedPart;

    //now we need to move this copied part to end of our new fractoin
    tPoint = newFraction;
    while (tPoint->tail != NULL) {
        tPoint = tPoint->tail;
    }
    tPoint->tail = copiedPart;

    return newFraction;
}
//takes two fractions and adds the econd on to he nd of the other



Fraction getApproximation(ContinuedFraction *fr, unsigned int n) {
  // your code here
    //math
    Fraction *CF = new Fraction;

    if (n==1) {
        CF->numerator = fr->head;
        CF->denominator = 1;
    } else {
        Fraction *intermediateFraction = new Fraction;
        Fraction recursionFraction = getApproximation(fr->tail, n-1);

        intermediateFraction->numerator = ((fr->head) * (recursionFraction.numerator));
        intermediateFraction->denominator = recursionFraction.denominator;
        CF->numerator = intermediateFraction->numerator + recursionFraction.denominator;
        CF->denominator = recursionFraction.numerator;
    }
    return *CF;


}

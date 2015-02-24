#include "flowers.h"

unsigned int spitSqrt8(unsigned int index) {
    if (index == 0) {
        return 2;
    }
    if (index % 2 == 0) {
        return 4;
    }

    return 1;

}

unsigned int spitEulerSquare(unsigned int index) {

    if (index == 0) {
        return 7;
    }
    if (index == 1) {
        return 2;
    }
    if (index%5 == 3 || index%5 == 2) {
        return 1;
    }
    if (index%5 == 0) {
        return (index/5)*12 + 6;
    }
    if (index%6 == 0) {
        return (index/6)*3 + 2;
    }
    if (index%4 == 0) {
        return (index/4)*3
    }
}

Fraction getApproximation(ContinuedFraction &fr, unsigned int n){
    // TODO : add code here
}


double getAngle(ContinuedFraction &theta, int k) {
    // TODO : add code here
}

Seed getSeed(ContinuedFraction &theta, int k) {
    // TODO : add code here
}

void pushSeed(std::list<Seed> &flower, ContinuedFraction &theta) {
    // TODO : add code here
}

int spitNextMagicBox(MagicBox &box) {
    // TODO : add code here
}

ContinuedFraction getCFUsingMB(ContinuedFraction &f, int a, int b, int length) {
    // TODO : add code here
}

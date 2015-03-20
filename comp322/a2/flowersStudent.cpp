#include "flowers.h"
#include <math.h>

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

    if (index==0) {
        return 7;
    }

    if (index%5 == 3|| index%5 == 2) {
        return 1;
    }
    if (index%5 == 1) {
        return 2 + ((index/5)*3);
    }
    if (index%5 == 4) {
        return 3 + ((index/5)*3);
    }
    return 18 + (((index/5)-1)*12);


}

Fraction getApproximation(ContinuedFraction &fr, unsigned int n){
    // TODO : add code here
    Fraction retFraction;
    std::vector<int> temp;
    if (fr.fixedPart[0]==0) {
        std::vector<int>::iterator iter = fr.periodicPart.begin();
        while (n>1) {
            temp.push_back(*iter);
            n--;
            if (iter == fr.periodicPart.end() ) {
                iter = fr.periodicPart.begin() ;
            }
        }


    }
    else if (fr.fixedPart.size()!=0) {
        std::vector<int>::iterator iter = fr.fixedPart.begin();
        while (iter != fr.fixedPart.end()) {
            temp.push_back(*iter);
            n--;
            if (n<1) {
                break;
            }
            ++iter;
        }

    }
    if (fr.periodicPart.size()!=0) {

        std::vector<int>::iterator iter = fr.periodicPart.begin();
        while (n>1) {
            temp.push_back(*iter);
            n--;
            if (iter == fr.periodicPart.end() ) {
                iter = fr.periodicPart.begin() ;
            }
        }
    }

    retFraction.numerator=1;
    retFraction.denominator=temp.back();
    temp.pop_back();
    temp.pop_back();

    std::vector<int>::iterator iter = temp.end()+1;
    while (iter != temp.begin()) {
        int num = ((*iter)*retFraction.denominator);

        retFraction.numerator+=num;
        num=retFraction.numerator;
        retFraction.numerator = retFraction.denominator;
        retFraction.denominator= num;
        --iter;
    }
    int num = temp[0]*retFraction.denominator;
    retFraction.numerator+= num;

    return retFraction;
}


double getAngle(ContinuedFraction &theta, int k) {

    double temp;
    Fraction approx = getApproximation(theta, 7);
    double approxDeci= ((double)approx.numerator/(double)approx.denominator)*k;
    approxDeci = modf(approxDeci, &temp);
    return  approxDeci * (2*M_PI);
}

Seed getSeed(ContinuedFraction &theta, int k) {
    Seed retSeed;

    double myAngle = getAngle(theta, k);

    retSeed.x= sqrt(k/M_PI)*cos(myAngle);
    retSeed.y= sqrt(k/M_PI)*sin(myAngle);
    return retSeed;
}

void pushSeed(std::list<Seed> &flower, ContinuedFraction &theta) {
    flower.push_back(getSeed(theta, (int)flower.size()));
}

int spitNextMagicBox(MagicBox &box) {
    while(true){
        int i = (box).i;
        int j = (box).j;
        int k = (box).k;
        int l = (box).l;


        if (k==0 && l==0) {
            //base case
            return 0;
        }
        else if (k==0 || l==0 || (j/l != i/k)) {
            int t = spit((box).boxedFraction, (box).indexInBoxedFraction++);

            if(t!=-1) {
                (box).i =j;
                (box).j =i+j*t;
                (box).k =l;
                (box).l =k+l*t;
            } else {
                (box).i =j;
                (box).j =j;
                (box).k =l;
                (box).l =l;
            }
        } else {

            int q = i/k;
            (box).i =k;
            (box).j =l;
            (box).k =i-k*q;
            (box).l =j-l*q;
            return q;
        }

    }
}

ContinuedFraction getCFUsingMB(ContinuedFraction &f, int a, int b, int length) {
    ContinuedFraction retFraction;
    MagicBox box;
    (box).boxedFraction = f;
    (box).i=a;
    (box).j=b;
    int i =0;
    int k;

    while(i<length){
        k = spitNextMagicBox(box);
        if(k <= 0) {
            break;
        }
        retFraction.fixedPart.push_back(k);
        i++;
    }

    return retFraction;
}

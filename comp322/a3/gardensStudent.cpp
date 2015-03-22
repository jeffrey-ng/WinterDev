#include "gardens.h"
#include <stack>
#include <iostream>
#include <math.h>

 /* 0-credit */
Fraction ContinuedFraction::getApproximation(unsigned int k) const {
    //TODO
  Fraction toRet; // will be returned
  vector<cf_int> fixedPart;
  // we go backwards from the end to the beginning to compute the approximation
  // z is the index that keeps track of the position reached - starts at n-1
  int z = k-1;

  // start with 1/0
  toRet.numerator = 1;
  toRet.denominator = 0;

  while(!hasNoMore() || fixedPart.size() < z) {
   fixedPart.push_back(next());

  }
    auto fixedSize = fixedPart.size();
    
    for (cf_int i = fixedSize; i-->0;) {
        cf_int ada = fixedPart.at(i);
        auto tmp = toRet.numerator;
        toRet.numerator = ada * toRet.numerator + toRet.denominator;
        toRet.denominator = tmp;
    }

  return toRet;
}



// TODO : RationalCF::RationalCF(Fraction f) ...
RationalCF::RationalCF(Fraction frac): PeriodicCF({},{}) {
    cf_int b = frac.numerator;
    cf_int a = frac.denominator;
    cf_int y = 0;
    do {
        cf_int x = b/a;
        y = b-x*a;
        fixedPart.push_back(x);
        b=a;
        a=y;

    } while (y!=0);
    
}

RationalCF::~RationalCF() {
}

/* QUESTION 3*/

cf_int PeriodicCF::next() const {
    unsigned long periodicPartSize = periodicPart.size();
    unsigned long fixedPartSize = fixedPart.size();
    cf_int index = *iteratorPosition;
    (*iteratorPosition)++;
    
    if (index < fixedPartSize) {
        return fixedPart.at(index);
    } else {
        cf_int tIndex = (index-fixedPartSize)%periodicPartSize;
        return periodicPart.at(tIndex);
    }
}

bool PeriodicCF::hasNoMore() const {
    //TODO
    unsigned long periodicPartSize = periodicPart.size();
    unsigned long fixedPartSize = fixedPart.size();
    
    if (*iteratorPosition >= fixedPartSize && periodicPartSize == 0) {
        resetIterator();
        return true;
    }
    return false;

}

void PeriodicCF::resetIterator() const {
    while(*iteratorPosition > 0) {
        (*iteratorPosition)--;
    }
}



PeriodicCF::~PeriodicCF() {
    free(iteratorPosition);
}





/* QUESTION 4*/

//TODO : MagicBoxCF::MagicBoxCF(ContinuedFraction const* f, unsigned long aParam, unsigned long bParam) ...

MagicBoxCF::MagicBoxCF(const ContinuedFraction *f, cf_int a, cf_int b):a{a}, b{b} {
    mbnums = new cf_int[4];
    this->boxedFraction = f;
    resetIterator();
}

cf_int MagicBoxCF::next() const {
    cf_int *m_i = mbnums;
    cf_int *m_j = (mbnums+1);
    cf_int *m_k = (mbnums+2);
    cf_int *m_l = (mbnums+3);
    cf_int q = *m_i / *m_k;
    cf_int i = *m_k,
    j = *m_l,
    k = *m_i - *m_k * q,
    l = *m_j - *m_l * q;
    *m_i = i;
    *m_j = j;
    *m_k = k;
    *m_l = l;
    return q;
}

bool MagicBoxCF::hasNoMore() const {
    //TODO
    
    cf_int *m_i = mbnums;
    cf_int *m_j = (mbnums+1);
    cf_int *m_k = (mbnums+2);
    cf_int *m_l = (mbnums+3);


    
    while( ((*m_k == 0 || *m_l == 0) && !(*m_k == 0 && *m_l == 0)) ||
          (*m_k != 0 && *m_l != 0 && *m_i / *m_k != *m_j / *m_l) ) {
        
        // while the indeces are not yet ready to spit q
        if(boxedFraction->hasNoMore())
        {

            *m_i = *m_j;
            *m_k = *m_l;
            continue;
        }
        
        //read p
        cf_int p = boxedFraction->next();
        
//        (*mbnums)++;
//        mbnums = mbnums + 1;
//        auto xxx = mbnums[1];
        
        //change box accordingly
        cf_int i = *m_j,
        j = *m_i + *m_j * p,
        k = *m_l,
        l = *m_k + *m_l * p;
        *m_i = i;
        *m_j = j;
        *m_k = k;
        *m_l = l;
    }
    if(*m_k == 0 && *m_l == 0) return true;
    
    return false;
//    return q;
    
//    while(true){
////        int i = (box).i; int j = (box).j;
////        int k = (box).k; int l = (box).l;
//        cf_int i = *mbnums;
//        cf_int j = *(mbnums+1);
//        cf_int k = *(mbnums+2);
//        cf_int l = *(mbnums+3);
//        
//        if (k==0 && l==0)
//            return true; //reached end
//        
//        else if (k==0 || l==0 || (i/k != j/l)) {
////            int p = spit((box).boxedFraction, (box).indexInBoxedFraction++);
//            cf_int p = boxedFraction->next();
//            if(p!=-1) {
//                (box).i =j; (box).j =i+j*p;
//                (box).k =l; (box).l =k+l*p;
//            }
//            else {
//                (box).i =j; (box).j =j;
//                (box).k =l; (box).l =l; }}
//        else {
//            int q = i/k;
//            (box).i =k; (box).j =l;
//            (box).k =i-k*q; (box).l =j-l*q;
//            return q; }}

}

void MagicBoxCF::resetIterator() const {
    mbnums[0] = a;
    mbnums[1] = b;
    mbnums[2] = 1;
    mbnums[3] = 0;
    boxedFraction->resetIterator();

}

MagicBoxCF::~MagicBoxCF() {
    free(mbnums);
}



/* QUESTION 5*/

ostream &operator<<(ostream& outs, const ContinuedFraction &cf) {
    
    bool first = true;
    bool second = true;
    int count = 0;
    cout << "[";
    while(!cf.hasNoMore()) {
        
        
        if (count > 10) {
            cf.resetIterator();
            cout << ", ...";
            break;
        } else {
            if (first) {
                cout <<cf.next();
                cout << "; ";
                first = false;
            } else if (second) {
                cout << cf.next();
                second = false;
            } else {
                cout << ", ";
                cout << cf.next();
            }
            count ++;
           
        }
       
    }
    cout << "]";
    return outs;
}


/* QUESTION 6 */

float Flower::getAngle(unsigned int k) const {
    //TODO
 return 0;
}

//TODO : Flower::Flower(const ContinuedFraction *f, unsigned int apxLengthParam) ...


Flower::Flower(const ContinuedFraction *f, unsigned int apxLengthParam): apx_length{0} {

}

//Seed Flower::getSeed(unsigned int k) const {
//    //TODO
//}

//vector<Seed> Flower::getSeeds(unsigned int k) const {
//    //TODO
//}


Flower::~Flower() {
    //TODO
}

/* QUESTION 7*/

void Flower::writeMVGPicture(ostream &out, unsigned int k, unsigned int scale_x, unsigned int scale_y) const {
    //TODO
}






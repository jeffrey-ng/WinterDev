#include "gardens.h"
#include <stack>
#include <iostream>
#include <math.h>

 /* 0-credit */
Fraction ContinuedFraction::getApproximation(unsigned int k) const {
    //TODO
  Fraction toRet; // will be returned
  ContinuedFraction fr;
  vector<cf_int> fixedPart;
  // we go backwards from the end to the beginning to compute the approximation
  // z is the index that keeps track of the position reached - starts at n-1
  int z = k-1;

  // start with 1/0
  toRet.numerator = 1;
  toRet.denominator = 0;
  cf_int f = next();

  while(!hasNoMore()) {
   fixedPart.push_back(next());
  }

  for (cf_int ada :fixedPart) {
   auto tmp = toRet.numerator;
   toRet.numerator = ada * toRet.numerator + toRet.denominator;
   toRet.denominator = tmp;
  }
  resetIterator();

  return toRet;
}



// TODO : RationalCF::RationalCF(Fraction f) ...
RationalCF::RationalCF(Fraction f): PeriodicCF({},{}) {
 //TODO
}

RationalCF::~RationalCF() {
}

/* QUESTION 3*/

cf_int PeriodicCF::next() const {
    Fraction toRet;
 int z = (*iteratorPosition);
 toRet.numerator = 1;
 toRet.denominator = 0;
 auto m = periodicPart.size();
 auto l = fixedPart.size();

 for (; m > 0 && z >= l; z--) { // first do the periodic part - if m > 0
  auto idx = (z-l) % m; // get idex in the periodic part

  // change the numerator and denominator
  auto tmp = toRet.numerator;
  toRet.numerator = periodicPart[idx] * toRet.numerator + toRet.denominator;
  toRet.denominator = tmp;
 }

 for (; z >= 0; z--) { // do the fixed part now
  // change the numerator and denominator
  auto tmp = toRet.numerator;
  toRet.numerator = fixedPart[z] * toRet.numerator + toRet.denominator;
  toRet.denominator = tmp;
 }
 (*iteratorPosition)++;
  return 0;
}

bool PeriodicCF::hasNoMore() const {
    //TODO
    auto tmp = next();
    if (tmp == NULL) {}

 return false;
}

void PeriodicCF::resetIterator() const {
    //TODO
 unsigned int *newPosition = new unsigned int(0);
 *iteratorPosition = *newPosition;
}



PeriodicCF::~PeriodicCF() {
    //TODO
}





/* QUESTION 4*/

//TODO : MagicBoxCF::MagicBoxCF(ContinuedFraction const* f, unsigned long aParam, unsigned long bParam) ...

MagicBoxCF::MagicBoxCF(const ContinuedFraction *f, cf_int a, cf_int b):a{0}, b{0} {
}

cf_int MagicBoxCF::next() const {
    //TODO
 return 0;
}

bool MagicBoxCF::hasNoMore() const {
    //TODO
 return false;
}

void MagicBoxCF::resetIterator() const {
    //TODO

}

MagicBoxCF::~MagicBoxCF() {
    //TODO
}



/* QUESTION 5*/

ostream &operator<<(ostream& outs, const ContinuedFraction &cf) {
    //TODO
}


/* QUESTION 6 */

float Flower::getAngle(unsigned int k) const {
    //TODO
 return 0;
}

//TODO : Flower::Flower(const ContinuedFraction *f, unsigned int apxLengthParam) ...


Flower::Flower(const ContinuedFraction *f, unsigned int apxLengthParam): apx_length{0} {

}

Seed Flower::getSeed(unsigned int k) const {
    //TODO
}

vector<Seed> Flower::getSeeds(unsigned int k) const {
    //TODO
}


Flower::~Flower() {
    //TODO
}

/* QUESTION 7*/

void Flower::writeMVGPicture(ostream &out, unsigned int k, unsigned int scale_x, unsigned int scale_y) const {
    //TODO
}






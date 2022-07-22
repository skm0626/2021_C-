#include "MyTerm.h"

myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e){}

myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp){}

bool myTerm::operator == (const myTerm& term) const{
   return (coeff == term.coeff && exp == term.exp);
}

bool myTerm::operator != (const myTerm& term) const{
   return !(*this == term);
}

bool myTerm::operator < (const myTerm& term) const{
   return exp > term.exp;
}
myTerm myTerm::operator - () const{
   return myTerm(-coeff, exp);
}

myTerm myTerm::ddx() const{
   if (exp == 0)
      return myTerm(0, 0);
   return myTerm(exp*coeff, exp - 1);
}

ostream& operator <<(ostream &os, const myTerm& term){
   if (term.exp == 0){
      if (term.coeff == 0)
         return os;
      else
         return os << term.coeff;
   }
   if (term.coeff == 0)
      return os;
   if (term.coeff == 1)
      os << "x";
   else if (term.coeff == -1)
      os << "-x";
   else
      os << term.coeff << "x";
   if (term.exp == 1)
      return os;
   else
      return os << "^" << term.exp;
}

#include "0531_team.h"
#include <iostream>

Team operator+(Team a, const Team& b){
  a+=b;
  return a;
}

bool operator==(const Team& a, const Team& b){
  return (a.name == b.name);
}

bool operator!=(const Team &a, const Team& b){
  return !(a==b);
}

std::ostream& operator<<(std::ostream& os, const Team& a){
  os << a.name << "(" << a.victory << ")";
  return os;
}

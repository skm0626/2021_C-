#include <iostream>
#include <string>

class Team{
public:
  std::string name;
  int victory;
  Team(const std::string& n="X", int w=0):name(n), victory(w){}
  Team& operator+=(const Team& rhs){
    victory+=rhs.victory;
    return *this;
  }
  friend Team operator+(Team a, const Team& b);
  friend bool operator==(const Team& a, const Team& b);
  friend bool operator!=(const Team& a, const Team& b);
  friend std::ostream& operator<<(std::ostream& os, const Team& a);
};

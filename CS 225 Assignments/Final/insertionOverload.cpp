#include <iostream>
#include <string>
using namespace std;

class Pokemon{
private:
  string name;
public:
  Pokemon(string n){ name=n;}
  friend ostream& operator<<(ostream &os, const Pokemon&);
};

ostream& operator<<(ostream &os, const Pokemon &p){
  os<<p.name;
  return os;
}
int main(){
  Pokemon p("Pikachu");
  cout<<p<<endl; 
}

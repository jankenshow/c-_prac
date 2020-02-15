#include <iostream>
#include <string>
using namespace std;

class Inu
{
    string name;
public:
    Inu(string);
    void naku() const;
};

Inu::Inu(string s) : name(s){}
void Inu::naku() const{
    cout << "わんわん、" << name << "だわん" <<endl;
}

int main()
{
    string name;
    cout << "Enter your dog name..." << endl;
    cin >> name;
    Inu pochi(name);
    pochi.naku();
}
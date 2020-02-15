#include <iostream>
#include <string>
using namespace std;

class Neko
{
    string name;
public:
    // 外にコンストラクタがあるので、Neko(string s); の s は省略可能
    Neko(string s);
    void naku() const;
};

Neko::Neko(string s) : name(s){}

void Neko::naku() const{
    cout<<"にゃあ。俺様は"<<name<<"だ。"<<endl;
}

int main()
{
    string name;
    cout << "enter your cat name..." << endl;
    cin >> name;
    Neko mike(name);
    mike.naku();
}
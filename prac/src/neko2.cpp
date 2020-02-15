#include <iostream>
#include <string>
using namespace std;

class Neko
{
    string name;
public:
    Neko(string s) : name(s) {}
    void naku() const {
        cout << "にゃあ、我輩は"  << name << "である。" << endl;
    }
};

int main()
{
    string s;
    cout << "Enter your cat name..." << endl;
    cin >> s;
    Neko tama(s);
    tama.naku();
}

#include <iostream>
#include <string>
using namespace std;

class Glass
{
    int remaining;
public:
    Glass(int x) : remaining(x){};
    void drink(int);
};

void Glass::drink(int x)
{
    if(remaining >= x){
        remaining -= x;
        cout << "現在の残量は" << remaining << "です。" <<endl;
    }
    else{
        cout << "現在の残量は" << remaining << "だから、お水が足りないよぉ〜" <<endl;
    }
}

int main()
{
    int x;
    cin >> x;
    Glass cup(x);
    for(int i=0; i<6; i++)
    {
        cup.drink(i);
    }
}
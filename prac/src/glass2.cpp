#include <iostream>
using namespace std;

class Glass
{
    int remaining;
public:
    Glass() : remaining(10){};
    void drink();
};

void Glass::drink()
{
    if(remaining >= 2){
        remaining -= 2;
        cout << "グラスの残量は　" << remaining << "です。" << endl;
    }
    else{
        cout << "もう水がありませーん。" << endl;
    }
}

int main()
{
    cout << "水の入ったグラスがあります。\n少し飲んでしまいましょう。" << endl;
    Glass cup;
    for(int i=0; i<5 ; i++){
        cup.drink();
    }
}
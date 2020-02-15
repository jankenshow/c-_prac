#include <iostream>
#include <string>
using namespace std;

class Glass
{
    int remaining;
public:
    // 引数をもつコンストラクタと持たないコンストラクタを書くと、呼び出し時に引数があってもなくてもエラーが起こらなくなる
    Glass() : remaining(10){};
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
    cout << "cup1に水をどのくらい注ぎますか？" <<endl;
    cin >> x;
    Glass cup1(x);
    cout << "cup1についてでござる" <<endl;
    for(int i=0; i<6; i++)
    {
        cup1.drink(i);
    }
    Glass cup2;
    cout << "cup2についてでござる" <<endl;
    for(int i=0; i<6; i++)
    {
        cup2.drink(i);
    }
}
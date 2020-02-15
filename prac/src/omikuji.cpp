#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Omikuji
{
    int un;
public:
    Omikuji();
    void uranai();
};

Omikuji::Omikuji()
{
    srand((unsigned)time(NULL));
    cout << "自分のラッキーナンバー（1～5）を入力してください。" << endl;
    cin >> un;
}

void Omikuji::uranai()
{
    int daikichi = rand() % 5 + 1;
    if(daikichi==un){
        cout << "大吉なり〜" << endl;
    }
    else{
        cout << "吉なり〜" << endl;
    }
}

int main()
{
    Omikuji today;
    today.uranai();
}


// クラス無しで書くと以下のようになる
/*
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int un;  //ラッキーナンバー
    cout << "自分のラッキーナンバー（1～5）を入力してください。" << endl;
    cin >> un;  //自分のラッキーナンバーを代入
    srand( (unsigned)time( NULL ) );
    int x;
    x = rand() % 5 + 1;  //引いたおみくじの番号
    cout << "あなたの運勢は";
    if(x == un){                                            //xとunが等しければ大吉
        cout << "大吉ということです。" << endl;
    }
    else{                                                    //xとunが等しくなければ「普通」
        cout<<"並みということです。"<<endl;
    }
}
*/
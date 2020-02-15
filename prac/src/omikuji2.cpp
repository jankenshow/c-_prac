#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Omikuji
{
    int un;  //ラッキーナンバー
public:
    Omikuji();   //コンストラクタ
    void hiku();
};

//コンストラクタ、ラッキーナンバーをユーザに代入してもらいます
Omikuji::Omikuji()
{
    srand( (unsigned)time( NULL ) );
    cout<<"自分のラッキーナンバー（1～5）を入力してください。"<<endl;
    cin>>un;  //自分のラッキーナンバーを代入
}

//おみくじを引く
void Omikuji::hiku()
{
    int x;
    x = rand() % 5 + 1;   //1～5の乱数を発生させ、ｘに代入、これが引いたおみくじの番号
    cout << "あなたの運勢は";
    if(x == un){                                            //xとunが等しければ大吉
        cout << "大吉ということです。" << endl;
    }
    else{                                                    //xとunが等しくなければ「普通」
        cout<<"並みということです。"<<endl;
    }
}

int main()
{
    Omikuji ok;  //おみくじ
    cout << "1週間分の占いです。" << endl;
    for(int i = 0; i < 7; i++){
        cout << "今日から" << i << "日後：" << endl;
        ok.hiku();
    }
}
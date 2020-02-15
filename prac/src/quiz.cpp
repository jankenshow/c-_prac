#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "日本一高い山はどれですか。" << endl;
    while(1){
        cout << "数字を入力してください。" << endl;
        cout << "1.ヒマラヤ　2.富士山　3.ロッキー" << endl;
        cin >> i;
        if(i == 2){
            break;
        }
        cout << "はずれです。" << endl;  //不正解の場合breakされないので
                                                     //この文が実行される。
    }
    //ループ終了後次の文が実行される。
    cout<<"正解なので終了しました。"<<endl;
}
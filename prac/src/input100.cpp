#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    while(i != 100){
        cout << "数値を入力してねー(100が正解だよぇ)" << endl;
        cin >> i;
    }
    cout << "おわーり" << endl;
}


// breakでループを抜けらるので、下記の通りでも同様のプログラムになる
/*
int main()
{
    int i = 0;
    while(1){ // while(1)（または、for(;;)）で無限ループができる
        cout << "好きな数字を入力してください。" <<endl;
        cin >> i;
        if(i == 100){
            break;
        }
    }
    cout << "終了しました。" <<endl;
}
*/
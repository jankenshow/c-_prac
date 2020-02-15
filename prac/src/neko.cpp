#include <iostream>
#include <string>
using namespace std;

class Neko
{
// publicの上にあるものはprivate扱いになるので、private: は省略可能
private:
    // メンバ変数、データメンバ
    string name;
public:
    Neko(string s){
        name = s;
    }
    // Neko(string s) : name(s) {} // 上と同じ動作をするコンストラクタ

    // データメンバを変更しない場合は const をつける
    void naku() {
        cout << "にゃあ、我輩は" << name << "である。" << endl;
    }
};

// コンストラクタやメンバ関数の処理が長い場合は、クラス定義の外に書くのが普通
// クラス定義内に書かれた関数はインライン関数となり、その関数が使われる場所すべてにその処理がビルド時に書かれるため、実行可能ファイルが大きくなる
// 一方で、インライン化していない関数は処理時間が長くなる

/* class Neko
{
    string name;
public:
    Neko(string s);
    void naku() const;
};

Neko::Neko(string s) : name(s){}

void Neko::naku() const{
    cout<<"にゃあ。俺様は"<<name<<"だ。"<<endl;
}
*/

int main()
{
    string name;
    cout << "enter your cat name" << endl;
    cin >> name;
    Neko mike(name);
    mike.naku();
}
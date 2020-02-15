#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Hero
{
    int power;  // ヒーローのパワー
public:
    Hero() : power(100){}; // ヒーローのコンストラクタ、ヒーローのパワーをはじめ100とした
    void attack(int); // 「ヒーローが攻撃する」関数
    void deffense(int); // 「ヒーローが攻撃される」関数
};

// 「ヒーローが攻撃する」関数の定義、nは攻撃に使うパワー
void Hero::attack(int n)
{
    cout << "悪党め。正義の攻撃を受けてみよ。" << endl;
    cout << "どか～ん！！！" << endl;
    power -= n;  // 攻撃したのでパワーを減らします。
     // もしパワーがまだ0以上ならよし、もし、負になったら、使いすぎで負けとした。
    if(power>=0){
         cout << "残りのパワーは" << power << "だ。" << endl;
    }
    else{
        cout << "しまった！パワーを使いすぎた。" << endl;
        cout << "もうおしまいだ！！！がくっ。" << endl;
        cout << "ヒーローは倒れました。" << endl;
    }
}

// 「ヒーローが攻撃される」関数の定義、nは攻撃されて減らされるパワーの量
void Hero::deffense(int n)
{
    cout << "くそっ。悪党の攻撃も当たることがあるのか。" << endl;
    power -= n;  // 攻撃されてパワーが減る。
    // 以下の仕組みはattack()とほぼ同じ。
    if(power >= 0){
        cout << "現在のパワーは" << power << "だ。" <<endl;
    }
    else{
        cout << "やられた。がくっ。" << endl;
        cout << "ヒーローは倒れました。" << endl;
    }
}

class Daimao
{
    int power;  // 大魔王のパワー
public:
    Daimao() : power(100){}; // 大魔王のコンストラクタ、大魔王のはじめのパワーは100とした
    void attack(int); // 「大魔王が攻撃する」関数
    void deffense(int); // 「大魔王が攻撃される」関数
};

// 「大魔王が攻撃する」関数の定義、nは攻撃に使うパワー
void Daimao::attack(int n)
{
    cout << "大魔王様の一撃をうけてみよ。" << endl;
    cout << "どか～ん。" << endl;
    power -= n;  // 攻撃したのでパワーを減らします。

    // もしパワーがまだ０以上ならよし、もし、負になったら、使いすぎで負けとした。
    // しかし、大魔王のパワーは秘密なので書かない。
    if(power < 0){
        cout << "しまった！！！パワーを使いすぎた。" << endl;
        cout << "む、む、む。無念だ。がくっ。" << endl;
        cout << "大魔王は倒れました。" << endl;
    }
}

// 「大魔王が攻撃される」関数の定義。nは攻撃されて減らされるパワーの量
void Daimao::deffense(int n)
{
    cout<< "くそっ。正義の味方の攻撃も当たることがあるのか。" <<endl;
    power -= n;  // 攻撃されてパワーが減る。
    // 以下の仕組みはkougeki_suru()とほぼ同じ。大魔王のパワーは秘密なので書かない。
    if(power < 0){
        cout << "やられた。がくっ。" << endl;
        cout << "大魔王は倒れました。" << endl;
    }
}

// 対決場所のクラス
class Battle_Field
{
    Daimao bu; // 対決場所にいる大魔王bu
    Hero loto; // 対決場所にいるヒーローloto
    int place_of_bu; // 大魔王のいる場所（1～5の数値）、これは後で決まる
    int place_of_loto; // ヒーローのいる場所（1～5の数値）、これは後でユーザが決める
public:
    Battle_Field();
    void battle();
};

// 対決場所のコンストラクタの定義
Battle_Field::Battle_Field()
{
    srand((unsigned)time(NULL)); // 乱数の初期化(実行するたびに異なる乱数が発生するようになる)
    place_of_bu = rand() % 5 + 1;
    cout << "あなたと大魔王ブーとの決戦です。\n" << endl;
    cout << "大魔王ブーは座標1～5のどこかに潜んでいます。" << endl;
    cout << "あなたもどこかに身を潜めてください。" << endl;
    cout << "身を潜める座標（1～5の数値）を入力してください。" << endl;
    cin >> place_of_loto; // ヒーローの場所を入力
}

void Battle_Field::battle() // 「ヒーローと大魔王が対決する」関数の定義
{
    int cordinate, attack_power;  // 一時的に必要な「位置」と「攻撃量」の変数（いれもの）
    cout << "さあ、あなたの攻撃です。" << endl;
    cout << "攻撃の位置（1～5の数値）を入力してください。>> ";
    cin >> cordinate; // 攻撃する位置をitiに代入
    cout << "攻撃に使うパワー（100以下の数値）を入力してください。>> ";
    cin >> attack_power;            // 攻撃に使うパワーをkougekiに代入
    cout << endl;

    loto.attack(attack_power); // ヒーローlotoの攻撃
    if(place_of_bu==cordinate){  // もしbu_no_bashoとitiが一致したら
        bu.deffense(attack_power * 2); // 大魔王はヒーローが使ったパワーの2倍を消耗
    }
    else{
        cout << "あなたの攻撃ははずれたようです。" << endl;  // はずれたら、何も起こらない
    }
    cout << endl;

    cout << "大魔王の攻撃です。" << endl;
    cout << "（エンターキーを押してください。）" << endl;
    cin.get();        // 下二つの関数のみでは上手く行かなかったので、回避のため
    cin.sync();       // cinをフラッシュ(「cin >> x;」などとすると、enterで入力を受け付け、
    // 「x」には入力値が入るが、enterによる改行は「cin」の中に残ってしまうので、「c.get()」をした時に、勝手に反応してしまうので、
    // 「cin」の中身を捨てるための関数)
    cin.get();        // 1時ストップ(キーボードから一文字だけ文字を読み込め」という読み込みの関数で、
    // ユーザの入力を待ち、ユーザが文字を入力したら、この関数の書かれている場所にその文字を置いてくれる（「その文字を戻す」）」
    // エンターキーが押されるまで待ち状態になる)
    cordinate = rand() % 5 + 1;       // 大魔王の攻撃の位置は乱数（ここでは1～5までのうちのどれか）で決まる
    attack_power = rand() % 100 + 1; // 大魔王の攻撃の量も乱数（1～100までのうちのどれか）で決まる

    bu.attack(attack_power);   // 大魔王buの攻撃（大魔王のパワーが減る）
    if(place_of_loto == cordinate){              // 当たったら
        loto.deffense(attack_power * 2);  // 攻撃される
    }
    else{                                 // はずれたら
        cout << "大魔王ブーの攻撃ははずれたようです。" << endl;
    }
}

int main()
{
    Battle_Field dokoka;  //対決場所Dokokaの生成
                           //ここでコンストラクタが働き、ヒーローと大魔王の位置が決められる。

    dokoka.battle();      //dokokaの対決
}
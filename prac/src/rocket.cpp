#include <iostream>
#include <string>
using namespace std;

class Rocket
{
    int fuel;
    int velocity;
public:
    Rocket(int, int);
    void accelerate();
};

Rocket::Rocket(int x, int y) : fuel(x), velocity(y){}
void Rocket::accelerate()
{
    if(fuel>=2){
        fuel -= 2;
        velocity += 2;
        cout << "現在、燃料は　" << fuel << " 残っています。" << endl;
        cout << "速度は " << velocity << " に到達しました。" << endl;
    }
    else{
        printf("燃料残量は %d です。燃料が足りないため、加速できません。\n", fuel);
    }
}

int main()
{
    cout << "ロケットをメモリ上につくります。燃料（整数）を入力してください。"<<endl;
    int n;
    cin >> n;
    cout << "初速度（整数）を入力してください。"<<endl;
    int m;
    cin >> m;

    Rocket apollo(n, m);
    cout<< "加速します。" <<endl;
    apollo.accelerate();
    cout<< "加速します。" <<endl;
    apollo.accelerate();
    cout<< "加速します。" <<endl;
    apollo.accelerate();
}

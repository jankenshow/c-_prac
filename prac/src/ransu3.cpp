#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    cout << rand() % 10 + 1 << endl; // 1~10の乱数を生成
    cout << rand() % 10 + 1 << endl;
    cout << rand() % 10 + 1 << endl;
}

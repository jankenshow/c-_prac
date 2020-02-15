#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned)time(NULL)); // これが無いと実行するたびに同じ乱数になってしまう
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
}
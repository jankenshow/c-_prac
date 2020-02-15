#include <iostream>
using namespace std;

class Glass
{
    int remaining;
public:
    Glass() : remaining(10){};
    void drink(){ remaining -= 2; };
};

int main()
{
    cout << "水の入ったグラスがあります。\n少し飲んでしまいましょう。" << endl;
    Glass cup;
    cup.drink();
}
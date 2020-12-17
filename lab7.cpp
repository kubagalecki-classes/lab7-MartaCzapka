#include <iostream>
#include <variant>
#include <vector>
using namespace std;
double podziel(int c, int d)
{
    if (d == 0) {
        int wyjatek = 0;
        throw wyjatek;
    }
    return c / d;
}
class Informer
{
public:
    Informer() { cout << "Konstruuje\n"; }
    ~Informer() { cout << "Niszcze\n"; }
};
int main()
{
    int x;
    int a, b;
    cin >> x >> a >> b;
    try {
        Informer               inf;
        int                    tab[x]{};
        int                    t[a]{};
        variant< int, string > var;
        if (b % 2 == 0)
            var = 42;
        else
            var = "nieparzyste";
        cout << get< int >(var);
        podziel(3, 0);
    }
    // catch (const bad_alloc& wyjatek) {
    //    cout << "ups, wyjatek " << wyjatek.what();
    // }
    catch (const exception& wyjatek) {
        podziel(3, 0);
    }
}

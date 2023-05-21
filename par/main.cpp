#include <fstream>
#include <iostream>


std::ifstream in("par.in");
std::ofstream out("par.out");

int n, k, nr;
char s;

int main()
{
    in >> n;
    if (n % 2 != 0)
    {
        out << -1;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        in >> s;
        if (s == '(')
            nr++;
        else
            nr--;
        if (nr == -1)
        {
            nr = 1;
            k++;
        }
    }

    k += nr / 2;
    out << k;

    in.close();
    out.close();

    return 0;
}
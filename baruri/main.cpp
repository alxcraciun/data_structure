#include <fstream>

std::ifstream in("baruri.in");
std::ofstream out("baruri.out");

int T, N, M, v[100005];
int op, B1, B2, x;

void update(int poz, int val)
{
    while (poz <= N)
    {
        v[poz] += val;
        poz += (poz & (-poz)); 
    }
}

int suma(int poz)
{
    int suma = 0;
    while (poz > 0)
    {
        suma += v[poz];
        poz -= (poz & (-poz));
    }
    return suma;
}

int main()
{
    in >> T;

    while (T--)
    {
        in >> N;
        for (int i = 1; i <= N; i++)
        {
            in >> x;
            update(i, x);
        }

        in >> M;
        while (M--)
        {
            in >> op;
            if (op == 0)
            {
                in >> B1 >> B2;
                out <<  suma(std::min(N, B1 + B2)) - suma(B1) + suma(B2 + 1) - suma(std::max(B1 - B2 - 1, 0)) << '\n';
            }
            else if (op == 1)
            {
                in >> x >> B1;
                update(B1, x);
            }
            else if (op == 2)
            {
                in >> x >> B1;
                update(B1, -x);
            }
            else if (op == 3)
            {
                in >> x >> B1 >> B2;
                update(B1, -x);
                update(B2, x);
            }
        }
        for (int i = 1; i <= N; i++)
        {
            v[i] = 0;
        }
    }

    return 0;
}
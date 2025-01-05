#include <fstream>

std::ifstream in("kami.in");
std::ofstream out("kami.out");

int N, N, v[100001];
int x, y, z, maxi = -1;

int main()
{
    in >> N;
    v[0] = 1000000001;
    for (int i = 1; i <= N; i++)
    {
        in >> v[i];
        maxi = std::max(maxi, v[i]);
    }
    
    in >> N;
    for (int i = 0; i < N; i++)
    {
        in >> x;
        if (x == 0)
        {
            in >> y >> z;
            v[y] = z;
            maxi = std::max(maxi, v[i]);
        }
        else
        {
            in >> y;
            int suma = v[y], j = y - 1;
            while (suma > v[j] && suma <= maxi)
            {
                suma += v[j];
                j--;
            }
            if (suma > maxi)
            {
                out << "0" << '\n';
            }
            else
            {
                out << j << '\n';
            }
        }
    }

    return 0;
}
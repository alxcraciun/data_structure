#include <fstream>
#include <unordered_map>

std::ifstream in("loto.in");
std::ofstream out("loto.out");

int n, v[101];
long s;
bool found;
std::unordered_map<int, int[3]> map;

void afisare_rezultat(int i, int j, int k)
{
    out << v[i] << ' ';
    out << v[j] << ' ';
    out << v[k] << ' ';
    out << map[s - (v[i] + v[j] + v[k])][0] << ' ';
    out << map[s - (v[i] + v[j] + v[k])][1] << ' ';
    out << map[s - (v[i] + v[j] + v[k])][2] << '\n';
}

int main()
{
    in >> n >> s;
    for (int i = 0; i < n; i++)
        in >> v[i];

    found = false;
    for (int i = 0; i < n && found == false; i++)
        for (int j = 0; j < n && found == false; j++)
            for (int k = 0; k < n && found == false; k++)
            {
                map[v[i] + v[j] + v[k]][0] = v[i];
                map[v[i] + v[j] + v[k]][1] = v[j];
                map[v[i] + v[j] + v[k]][2] = v[k];
                if (map.find(s - (v[i] + v[j] + v[k])) != map.end())
                {
                    found = true;
                    afisare_rezultat(i, j, k);
                }
            }

    if (found == false)
        out << "-1";

    in.close();
    out.close();

    return 0;
}
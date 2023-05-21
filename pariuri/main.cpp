#include <fstream>
#include <unordered_map>

std::ifstream in("pariuri.in");
std::ofstream out("pariuri.out");

long N, M, timp, suma;
std::unordered_map<long, long> elem;

int main()
{
    in >> N;
    for (long i = 0; i < N; i++)
    {
        in >> M;
        for (long j = 0; j < M; j++)
        {
            in >> timp >> suma;
            if (elem.find(timp) == elem.end())
            {
                elem[timp] = suma;
            }
            else
            {
                elem[timp] += suma;
            }
        }
    }
    out << elem.size() << '\n';

    for (auto i = elem.begin(); i != elem.end(); i++)
    {
        out << i->first << ' ' << i->second << ' ';
    }

    in.close();
    out.close();

    return 0;
}
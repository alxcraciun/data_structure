#include <fstream>
#include <vector>

std::ifstream in("hashuri.in");
std::ofstream out("hashuri.out");

long unsigned N;
const long unsigned SIZE = 666013;
std::vector<std::vector<long unsigned>> v(SIZE + 1);

int main()
{
    in >> N;
    while (N)
    {
        long unsigned op, elem;
        in >> op >> elem;
        
        bool found = false;
        long unsigned bucket = elem % SIZE;

        if (op == 1)
        {
            for (long unsigned i = 0; i < v[bucket].size(); i++)
            {
                if (v[bucket][i] == elem)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                v[bucket].push_back(elem);
            }
        }
        else if (op == 2)
        {
            for (long unsigned i = 0; i < v[bucket].size(); i++)
            {
                if (v[bucket][i] == elem)
                {
                    v[bucket].erase(v[bucket].begin() + i);
                    break;
                }
            }
        }
        else if (op == 3)
        {
            for (long unsigned i = 0; i < v[bucket].size(); i++)
            {
                if (v[bucket][i] == elem)
                {
                    found = true;
                    break;
                }
            }
            out << found << '\n';
        }

        N--;
    }

    in.close();
    out.close();

    return 0;
}
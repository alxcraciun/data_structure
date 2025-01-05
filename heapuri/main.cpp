#include <fstream>
#include <set>
#include <vector>

std::ifstream in("heapuri.in");
std::ofstream out("heapuri.out");

unsigned int n, op, elem;
std::set<int> heap;    
std::vector<int> order; 

int main()
{
    in >> n;
    while (n)
    {
        in >> op;
        if (op == 1)
        {
            in >> elem;
            heap.insert(elem);
            order.push_back(elem); 
        }
        else if (op == 2)
        {
            in >> elem;
            if (elem - 1 < order.size())
            {
                heap.erase(order[elem - 1]);
            }
        }
        else if (op == 3)
        {
            out << *heap.begin() << '\n';
        }
        n--;
    }

    in.close();
    out.close();

    return 0;
}
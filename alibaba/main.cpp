#include <fstream>
#include <iostream>

std::ifstream in("alibaba.in");
std::ofstream out("alibaba.out");

int n, k, index;
char stiva[10001], numar[10001];

int main()
{
    in >> n >> k;
    in.get();
    in.getline(numar, 10001);
    
    stiva[index] = '$';
    for (int i = 0; i < n; i++)
    {
        while (index != 0 && k > 0 && stiva[index] < numar[i])
        {
            stiva[index] = 0, index--;
            k--;
        }
        index++, stiva[index] = numar[i];
    }

    while (k > 0)
    {
        stiva[index] = 0, index--;
        k--;
    }


    for (int i = 1; i <= index; i++)
    {
        out << stiva[i];
    }

    return 0;
}
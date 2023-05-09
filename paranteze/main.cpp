#include <fstream>
#include <iostream>

std::ifstream in("paranteze.in");
std::ofstream out("paranteze.out");

bool checkMatch(char open, char closed)
{
    if (open == '(' && closed == ')')
    {
        return true;
    }

    else if (open == '[' && closed == ']')
    {
        return true;
    }

    else if (open == '{' && closed == '}')
    {
        return true;
    }

    else
    {
        return false;
    }
}

int n, max_len = 0, stiva[1000002], index = 0;
char sir[1000002];

int main()
{
    in >> n;
    in.get();
    in.getline(sir, 1000001);

    stiva[index] = -1;
    for (int i = 0; i <= n; i++)
    {
        if (sir[i] == '(' || sir[i] == '[' || sir[i] == '{')
        {
            index++, stiva[index] = i;
        }
        else
        {
            int last_open = stiva[index];
            if (checkMatch(sir[last_open], sir[i]) && index != 0)
            {
                stiva[index] = 0, index--;
                if (index != 0 && ((i - stiva[index]) > max_len))
                {
                    max_len = i - stiva[index];
                }
            }
            else
            {
                index++, stiva[index] = i;
            }
        }
    }
    out << max_len;

    return 0;
}
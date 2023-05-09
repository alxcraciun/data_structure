#include <fstream>
#include <iostream>

std::ifstream in("vila2.in");
std::ofstream out("vila2.out");

int n, k, spatiu, v[100001], max_deque[100001], min_deque[100001];
int max_left = 1, max_right = 0, min_left = 1, min_right = 0;

int main()
{
    in >> n >> k;

    for (int i = 1; i <= n; i++)
        in >> v[i];

    for (int i = 1; i <= n; i++)
    {
        while (max_left <= max_right && v[i] >= v[max_deque[max_right]])
            max_right--;

        while (min_left <= min_right && v[i] <= v[min_deque[min_right]])
            min_right--;

        max_right++;
        max_deque[max_right] = i;

        min_right++;
        min_deque[min_right] = i;

        if (max_deque[max_left] == i - (k + 1))
            max_left++;

        if (min_deque[min_left] == i - (k + 1))
            min_left++;

        if (i >= k)
            spatiu = std::max(spatiu, v[max_deque[max_left]] - v[min_deque[min_left]]);
    }

    out << spatiu << '\n';

    in.close();
    out.close();

    return 0;
}
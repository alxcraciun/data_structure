#include <iostream>
#include <fstream>

std::ifstream in("deque.in");
std::ofstream out("deque.out");
int n, k, left = 0, right = 0, v[5000001], deque[5000001];
long int suma = 0;

int main()
{
  in >> n >> k;

  for (int i = 1; i <= n; i++)
    in >> v[i];

  for (int i = 1; i <= n; i++)
  {
    while (left <= right && v[i] <= v[deque[right]])
      right--;

    right++;
    deque[right] = i;

    if (deque[left] == i - k)
      left++;

    if (i >= k)
      suma += v[deque[left]];
  }

  out << suma << '\n';

  in.close();
  out.close();

  return 0;
}
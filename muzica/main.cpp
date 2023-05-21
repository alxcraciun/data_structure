#include <fstream>
#include <unordered_set>

std::ifstream in("muzica.in");
std::ofstream out("muzica.out");

long long N, M, A, B, C, D, E, common;
std::unordered_set<long long> playlist;

int main()
{
    in >> N >> M;
    in >> A >> B >> C >> D >> E;    

    for (long long i = 0; i < N; i++)
    {
        long long x;
        in >> x;
        playlist.insert(x);
    }

    long long common = 0;
    for (long long i = 0; i < M && !playlist.empty(); i++)
    {
        std::unordered_set<long long>::iterator adress = playlist.find(A);
        if (adress != playlist.end())
        {
            common++;
            playlist.erase(adress);
        }

        long long next_song = (C * B + D * A) % E;
        A = B;
        B = next_song;
    }

    out << common;

    in.close();
    out.close();

    return 0;
}
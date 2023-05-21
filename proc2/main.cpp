    #include <fstream>
    #include <functional>
    #include <queue>
    #include <utility>

    std::ifstream in("proc2.in");
    std::ofstream out("proc2.out");

    int N, M;

    std::priority_queue<
        int,
        std::vector<int>,
        std::greater<int>>
        processors;

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>>
        finished;

    int main()
    {
        in >> N >> M;
        for (int i = 0; i < N; i++)
        {
            processors.push(i+1);
        }

        for (int i = 0; i < M; i++)
        {
            int start, duration;
            in >> start >> duration;

            // clear used processors that finished their task
            while (!finished.empty() && finished.top().first <= start)
            {
                processors.push(finished.top().second);
                finished.pop();
            }

            finished.push(std::make_pair(start + duration, processors.top()));
            out << processors.top() << '\n';
            processors.pop();
        }

        in.close();
        out.close();

        return 0;
    }
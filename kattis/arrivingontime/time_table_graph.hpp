#include <vector>
#include <queue>
#include <limits>

namespace popup {
class Edge {
public:
    size_t from_;
    size_t to_;
    int64_t weight_;
    size_t starting_time_;
    size_t period_;
    Edge(size_t from, size_t to, size_t starting_time, size_t period, int64_t weight) {
        from_ = from;
        to_ = to;
        weight_ = weight;
        starting_time_ = starting_time;
        period_ = period;
    }
};

class Graph {
    size_t size_;
    size_t capacity_;
    std::vector<std::vector<Edge>> list_;
public:
    Graph(size_t size) {
        size_ = size;
        capacity_ = size;
        list_.resize(size);
    }

    void add_edge(size_t from, size_t to, int64_t start, int64_t period, int64_t weight) {
        list_[from].emplace_back(Edge(from, to, start, period, weight));
    };

    // Dijkstra
    int64_t dijkstra(size_t start, size_t from, size_t to){

        std::priority_queue<std::pair<int64_t, size_t>,
            std::vector<std::pair<int64_t, size_t>>,
            std::greater<std::pair<int64_t, size_t>>> queue;
        std::vector<int64_t> distances(capacity_, std::numeric_limits<int64_t>::max());
        std::vector<size_t> came_from(capacity_, std::numeric_limits<int64_t>::max());
        std::vector<bool> visited(capacity_, 0);

        distances[from] = start;
        queue.emplace(std::make_pair(start, from));
        while (!queue.empty()) {
            auto e = queue.top();
            queue.pop();
            auto current_node = e.second;
            auto current_time = e.first;

            if (visited[current_node]) {
                continue;
            }
            visited[current_node] = true;
            if (current_node == to) {
                break;
            }

            for (auto& edge : list_[current_node]) {
                auto node = edge.to_;
                size_t t_to_open;

                if (current_time <= (int64_t)edge.starting_time_) {
                    t_to_open = edge.starting_time_ - current_time;
                } else if (edge.period_ == 0) {
                    continue;
                } else {
                    t_to_open = (edge.period_ - 
                            ((current_time - edge.starting_time_)
                             % edge.period_)) % edge.period_;
                }

                size_t time_to_trav = current_time + edge.weight_ + t_to_open;

                if ((size_t)distances[node] > time_to_trav) {
                    distances[node] = time_to_trav;
                    queue.push(
                            std::make_pair(time_to_trav, edge.to_)
                            );
                    came_from[node] = edge.from_;
                }
            }
        }

        if (!visited[to])  {
            return std::numeric_limits<int64_t>::max();
        } else {
            return distances[to];
        }
    };

};
} // namespace popup

#include <iostream>
#include <set>
#include <fstream>

typedef unsigned long long val_type;

constexpr size_t n_vertexes = 50000;
constexpr size_t size_vertexes = n_vertexes + 1;

size_t parent[size_vertexes];
size_t rank[size_vertexes];
void make_set (size_t v) {
    parent[v] = v;
    rank[v] = 0;
}

size_t find_set (size_t v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (size_t a, size_t b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b])
            std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            ++rank[a];
    }
}

using namespace std;

size_t n, m;
val_type s;

struct weighted_edge_t
{
    size_t index;
    size_t from, to;
    val_type weight;

    friend std::ostream& operator<< (std::ostream& stream, const weighted_edge_t& we) {
       return stream << we.index << " " << we.from << " " << we.to << " " << we.weight;
    }
};
struct compare_weight_t
{
    bool operator()(const weighted_edge_t& a, const weighted_edge_t& b)
    {
        return a.weight > b.weight;
    }
};
multiset<weighted_edge_t, compare_weight_t> edges_sort;


unsigned long long Kruskals_algorithm()
{
    auto iter = edges_sort.begin();

    unsigned long long sum = 0;
    size_t k = 0;

    while(iter != edges_sort.end() && k <= n - 1)
    {
        auto edge = *iter;
        auto cur_iter = iter;
        iter++;
        if(find_set(edge.from) != find_set(edge.to)) {
            union_sets(edge.from, edge.to);
            sum += edge.weight;

            edges_sort.erase(cur_iter);
            k++;
        }
    }
    return sum;
}

set<size_t> edges;

int main()
{
    std::ifstream in_file;
    std::ofstream out_file;

    in_file.open("destroy.in");
    out_file.open("destroy.out");

    ///==================================================///
    std::istream &in = in_file;             /// = std::cin
    std::ostream &out = out_file;         /// = std::cout
    ///==================================================///

    in >> n >> m >> s;

    for(size_t i = 1; i <= n; i++)
    {
        make_set(i);
    }

    for(size_t i = 1; i <= m; i++)
    {
        size_t x, y;
        val_type w;
        in >> x >> y >> w;
        edges_sort.insert({i, x, y, w});
    }

    Kruskals_algorithm();

//    cout << Kruskals_algorithm() << endl;
//    for (const auto &item: edges_sort) {
//        cout << item << "\n";
//    }

    val_type sum = 0;
    for (auto riter = edges_sort.rbegin(); riter != edges_sort.rend(); ++riter) {
        if((double)sum + (double)riter->weight > (double)s)
            break;
        sum += riter->weight;
        edges.insert(riter->index);
    }

    out << edges.size() << endl;
    for (const auto &item: edges) {
        out << item << " ";
    }

    return 0;
}

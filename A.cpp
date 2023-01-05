#include <iostream>
#include <set>

typedef unsigned long long uint;

struct queue_t {
    uint n = 0;
    unsigned long long fine = 0;
    std::set<size_t> available_seats;

    explicit queue_t(size_t n, size_t max_d = SIZE_MAX) : n(n) {
        for (size_t i = 1; i <= std::min(n, max_d); i++)
            available_seats.insert(i);
    }

    void add(uint d, uint w) {
        if (d == 0)
            fine += w;
        else if (d < n) {
            auto iter = available_seats.upper_bound(d);

            if (iter != available_seats.begin()) {
                iter--;
                available_seats.erase(iter);
            } else
                fine += w;
        }
    }
};

using task_t = std::pair<uint, uint>;
struct task_comparator_t
{
    bool operator() (task_t const &one, task_t const &two)
    {
        return one.second > two.second;
    }
};

unsigned long long a_work(size_t n, uint *array) {
    std::multiset<task_t, task_comparator_t> sort_array;
    uint max_d = array[0];
    for (size_t i = 0; i < n; i++)
    {
        if (array[(2 * i) + 1] != 0)
        {
            sort_array.insert({array[2 * i], array[(2 * i) + 1]});
            if(array[2 * i] > max_d)
                max_d = array[2 * i];
        }
    }

    queue_t queue(n);

    for (const auto &item: sort_array)
        queue.add(item.first, item.second);


    return queue.fine;
}

#ifndef TEST_ON

#include <fstream>

template<typename T>
T read_const(std::istream& in) {
    T t;
    in >> t;
    return t;
}

int main() {
    std::ifstream in_file;
    std::ofstream out_file;

    in_file.open("schedule.in");
    out_file.open("schedule.out");

    ///==================================================///
    std::istream &in = in_file;             /// = std::cin
    std::ostream &out = out_file;         /// = std::cout
    ///==================================================///

    //const auto n = [&in](size_t t) { return in >> t, std::move(t); }({});
    const auto n = read_const<size_t>(in);

    uint *array = new uint[2 * n];

    for (size_t i = 0; i < 2 * n; i++)
        in >> array[i];

    out << a_work(n, array) << "\n";

    delete[] array;
    return 0;
}

#endif

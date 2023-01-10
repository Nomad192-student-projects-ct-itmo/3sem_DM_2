#include <iostream>
#include <set>

typedef unsigned long long val_type;

struct queue_t {
    val_type n = 0;
    unsigned long long fine = 0;
    std::set<size_t> available_seats;

    explicit queue_t(size_t n, size_t max_d = SIZE_MAX) : n(n) {
        for (size_t i = 1; i <= std::min(n, max_d); i++)
            available_seats.insert(i);
    }

    void add(val_type d, val_type w) {
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

using task_t = std::pair<val_type, val_type>;
struct task_comparator_t
{
    bool operator() (task_t const &one, task_t const &two)
    {
        return one.second > two.second;
    }
};

unsigned long long a_work(size_t n, val_type *array) {
    std::multiset<task_t, task_comparator_t> sort_array;
    val_type max_d = array[0];
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
    return std::move(t);
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

    val_type *array = new val_type[2 * n];

    for (size_t i = 0; i < 2 * n; i++)
        in >> array[i];

    out << a_work(n, array) << "\n";

    delete[] array;
    return 0;
}

#endif

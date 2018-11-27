#include <vector>
#include <iostream>
#include <thread>

void acc_func(const std::vector<int> &v, unsigned long long &acm, unsigned int beginIdx, unsigned int endIndex)
{
    acm = 0;
    for (unsigned int i = beginIdx; i < endIndex; i++)
    {
        acm += v[i];
    }
}

int main()
{
    std::vector<int> v(1000000000, 5);
    unsigned long long acm1 = 0;
    // unsigned long long acm2 = 0;
    acc_func(v, acm1, 0, v.size());
    // std::thread t1(acc_func, std::ref(v),
    //                std::ref(acm1), 0, v.size() / 2);
    // std::thread t2(acc_func, std::ref(v),
    //                std::ref(acm2), v.size() / 2, v.size());
    // t1.join();
    // t2.join();

    std::cout << "acm1: " << acm1 << '\n';
    // std::cout << "acm2: " << acm2 << '\n';
    // std::cout << "acm1 + acm2: " << acm1 + acm2 << '\n';
}
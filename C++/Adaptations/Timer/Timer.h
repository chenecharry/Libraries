#include<iostream>
#include<chrono>

// This code was developed on learncpp.com
// I took the code, and made it easy to
// use with shared object.

class Timer 
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;

public:
    Timer();

    void reset();
    double elapsed() const;
};

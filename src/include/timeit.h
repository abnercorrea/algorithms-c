//
// Created by Abner J Correa Jr on 3/22/21.
//

// TODO: create a library with this?

#ifndef ALGORITHMS_C_TIMEIT_H
#define ALGORITHMS_C_TIMEIT_H

#include <chrono>

// typedef std::chrono::high_resolution_clock::time_point TimeVar;
// #define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
// #define now() std::chrono::high_resolution_clock::now()

template<typename F, typename... Args>
double timeIt(F f, Args&&... args) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    f(std::forward<Args>(args)...);
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    // auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    return ms_double.count();
}

#endif

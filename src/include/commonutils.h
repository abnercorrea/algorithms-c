//
// Created by Abner Correa on 3/13/22.
//

#ifndef ALGORITHMS_C_COMMONUTILS_H
#define ALGORITHMS_C_COMMONUTILS_H

#include <sstream>

using namespace std;

#define max(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

template <typename Iterator>
string join(Iterator begin, Iterator end, char sep = '\n') {
    std::ostringstream out;

    if (begin != end) {
        out << *begin++;
        for (; begin != end; begin++) {
            out << sep << *begin;
        }
    }

    return out.str();
}

template <typename Container>
string join(Container const& c, char sep = ',') {
    using std::begin;
    using std::end;
    return join(begin(c), end(c), sep);
}

#endif //ALGORITHMS_C_COMMONUTILS_H

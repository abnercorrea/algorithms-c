//
// Created by Abner J Correa Jr on 4/26/21.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
//#include "../util/timeit.h"

using namespace std;

typedef unsigned long long ullint;

static ullint MEMOIZE_CAPACITY = 5000001;

// This fails multiple test cases in hackerrank...

/**
 * Calculates the length of the collatz sequence.
 * Requires at least collatzSeqLen[1] = 1 to be preset.
 * As an optimization, all powers of 2 can be easily calculated / preset.
 *
 * @param n
 * @param collatzSeqLen
 * @return
 */
ullint collatzSequenceLength(ullint n, vector<ullint> &collatzSeqLen) {
    for (ullint length = 0; true; length++) {
        if (n < MEMOIZE_CAPACITY && collatzSeqLen[n] != 0) {
            return length + collatzSeqLen[n];
        }
        n = (n % 2 == 0) ? n >> 1 : 3 * n + 1;
    }
}

/**
 * Recursion based implementation... the iterative one is much simpler.
 * collatzSeqLen[1] should be preset to 1, for the base case of the recursion.
 *
 * @param n
 * @param collatzSeqLen
 * @return
 */
ullint collatzSequenceLengthR(ullint n, vector<ullint> &collatzSeqLen) {
    if (collatzSeqLen[n] != 0) return collatzSeqLen[n];

    if (n % 2 == 0) {
        collatzSeqLen[n] = 1 + collatzSequenceLengthR(n >> 1, collatzSeqLen);
    }
    else {
        // watch out for int overflow !!!
        unsigned long c = 3 * n + 1;
        ullint steps = 1;
        while (c >= MEMOIZE_CAPACITY) {
            c = (c % 2 == 0) ? c >> 1 : 3 * c + 1;
            steps++;
        }
        collatzSeqLen[n] = steps + collatzSequenceLengthR(c, collatzSeqLen);
    }

    return collatzSeqLen[n];
}

map<ullint, ullint> longestCollatzSequence(vector<ullint> numbers) {
    sort(numbers.begin(), numbers.end());

    assert(numbers.back() < MEMOIZE_CAPACITY);

    vector<ullint> collatzSeqLen(MEMOIZE_CAPACITY);

    // Powers of 2 can be easily computed. (length(n) = log2(n) + 1, if n is a power of 2)
    // collatzSeqLen[1] = 1 is very important for recursion base case in "longestCollatzSequence"
    for (ullint i = 1, c = 1; i < MEMOIZE_CAPACITY; i *= 2) collatzSeqLen[i] = c++;

    map<ullint, ullint> result;

    for (ullint i = 0, n = 1, maxLengthN = 0, maxLength = 0; i < numbers.size(); n++) {
        collatzSeqLen[n] = collatzSequenceLength(n, collatzSeqLen);
        if (collatzSeqLen[n] >= maxLength) {
            maxLength = collatzSeqLen[n];
            maxLengthN = n;
        }
        if (n == numbers[i])  {
            result[n] = maxLengthN;
            i++;
        }
    }

    return result;
}

int main_hackerrank() {
    int t;
    cin >> t;
    vector<ullint> numbers(t);
    for (ullint i = 0; i < t; i++) cin >> numbers[i];

    map<ullint, ullint> result = longestCollatzSequence(numbers);

    for (ullint & number : numbers) cout << result[number] << endl;

    return 0;
}

int main() {
    int t = 10000;
    vector<ullint> numbers(t);

    for (ullint i = 0; i < t; i++) numbers[t - i - 1] = MEMOIZE_CAPACITY - i - 1;

    //cout << "Time taken I: " << timeIt(longestCollatzSequence, numbers) << "ms" << endl;
    //cout << "Time taken R: " << timeIt(longestCollatzSequenceR, numbers) << "ms" << endl;

    map<ullint, ullint> result = longestCollatzSequence(numbers);

    for (ullint & number : numbers) cout << result[number] << endl;

    return 0;
}

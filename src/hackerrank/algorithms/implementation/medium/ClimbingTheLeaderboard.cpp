//
// Created by Abner Correa on 3/5/22.
//

/*
 * Pay attention to:
 * - The input arrays are sorted
 * - The scores provided in the "player" input array belong to the same player.
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

// First attempt: very bad, runs through the ranked array multiple times, considers multiple players.
// 100, 90, 90, 80
// 70, 80, 105
vector<int> climbingLeaderboard1st(vector<int> ranked, vector<int> player) {
    vector<int> ranks(player.size());

    for (int i = 0; i < player.size(); i++) {
        int score = player[i], rank = 0, j = 0;

        for (; j < ranked.size() && score < ranked[j]; j++) {
            if (j == 0 || ranked[j] != ranked[j - 1]) {
                rank++;
            }
        }
        rank++;

        if (j == ranked.size() || score > ranked[j]) {
            ranked.insert(ranked.begin() + j, score);
        }

        ranks[i] = rank;
    }

    return ranks;
}

// 3, 5, 7
// 4
template <class c>
int binarySearch(vector<c> a, c key) {
    int start = 0, end = a.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[mid] == key) {
            return mid;
        }
        else if (a[mid] > key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return start;
}

// Second attempt: better since it uses binary search but still disregards fact that it's the same player.
// This version is a good option if the array "player" is not sorted and it has the scores for multiple players.
vector<int> climbingLeaderboard2nd(vector<int> ranked, vector<int> player) {
    vector<int> ranks(player.size());

    vector<int> score_rank;
    for (int i = 0; i < ranked.size(); i++) {
        if (i == 0 || ranked[i] != ranked[i - 1]) {
            score_rank.push_back(ranked[i]);
        }
    }

    for (int i = 0; i < player.size(); i++) {
        int score = player[i];
        int pos = binarySearch(score_rank, score);

        if (pos == score_rank.size() || score != score_rank[pos]) {
            score_rank.insert(score_rank.begin() + pos, score);
        }

        ranks[i] = pos + 1;
    }

    return ranks;
}

/*
 * Third attempt: Better, runs in linear time (gets 100% of the test cases) but still disregards fact that it's the same player.
 * ranked is sorted descending
 * player is sorted ascending
 */
vector<int> climbingLeaderboard3rd(vector<int> ranked, vector<int> player) {
    vector<int> ranks(player.size());

    vector<int> score_rank;
    for (int i = ranked.size() - 1; i >= 0 ; i--) {
        if (i == ranked.size() - 1 || ranked[i] != ranked[i + 1]) {
            score_rank.push_back(ranked[i]);
        }
    }

    for (int i = 0, j = 0; i < player.size(); i++) {
        int score = player[i];

        for (; j < score_rank.size() && score > score_rank[j]; j++);

        ranks[i] = score_rank.size() - j + ((score == score_rank[j]) ? 0 : 1);
    }

    return ranks;
}

/*
 * Fourth attempt: much better, linear time in the sum of the sizes of input arrays
 *
 * ranked is sorted descending
 * player is sorted ascending
 * player array has scores for the same player.
 */
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> ranks(player.size());

    // 80 80 70 70 60 50 40 40 30 20
    // 1 55 60 105
    //
    // rank = 1, 2, 3, 4, 5, 6, 7
    // score = 105, 60, 55, 1
    // j = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    // i = 3, 2, 1, 0
    // ranks = [8,4,3,1]
    for (int i = player.size() - 1, j = 0, rank = 1; i >= 0; i--) {
        int score = player[i];

        while (j < ranked.size() && score < ranked[j]) {
            j++;
            if (j == ranked.size() || ranked[j] != ranked[j - 1]) rank++;
        }

        ranks[i] = rank;
    }

    return ranks;
}

void testClimbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> ranks = climbingLeaderboard(ranked, player);

    for (int rank: ranks) {
        cout << rank << "\n";
    }

    cout << "\n";
}

int main() {
    testClimbingLeaderboard({100, 100, 50, 40, 40, 20, 10}, {5, 25, 50, 120});
    testClimbingLeaderboard({100, 90, 90, 80, 75, 60}, {50, 65, 77, 90, 102});

    return 0;
}



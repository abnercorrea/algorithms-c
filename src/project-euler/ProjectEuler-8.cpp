#include <iostream>
#include <vector>

using namespace std;

const string testN = "73167176531330624919225119674426574742355349194934"
                     "96983520312774506326239578318016984801869478851843"
                     "85861560789112949495459501737958331952853208805511"
                     "12540698747158523863050715693290963295227443043557"
                     "66896648950445244523161731856403098711121722383113"
                     "62229893423380308135336276614282806444486645238749"
                     "30358907296290491560440772390713810515859307960866"
                     "70172427121883998797908792274921901699720888093776"
                     "65727333001053367881220235421809751254540594752243"
                     "52584907711670556013604839586446706324415722155397"
                     "53697817977846174064955149290862569321978468622482"
                     "83972241375657056057490261407972968652414535100474"
                     "82166370484403199890008895243450658541227588666881"
                     "16427171479924442928230863465674813919123162824586"
                     "17866458359124566529476545682848912883142607690042"
                     "24219022671055626321111109370544217506941658960408"
                     "07198403850962455444362981230987879927244284909188"
                     "84580156166097919133875499200524063689912560717606"
                     "05886116467109405077541002256983155200055935729725"
                     "71636269561882670428252483600823257530420752963450";

long largestProduct(string n, int k, int left, int right) {
    long prod = 1;
    for (int j = left, nj = left + k; j < nj; j++) prod *= (n[j] - '0');
    long maxProd = prod;
    for (int i = left + 1; i <= right - k; i++) {
        // Divide by previous first, multiple by new last (in the k digits sequences)
        prod = (prod / (n[i - 1] - '0')) * (n[i + k - 1] - '0');
        maxProd = max(prod, maxProd);
    }
    return maxProd;
}

long largestProductInASeries(string n, int k) {
    long maxProd = 0;
    int left = 0;
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == '0') {
            if (i - left >= k) maxProd = max(largestProduct(n, k, left, i), maxProd);
            // watch out to always move left when a zero if found regardless of above.
            left = i + 1;
        }
    }
    if (n.length() - left >= k) maxProd = max(largestProduct(n, k, left, n.length()), maxProd);
    return maxProd;
}

int main(){
    cout << "3675356291 = " << largestProductInASeries("3675356291", 5) << endl;
    cout << "2709360626 = " << largestProductInASeries("2709360626", 5) << endl;

    cout << testN << '\n' << largestProductInASeries(testN, 4) << endl;
    cout << testN << '\n' << largestProductInASeries(testN, 13) << endl;

    return 0;
}
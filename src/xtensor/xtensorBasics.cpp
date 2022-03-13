//
// Created by Abner Correa on 3/7/22.
//
#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

void slicing() {
    xt::xarray<double> arr1
            {{1.0, 2.0, 3.0},
             {2.0, 5.0, 7.0},
             {2.0, 5.0, 7.0}};

    xt::xarray<double> arr2
            {5.0, 6.0, 7.0};

    xt::xarray<double> res = xt::view(arr1, 1) + arr2;

    std::cout << res << std::endl;
}

void reshape() {
    xt::xarray<int> arr
            {1, 2, 3, 4, 5, 6, 7, 8, 9};

    arr.reshape({3, 3});

    std::cout << arr;
}

void indexAccess() {
    xt::xarray<double> arr1
            {{1.0, 2.0, 3.0},
             {2.0, 5.0, 7.0},
             {2.0, 5.0, 7.0}};

    std::cout << arr1(0, 0) << std::endl;

    xt::xarray<int> arr2
            {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << arr2(0);
}

void broadcasting() {
    xt::xarray<double> arr1
            {1.0, 2.0, 3.0};

    xt::xarray<unsigned int> arr2
            {4, 5, 6, 7};

    arr2.reshape({4, 1});

    xt::xarray<double> res = xt::pow(arr1, arr2);

    std::cout << res;
}

int main(int argc, char* argv[]) {
    slicing();
    reshape();
    indexAccess();
    broadcasting();

    return 0;
}

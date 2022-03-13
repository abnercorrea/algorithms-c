//
// Created by Abner Correa on 3/7/22.
//

#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/*
 * The expression engine avoids the evaluation of intermediate results and their storage in temporary arrays,
 * so you can achieve the same performance as if you had written a simple loop.
 */
xt::xarray<double> expressions() {
    xt::xarray<double> x = {1, 2, 3};
    xt::xarray<double> y = {3, 2, 1};
    xt::xarray<double> z = {6, 5, 4};
    xt::xarray<double> w = {10, 20, 30};

    // The result is an xexpression which offers the same interface as an N-dimensional array but does not hold any value.
    auto f = x + y * sin(z);
    auto f2 = w + 2 * cos(f);

    return f2;
}

/*
 * Values are only computed upon access or when the expression is assigned to a container.
 */
void lazyEvaluation() {
    auto f = expressions();

    std::cout << f(0) << "\n";
    std::cout << f(1) << "\n";
}

void forcingEvaluation() {
    xt::xarray<double> a = {1, 2, 3};
    xt::xarray<double> b = {3, 2, 1};

    // unevaluated xexpression!
    auto calc = a + b;
    // a rvalue container xarray!
    auto&& e = xt::eval(calc);
    // this just returns a reference to the existing container
    auto&& a_ref = xt::eval(a);
}

int main(int argc, char* argv[]) {
    std::cout << expressions()(0) << "\n";
    std::cout << expressions()(1) << "\n";

    lazyEvaluation();

    return 0;
}

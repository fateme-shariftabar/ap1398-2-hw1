// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.

// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:

// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "aphw1.h"
#include <iostream>
#include <vector>
#include "gtest/gtest.h"
namespace
{
TEST(APHW1Test, getDataFunctionTest)
{
    std::vector<std::vector<double>> data{getData("AP-Data.csv")};
    std::cout << "getData Test here!" << std::endl;
    EXPECT_EQ(1, data[0][0]);
    EXPECT_EQ(14.23, data[0][7]);
}
TEST(APHW1Test, gradeFunctionTest)
{
    std::vector<double> student{1, 2, 3, 4, 5, 6, 7};
    std::vector<double> w (7, 1);
    std::cout << "grade Test here!" << std::endl;
    EXPECT_EQ(28, grade(w, student));
}
TEST(APHW1Test, costFunctionTest)
{
    std::vector<std::vector<double>> data{getData("AP-Data.csv")};
    std::vector<double> w (7, 1);
    std::cout << "CostFunction Test here!" << std::endl;
    EXPECT_TRUE((48 < J(w, data)) && (49 > J(w, data)));
}
TEST(APHW1Test, trainFunctionTest)
{
    std::vector<std::vector<double>> data{getData("AP-Data.csv")};
    std::vector<double> w (7, 0);
    w = train(data, w, 0.01, 500, 0.01, false);
    std::cout<<"Weights...\n";
    for(size_t i{}; i<w.size(); std::cout << w[i++] << " ,");
    std::cout<<"\n";
    EXPECT_TRUE((w[0]>5) && (w[0]<6) && (w[6] > 2) && (w[6] < 3));
}
} // namespace

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
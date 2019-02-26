//
//  main.cpp
//  CPUCaches
//
//  Created by Neil on 2019/2/26.
//  Copyright © 2019 Neil. All rights reserved.
//

#include <chrono>
#include <iostream>
#include "MatrixTraversals.hpp"

using namespace std;
using Clock = chrono::steady_clock;

int main() {
    const int TEST_COUNT = 1024;
    
    Clock::time_point start;
    Clock::duration timeRowMajor, timeColumnMajor;
    
    /**
     * Matrix Traversal test
     */
    start = Clock::now();
    for (int i=0; i<TEST_COUNT; i++) {
        sumMatrixRowMajor();
    }
    timeRowMajor = Clock::now()-start;
    
    start = Clock::now();
    for (int i=0; i<TEST_COUNT; i++) {
        sumMatrixColumnMajor();
    }
    timeColumnMajor = Clock::now()-start;
    
    float t1 = chrono::duration_cast<chrono::duration<float>>(timeRowMajor).count();
    float t2 = chrono::duration_cast<chrono::duration<float>>(timeColumnMajor).count();
    float r = t2 / t1;
    
    cout << "RowMajor Time = " << t1
    << ", ColumnMajor time = " << t2 << ", ColumnMajor/RowMajor = " << r << endl;
    
    return 0;
}

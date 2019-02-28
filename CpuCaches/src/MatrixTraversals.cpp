//
//  MatrixTraversals.cpp
//  CPUCaches
//
//  Created by Neil on 2019/2/26.
//  Copyright © 2019 Neil. All rights reserved.
//

#include "MatrixTraversals.hpp"

const int ROW = 1024;
const int COL = 1024;

void sumMatrixRowMajor(){
    float m[ROW][COL];
    float sum =0;
    
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            sum+=m[i][j];
        }
    }
}

void sumMatrixColumnMajor(){
    float m[ROW][COL];
    float sum =0;
    
    for (int j=0; j<COL; j++) {
        for (int i=0; i<ROW; i++) {
            sum+=m[i][j];
        }
    }
}

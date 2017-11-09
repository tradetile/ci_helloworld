//
// CI Hello World
//
// Copyright (C) 2017 Assured Information Security, Inc.
// Author: Rian Quinn        <quinnr@ainfosec.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <producer.h>
#include <consumer.h>
#include <math.h>

void computeStats (int numbers[], int length);

int
MAIN(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    producer p{};
    consumer c{&p};

    // test dynamic.
    int numbers[] = {1,2,4};
    computeStats(numbers, 3);
    computeStats(numbers, 1);
    computeStats(numbers, 0);

    return 0;
}

/**
* Example Data Flow - Stats
*/
void computeStats (int numbers[], int length)
{
    //int length = numbers.length;
    double med, var, sd, mean, sum, varsum;    
    sum = 0.0;
    for (int i = 0; i < length; i++)
    {
        sum += numbers [ i ];
    }
    med = numbers [length / 2 ]; 
    mean = sum / (double) length;
    varsum = 0.0;
    for (int i = 0; i < length; i++)
    {
        varsum = varsum + ((numbers [ i ] - mean) * (numbers [ i ] - mean));
    }
    var = varsum / ( length - 1 ); 
    sd = sqrt ( var );

    printf("length: %d \n", length);
    printf("mean: %f \n", mean);
    printf("median: %f \n", med);
    printf("variance: %f \n", var);
    printf("standard deviation: %f \n", sd);
    return;
}

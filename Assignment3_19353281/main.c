//
// Created by Yiming Zhao on 2020/5/13.
//

#include <stdio.h>
#include <CUnit.h>
#include <Basic.h>

#include "avg_and_max.h"
//Define all the cases

void test_max(void){
    //p stands for positive
    //n stands for negative
    //z stands for 0
    //d stands for different
    //i stands for identical
    //s stands for single
    double p_d[5] = {1,2,3,4,5};//The case where all numbers are positive number while being different
    double p_s[1] = {8};//The case where there's only one positive number
    double n_d[3] = {-6,-5,-1};//The case where all numbers are negative number while being different
    double pn_d[4] = {-1,-2,1,-9};//The case where contain both positive and negative number while being different
    double p_i[3] = {2,2,2};//The case that contain identical positive numbers
    double n_i[3] = {-1,-1,-1};//The case that contain negative identical numbers
    double z_s[1] = {0};//The case where a single 0 is given
    double n_s[1] = {-2};//The case where a single 0 is given
    CU_ASSERT(max(p_d,5) == 5);
    CU_ASSERT(max(p_s,1) == 8);
    CU_ASSERT(max(n_d,3) == -1);
    CU_ASSERT(max(pn_d,4) == 1);
    CU_ASSERT(max(p_i,3) == 2);
    CU_ASSERT(max(n_i,3) == -1);
    CU_ASSERT(max(z_s,1) == 0);
    CU_ASSERT(max(n_s,1) == -2);
}
void test_avg(void) {
    //p stands for positive
    //n stands for negative
    //z stands for 0
    //m stands for multiple
    //s stands for single
    double p_m[5] = {1,2,3};//The case where multiple positive numbers are given
    double p_s[1] = {7};//The case where there's only one positive number
    double z_s[1] = {0};//The case where a single 0 is given
    double n_s[1] = {-5};//The case where a negative number is given
    double n_m[3] = {-2,-3,-1};//The case where multiple negative numbers are given
    double z_m[3] = {0,0,0};//The case where all numbers are 0
    CU_ASSERT(average(p_m,3) == 2);
    CU_ASSERT(average(p_s,1) == 8);
    CU_ASSERT(average(z_s,1) == 0);
    CU_ASSERT(average(n_s,1) == -5);
    CU_ASSERT(average(n_m,3) == -2);
    CU_ASSERT(average(z_m,3) == 0);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("max_test", 0, 0);//Separate suites for the two tests
    CU_add_test(suite, "max_fun", test_max);
    CU_pSuite suite2 = CU_add_suite("avg_test", 0, 0);
    CU_add_test(suite2, "avg_fun", test_avg);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}





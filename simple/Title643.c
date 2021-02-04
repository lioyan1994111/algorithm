//
// Created by 李延 on 2021/2/4.
//
/*
 *643. 子数组最大平均数 I
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

示例：

输入：[1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75

提示：

1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。

 */

double findMaxAverage(int* nums, int numsSize, int k){
    int maxSum = 0;
    int lastSum =0;
    for(int i = 0; i < k; i ++){
        maxSum += nums[i];
    }
    lastSum = maxSum;
    for(int i = k; i < numsSize; i ++){
        int thisSum = lastSum + nums[i] - nums[i-k];
        if(thisSum > maxSum){
            maxSum = thisSum;
        }
        lastSum = thisSum;
    }
    return 1.0*maxSum/k;
}
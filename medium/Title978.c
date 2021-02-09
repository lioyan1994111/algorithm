//
// Created by 李延 on 2021/2/6.
//

#include <stdbool.h>

/*
 *
当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：

若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。

 

示例 1：

输入：[9,4,2,10,7,8,8,1,9]
输出：5
解释：(A[1] > A[2] < A[3] > A[4] < A[5])
示例 2：

输入：[4,8,12,16]
输出：2
示例 3：

输入：[100]
输出：1
 

提示：

1 <= A.length <= 40000
0 <= A[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-turbulent-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
int maxTurbulenceSize(int *arr, int arrSize) {
    int maxSizeA = 0;
    int maxSizeB = 0;
    int lestSizeA = 0;
    int lestSizeB = 0;

    for (int i = 0; i < arrSize; i++) {
        if (i == 0) {
            maxSizeA = 1;
            lestSizeA = 1;
            maxSizeB = 1;
            lestSizeB = 1;
            continue;
        }
        int thisNum = arr[i];
        int lestNum = arr[i - 1];
        bool flayA = false;
        bool flayB = false;
        if (i % 2 == 0) {

            if(thisNum < lestNum){
                flayA = true;
            } else if(thisNum != lestNum){
                flayB = true;
            }
        } else {
            if(thisNum > lestNum){
                flayA = true;
            } else if(thisNum != lestNum){
                flayB = true;
            }
        }
        if(flayA){
            lestSizeA++;
        } else{
            lestSizeA = 1;
        }
        if(flayB){
            lestSizeB++;
        } else{
            lestSizeB = 1;
        }

        if(maxSizeA < lestSizeA){
            maxSizeA = lestSizeA;
        }
        if(maxSizeB < lestSizeB){
            maxSizeB = lestSizeB;
        }

    }
    if(maxSizeA > maxSizeB){
        return  maxSizeA;
    } else{
        return maxSizeB;
    }

}
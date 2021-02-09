//
// Created by 李延 on 2021/2/9.
//
int subarraysWithKDistinctMax(int *pInt, int size, int k);

/*
 *
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

返回 A 中好子数组的数目。

 

示例 1：

输入：A = [1,2,1,2,3], K = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
示例 2：

输入：A = [1,2,1,3,4], K = 3
输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 

提示：

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarrays-with-k-different-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 */


int subarraysWithKDistinct(int *A, int ASize, int K) {
    return subarraysWithKDistinctMax(A, ASize, K) - subarraysWithKDistinctMax(A, ASize, K - 1);
}

int subarraysWithKDistinctMax(int *A, int ASize, int k) {
    if(k == 0){
        return 0;
    }
    int countNum[ASize + 1];
    for (int i = 0; i < ASize + 1; i++) {
        countNum[i] = 0;
    }
    int findSize = 0;
    int needSize = 0;
    int leftNum = 0;
    for (int i = 0; i < ASize; i++) {
        int thisNum = A[i];
        int thisSum = countNum[thisNum];
        countNum[thisNum]++;
        if (thisSum == 0) {
            findSize++;
            if (findSize == k) {
                int a = i - leftNum + 1;
                needSize += (a + 1) * a / 2;
            } else if (findSize > k) {
                while (findSize > k) {
                    int leftNumNum = A[leftNum];
                    int leftNumSum = countNum[leftNumNum];
                    countNum[leftNumNum]--;
                    leftNum++;
                    //说明只出现了一次
                    if (leftNumSum == 1) {
                        int a = i - leftNum + 1;
                        needSize += a;
                        findSize--;
                    }
                }

            }

        } else {
            if (findSize == k) {
                int a = i - leftNum + 1;
                needSize += a;
            }
        }


    }
    if(needSize == 0){
        return (ASize + 1) * ASize / 2;
    }


    return needSize;
}

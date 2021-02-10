//
// Created by 李延 on 2021/2/10.
//

#include <stdbool.h>
#include <string.h>

/*
 *
 *
 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

bool checkInclusion(char *s1, char *s2) {
    int a[26];
    int b[26];

    for (int i = 0; i < 26; i++) {
        a[i] = 0;
        b[i] = 0;
    }

    int n = strlen(s1);
    for (int i = 0; i < n; i++) {
        a[s1[i]-'a']++;
        b[s1[i]-'a']++;
    }

    int n2 = strlen(s2);
    for (int i = 0; i < n2; i++) {
        int thisNum = a[s2[i]-'a'];
        int eqNum = 0;
        if (thisNum != 0) {
            int j = i;
            while (thisNum != 0 ) {
                eqNum++;
                a[s2[j]-'a']--;
                j++;
                if(j >= n2){
                    break;
                }
                thisNum = a[s2[j]-'a'];
            }

        }
        if (eqNum == n) {
            return true;
        } else {
            for (int i = 0; i < 26; i++) {
                a[i] = b[i];
            }

        }
    }
    return false;


}


bool checkInclusion2(char *s1, char *s2) {
    int a[26];

    for (int i = 0; i < 26; i++) {
        a[i] = 0;
    }

    int n = strlen(s1);
    for (int i = 0; i < n; i++) {
        a[s1[i]-'a']++;
    }

    int n2 = strlen(s2);
    int eqNum = 0;
    for (int i = 0,j = 0; i < n2; i++,j++) {
        int thisNum = a[s2[i]-'a'];
        if (thisNum != 0) {
            while (thisNum != 0 ) {
                eqNum++;
                a[s2[i]-'a']--;
                i++;
                if(i >= n2){
                    break;
                }
                thisNum = a[s2[i]-'a'];
            }

        }
        if (eqNum == n) {
            return true;
        } else if(i != j){
            a[s2[j]-'a']++;
            eqNum -=1;
            i -= 1;
        }
    }
    return false;


}
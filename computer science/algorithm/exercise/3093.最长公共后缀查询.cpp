#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3093 lang=cpp
 *
 * [3093] 最长公共后缀查询
 */

// @lc code=start
class TrieNode {
public:
    TrieNode* children[26] = {nullptr} ;
    int minlen = INT_MAX;
    int maxlen = INT_MIN;
};

class Solution {



public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();

        // 构建字典树
        for(string& word : wordsContainer){
            TrieNode* cur = root;
            int n = word.size();
            // 反向插入单词
            for(int i = n - 1; i >= 0; --i){
                int idx = word[i] - 'a';
                if(!cur->children[idx]){
                    cur->children[idx] = new TrieNode();
                }
                cur = cur->children[idx];
            }
        }
    }
};
// @lc code=end

// // 字典树节点
//     class TrieNode {
//         TrieNode[] children = new TrieNode[26];
//         // 到达该节点的 最短字符串长度
//         int minLen = Integer.MAX_VALUE;
//         // 对应最小下标
//         int minIndex = Integer.MAX_VALUE;
//     }

//     // 根节点
//     private TrieNode root = new TrieNode();

//     public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
//         // 步骤1：从后往前构建字典树，每个节点存最短长度、最小下标
//         for (int idx = 0; idx < wordsContainer.length; idx++) {
//             String s = wordsContainer[idx];
//             int len = s.length();
//             TrieNode cur = root;

//             // 从后往前遍历
//             for (int i = len - 1; i >= 0; i--) {
//                 int c = s.charAt(i) - 'a';
//                 if (cur.children[c] == null) {
//                     cur.children[c] = new TrieNode();
//                 }
//                 cur = cur.children[c];

//                 // 更新：更短 → 替换；长度相同 → 保留更早下标
//                 if (len < cur.minLen) {
//                     cur.minLen = len;
//                     cur.minIndex = idx;
//                 }
//             }
//         }

//         // 步骤2：预处理全局最短字符串下标（无任何匹配时用）
//         int globalMinIndex = 0;
//         int globalMinLen = wordsContainer[0].length();
//         for (int i = 1; i < wordsContainer.length; i++) {
//             if (wordsContainer[i].length() < globalMinLen) {
//                 globalMinLen = wordsContainer[i].length();
//                 globalMinIndex = i;
//             }
//         }

//         // 步骤3：处理每个查询
//         int[] ans = new int[wordsQuery.length];
//         for (int qIdx = 0; qIdx < wordsQuery.length; qIdx++) {
//             String q = wordsQuery[qIdx];
//             TrieNode cur = root;
//             int bestIndex = globalMinIndex; // 默认全局最短

//             // 从后往前查，走到最远能走的节点
//             for (int i = q.length() - 1; i >= 0; i--) {
//                 int c = q.charAt(i) - 'a';
//                 if (cur.children[c] == null) {
//                     break;
//                 }
//                 cur = cur.children[c];
//                 bestIndex = cur.minIndex; // 每走一步就更新最优答案
//             }

//             ans[qIdx] = bestIndex;
//         }

//         return ans;
//     }
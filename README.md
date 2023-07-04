下表是本仓库所包含的题目，后续将会持续更新 ~



### leetcode

| 题号 | 难度   | 英文题目                                                  | 中文题目                                   | 分类       | 思路                                     | 相关           |
| ---- | ------ | --------------------------------------------------------- | ------------------------------------------ | ---------- | ---------------------------------------- | -------------- |
| 1    | Easy   | Two Sum                                                   | 两数之和                                   | 数组       | 哈希映射                                 | 15, 18         |
| 2    | Medium | Add Two Numbers                                           | 两数相加                                   | 链表       | 双指针                                   |                |
| 3    | Medium | Longest Substring Without Repeating Characters            | 无重复字符的最长子串                       | 字符串     | 滑动窗口<br/>哈希集合<br/>哈希映射       |                |
| 4    | Hard   | Median of Two Sorted Arrays                               | 寻找两个正序数组的中位数                   | 数组       | 归并<br/>二分查找                        |                |
| 5    | Medium | Longest Palindromic Substring                             | 最长回文子串                               | 字符串     | 动态规划                                 | 9              |
| 6    | Medium | ZigZag Conversion                                         | Z 字形变换                                 | 字符串     | 找规律                                   |                |
| 7    | Easy   | Reverse Integer                                           | 整数反转                                   | 数字       | 暴力模拟                                 | 9              |
| 8    | Medium | String to Integer (atoi)                                  | 字符串转换整数 (atoi)                      | 字符串     | 暴力模拟                                 |                |
| 9    | Easy   | Palindrome Number                                         | 回文数                                     | 数字       | 暴力模拟                                 | 5, 7           |
| 10   | Hard   | Regular Expression Matching                               | 正则表达式匹配                             | 字符串     | 递归<br/>动态规划                        | 44             |
| 11   | Medium | Container With Most Water                                 | 盛最多水的容器                             | 数组       | 左右指针                                 | 42             |
| 12   | Medium | Integer to Roman                                          | 整数转罗马数字                             | 数字       | 硬编码<br/>贪心算法                      | 13             |
| 13   | Easy   | Roman to Integer                                          | 罗马数字转整数                             | 字符串     | 找规律                                   | 12             |
| 14   | Easy   | Longest Common Prefix                                     | 最长公共前缀                               | 字符串     | 暴力模拟                                 |                |
| 15   | Medium | 3Sum                                                      | 三数之和                                   | 数组       | 左右指针                                 | 1, 16, 18      |
| 16   | Medium | 3Sum Closest                                              | 最接近的三数之和                           | 数组       | 左右指针                                 | 11, 15         |
| 17   | Medium | Letter Combinations of a Phone Number                     | 电话号码的字母组合                         | 字符串     | 回溯                                     |                |
| 18   | Medium | 4Sum                                                      | 四数之和                                   | 数组       | 左右指针                                 | 1, 15          |
| 19   | Medium | Remove Nth Node From End of List                          | 删除链表的倒数第 N 个结点                  | 链表       | 栈<br/>快慢指针                          |                |
| 20   | Easy   | Valid Parentheses                                         | 有效的括号                                 | 字符串     | 栈                                       | 32             |
| 21   | Easy   | Merge Two Sorted Lists                                    | 合并两个有序链表                           | 链表       | 归并                                     | 23             |
| 22   | Medium | Generate Parentheses                                      | 括号生成                                   | 字符串     | 回溯                                     |                |
| 23   | Hard   | Merge k Sorted Lists                                      | 合并K个升序链表                            | 链表       | 归并<br/>优先队列<br/>分治               | 21             |
| 24   | Medium | Swap Nodes in Pairs                                       | 两两交换链表中的节点                       | 链表       | 递归<br/>迭代                            | 25             |
| 25   | Hard   | Reverse Nodes in k-Group                                  | K 个一组翻转链表                           | 链表       | 递归<br/>迭代                            | 24             |
| 26   | Easy   | Remove Duplicates from Sorted Array                       | 删除有序数组中的重复项                     | 数组       | 快慢指针                                 | 80             |
| 27   | Easy   | Remove Element                                            | 移除元素                                   | 数组       | 左右指针                                 |                |
| 28   | Easy   | Implement strStr()                                        | 实现 strStr()                              | 字符串     | 暴力模拟<br/>KMP                         |                |
| 29   | Medium | Divide Two Integers                                       | 两数相除                                   | 数字       | 倍增                                     | 50             |
| 30   | Hard   | Substring with Concatenation of All Words                 | 串联所有单词的子串                         | 字符串     | 哈希映射<br/>滑动窗口                    |                |
| 31   | Medium | Next Permutation                                          | 下一个排列                                 | 数组       | 背景规则                                 |                |
| 32   | Hard   | Longest Valid Parentheses                                 | 最长有效括号                               | 字符串     | 栈<br/>双向遍历<br/>动态规划             | 20             |
| 33   | Medium | Search in Rotated Sorted Array                            | 搜索旋转排序数组                           | 数组       | 二分查找                                 | 81             |
| 34   | Medium | Find First and Last Position of Element in Sorted Array   | 在排序数组中查找元素的第一个和最后一个位置 | 数组       | 二分查找                                 |                |
| 35   | Easy   | Search Insert Position                                    | 搜索插入位置                               | 数组       | 二分查找                                 |                |
| 36   | Medium | Valid Sudoku                                              | 有效的数独                                 | 数组       | 哈希映射                                 | 37             |
| 37   | Hard   | Sudoku Solver                                             | 解数独                                     | 数组       | 回溯                                     | 36             |
| 38   | Medium | Count and Say                                             | 外观数列                                   | 字符串     | 迭代                                     |                |
| 39   | Medium | Combination Sum                                           | 组合总和                                   | 数组       | 回溯                                     | 40             |
| 40   | Medium | Combination Sum II                                        | 组合总和 II                                | 数组       | 回溯                                     | 39             |
| 41   | Hard   | First Missing Positive                                    | 缺失的第一个正数                           | 数组       | 原地哈希                                 |                |
| 42   | Hard   | Trapping Rain Water                                       | 接雨水                                     | 数组       | 单调栈<br/>左右指针<br/>动态规划         | 11, 84         |
| 43   | Medium | Multiply Strings                                          | 字符串相乘                                 | 字符串     | 暴力模拟                                 |                |
| 44   | Hard   | Wildcard Matching                                         | 通配符匹配                                 | 字符串     | 贪心<br/>动态规划                        | 10             |
| 45   | Medium | Jump Game II                                              | 跳跃游戏 II                                | 数组       | 贪心<br/>动态规划                        | 55             |
| 46   | Medium | Permutations                                              | 全排列                                     | 数组       | 回溯                                     | 47             |
| 47   | Medium | Permutations II                                           | 全排列 II                                  | 数组       | 回溯                                     | 46             |
| 48   | Medium | Rotate Image                                              | 旋转图像                                   | 数组       | 找规律                                   |                |
| 49   | Medium | Group Anagrams                                            | 字母异位词分组                             | 数组       | 哈希映射                                 |                |
| 50   | Medium | Pow(x, n)                                                 | Pow(x, n)                                  | 数字       | 递归<br/>迭代<br/>倍增                   | 29             |
| 51   | Hard   | N-Queens                                                  | N 皇后                                     | 数组       | 回溯                                     | 52             |
| 52   | Hard   | N-Queens II                                               | N皇后 II                                   | 数组       | 回溯                                     | 51             |
| 53   | Easy   | Maximum Subarray                                          | 最大子数组和                               | 数组       | 动态规划                                 |                |
| 54   | Medium | Spiral Matrix                                             | 螺旋矩阵                                   | 数组       | 暴力模拟                                 | 59             |
| 55   | Medium | Jump Game                                                 | 跳跃游戏                                   | 数组       | 贪心                                     | 45             |
| 56   | Medium | Merge Intervals                                           | 合并区间                                   | 数组       | 双指针                                   | 57             |
| 57   | Medium | Insert Interval                                           | 插入区间                                   | 数组       | 暴力模拟                                 | 56             |
| 58   | Easy   | Length of Last Word                                       | 最后一个单词的长度                         | 字符串     | 暴力模拟                                 |                |
| 59   | Medium | Spiral Matrix II                                          | 螺旋矩阵 II                                | 数组       | 暴力模拟                                 | 54             |
| 60   | Hard   | Permutation Sequence                                      | 排列序列                                   | 数字       | 数学方法                                 |                |
| 61   | Medium | Rotate List                                               | 旋转链表                                   | 链表       | 暴力模拟                                 |                |
| 62   | Medium | Unique Paths                                              | 不同路径                                   | 数组       | 动态规划<br/>数学方法                    | 63, 64         |
| 63   | Medium | Unique Paths II                                           | 不同路径 II                                | 数组       | 动态规划                                 | 62             |
| 64   | Medium | Minimum Path Sum                                          | 最小路径和                                 | 数组       | 动态规划                                 | 62             |
| 65   | Hard   | Valid Number                                              | 有效数字                                   | 数字       | 状态机<br/>暴力模拟                      |                |
| 66   | Easy   | Plus One                                                  | 加一                                       | 数组       | 暴力模拟                                 |                |
| 67   | Easy   | Add Binary                                                | 二进制求和                                 | 字符串     | 暴力模拟                                 |                |
| 68   | Hard   | Text Justification                                        | 文本左右对齐                               | 字符串     | 暴力模拟                                 |                |
| 69   | Easy   | Sqrt(x)                                                   | x 的平方根                                 | 数字       | 顺序查找<br/>二分查找                    |                |
| 70   | Easy   | Climbing Stairs                                           | 爬楼梯                                     | 数字       | 动态规划                                 |                |
| 71   | Medium | Simplify Path                                             | 简化路径                                   | 字符串     | 暴力模拟                                 |                |
| 72   | Hard   | Edit Distance                                             | 编辑距离                                   | 字符串     | 动态规划                                 |                |
| 73   | Medium | Set Matrix Zeroes                                         | 矩阵置零                                   | 数组       | 暴力模拟                                 |                |
| 74   | Medium | Search a 2D Matrix                                        | 搜索二维矩阵                               | 数组       | 二分查找                                 | 79             |
| 75   | Medium | Sort Colors                                               | 颜色分类                                   | 数组       | 暴力模拟                                 |                |
| 76   | Hard   | Minimum Window Substring                                  | 最小覆盖子串                               | 字符串     | 哈希映射<br/>滑动窗口                    |                |
| 77   | Medium | Combinations                                              | 组合                                       | 数组       | 回溯                                     |                |
| 78   | Medium | Subsets                                                   | 子集                                       | 数组       | 回溯                                     |                |
| 79   | Medium | Word Search                                               | 单词搜索                                   | 数组       | 回溯                                     | 74             |
| 80   | Medium | Remove Duplicates from Sorted Array II                    | 删除有序数组中的重复项 II                  | 数组       | 快慢指针                                 | 26             |
| 81   | Medium | Search in Rotated Sorted Array II                         | 搜索旋转排序数组 II                        | 数组       | 二分查找                                 | 33             |
| 82   | Medium | Remove Duplicates from Sorted List II                     | 删除排序链表中的重复元素 II                | 链表       | 快慢指针                                 | 26, 83         |
| 83   | Easy   | Remove Duplicates from Sorted List                        | 删除排序链表中的重复元素                   | 链表       | 快慢指针                                 | 82             |
| 84   | Hard   | Largest Rectangle in Histogram                            | 柱状图中最大的矩形                         | 数组       | 单调栈                                   | 42, 85         |
| 85   | Hard   | Maximal Rectangle                                         | 最大矩形                                   | 数组       | 单调栈                                   | 84             |
| 86   | Medium | Partition List                                            | 分隔链表                                   | 链表       | 暴力模拟                                 |                |
| 87   | Hard   | Scramble String                                           | 扰乱字符串                                 | 字符串     | 动态规划                                 |                |
| 94   | Easy   | Binary Tree Inorder Traversal                             | 二叉树的中序遍历                           | 二叉树     | 递归                                     |                |
| 96   | Medium | Unique Binary Search Trees                                | 不同的二叉搜索树                           | 二叉搜索树 | 递归                                     |                |
| 98   | Medium | Validate Binary Search Tree                               | 验证二叉搜索树                             | 二叉树     | 递归                                     |                |
| 101  | Easy   | Symmetric Tree                                            | 对称二叉树                                 | 二叉树     | 递归                                     |                |
| 102  | Medium | Binary Tree Level Order Traversal                         | 二叉树的层序遍历                           | 二叉树     | 广度优先搜索                             |                |
| 104  | Easy   | Maximum Depth of Binary Tree                              | 二叉树的最大深度                           | 二叉树     | 递归                                     |                |
| 105  | Medium | Construct Binary Tree from Preorder and Inorder Traversal | 从前序与中序遍历序列构造二叉树             | 二叉树     | 递归                                     |                |
| 111  | Easy   | Minimum Depth of Binary Tree                              | 二叉树的最小深度                           | 二叉树     | 深度优先搜索<br/>广度优先搜索            |                |
| 114  | Medium | Flatten Binary Tree to Linked List                        | 二叉树展开为链表                           | 二叉树     | 递归                                     |                |
| 121  | Easy   | Best Time to Buy and Sell Stock                           | 买卖股票的最佳时机                         | 数组       | 预处理<br/>逆过程                        |                |
| 124  | Hard   | Binary Tree Maximum Path Sum                              | 二叉树中的最大路径和                       | 二叉树     | 递归                                     | 543            |
| 127  | Hard   | Word Ladder                                               | 单词接龙                                   | 字符串     | 广度优先搜索                             | 752            |
| 128  | Medium | Longest Consecutive Sequence                              | 最长连续序列                               | 数组       | 哈希                                     |                |
| 130  | Medium | Surrounded Regions                                        | 被围绕的区域                               | 数组       | 深度优先搜索<br/>广度优先搜索            | 200            |
| 136  | Easy   | Single Number                                             | 只出现一次的数字                           | 数组       | 位运算                                   |                |
| 139  | Medium | Word Break                                                | 单词拆分                                   | 字符串     | 哈希<br/>动态规划                        |                |
| 141  | Easy   | Linked List Cycle                                         | 环形链表                                   | 链表       | 快慢指针                                 |                |
| 142  | Medium | Linked List Cycle II                                      | 环形链表 II                                | 链表       | 快慢指针                                 |                |
| 148  | Medium | Sort List                                                 | 排序链表                                   | 链表       | 归并排序                                 |                |
| 152  | Medium | Maximum Product Subarray                                  | 乘积最大子数组                             | 数组       | 动态规划                                 |                |
| 160  | Easy   | Intersection of Two Linked Lists                          | 相交链表                                   | 链表       | 数学                                     |                |
| 169  | Easy   | Majority Element                                          | 多数元素                                   | 数组       | 模拟                                     |                |
| 198  | Medium | House Robber                                              | 打家劫舍                                   | 数组       | 动态规划                                 |                |
| 199  | Medium | Binary Tree Right Side View                               | 二叉树的右视图                             | 二叉树     | 广度优先搜索                             |                |
| 200  | Medium | Number of Islands                                         | 岛屿数量                                   | 数组       | 深度优先搜索<br/>广度优先搜索<br/>并查集 | 130, 695, 1254 |
| 206  | Easy   | Reverse Linked List                                       | 反转链表                                   | 链表       | 迭代                                     |                |
| 215  | Medium | Kth Largest Element in an Array                           | 数组中的第K个最大元素                      | 数组       | 堆                                       | 347            |
| 221  | Medium | Maximal Square                                            | 最大正方形                                 | 数组       | 动态规划                                 |                |
| 226  | Easy   | Invert Binary Tree                                        | 翻转二叉树                                 | 二叉树     | 递归                                     |                |
| 234  | Easy   | Palindrome Linked List                                    | 回文链表                                   | 链表       | 转换                                     |                |
| 236  | Medium | Lowest Common Ancestor of a Binary Tree                   | 二叉树的最近公共祖先                       | 二叉树     | 递归                                     |                |
| 238  | Medium | Product of Array Except Self                              | 除自身以外数组的乘积                       | 数组       | 前缀和                                   |                |
| 239  | Hard   | Sliding Window Maximum                                    | 滑动窗口最大值                             | 数组       | 单调队列                                 |                |
| 240  | Medium | Search a 2D Matrix II                                     | 搜索二维矩阵 II                            | 数组       | 二分查找                                 |                |
| 279  | Medium | Perfect Squares                                           | 完全平方数                                 | 数字       | 动态规划                                 |                |
| 283  | Easy   | Move Zeroes                                               | 移动零                                     | 数组       | 快慢指针                                 |                |
| 297  | Hard   | Serialize and Deserialize Binary Tree                     | 二叉树的序列化与反序列化                   | 二叉树     | 递归                                     |                |
| 300  | Medium | Longest Increasing Subsequence                            | 最长递增子序列                             | 数组       | 动态规划                                 | 516, 1143      |
| 303  | Easy   | Range Sum Query - Immutable                               | 区域和检索 - 数组不可变                    | 数组       | 前缀和                                   | 304            |
| 304  | Medium | Range Sum Query 2D - Immutable                            | 二维区域和检索 - 矩阵不可变                | 数组       | 前缀和                                   | 303            |
| 337  | Medium | House Robber III                                          | 打家劫舍 III                               | 二叉树     | 递归<br/>动态规划                        |                |
| 338  | Easy   | Counting Bits                                             | 比特位计数                                 | 数字       | 位运算                                   | 461            |
| 347  | Medium | Top K Frequent Elements                                   | 前 K 个高频元素                            | 数组       | 堆                                       | 215            |
| 376  | Medium | Wiggle Subsequence                                        | 摆动序列                                   | 数组       | 贪心算法                                 |                |
| 394  | Medium | Decode String                                             | 字符串解码                                 | 字符串     | 栈                                       |                |
| 416  | Medium | Partition Equal Subset Sum                                | 分割等和子集                               | 数组       | 转换<br/>深度优先搜索<br/>动态规划       | 494            |
| 435  | Medium | Non-overlapping Intervals                                 | 无重叠区间                                 | 数组       | 贪心算法                                 |                |
| 437  | Medium | Path Sum III                                              | 路径总和 III                               | 二叉树     | 递归                                     |                |
| 438  | Medium | Find All Anagrams in a String                             | 找到字符串中所有字母异位词                 | 字符串     | 滑动窗口                                 |                |
| 448  | Easy   | Find All Numbers Disappeared in an Array                  | 找到所有数组中消失的数字                   | 数组       | 哈希<br/>原地哈希                        |                |
| 461  | Easy   | Hamming Distance                                          | 汉明距离                                   | 数字       | 位运算                                   | 338            |
| 494  | Medium | Target Sum                                                | 目标和                                     | 数组       | 深度优先搜索<br/>转换<br/>动态规划       | 416            |
| 496  | Easy   | Next Greater Element I                                    | 下一个更大元素 I                           | 数组       | 单调栈                                   | 503            |
| 503  | Medium | Next Greater Element II                                   | 下一个更大元素 II                          | 数组       | 单调栈                                   | 496            |
| 516  | Medium | Longest Palindromic Subsequence                           | 最长回文子序列                             | 字符串     | 动态规划                                 | 300, 1143      |
| 538  | Medium | Convert BST to Greater Tree                               | 把二叉搜索树转换为累加树                   | 二叉搜索树 | 递归                                     |                |
| 543  | Easy   | Diameter of Binary Tree                                   | 二叉树的直径                               | 二叉树     | 递归                                     | 124            |
| 560  | Medium | Subarray Sum Equals K                                     | 和为 K 的子数组                            | 数组       | 前缀和<br/>哈希                          |                |
| 581  | Medium | Shortest Unsorted Continuous Subarray                     | 最短无序连续子数组                         | 数组       | 排序<br/>模拟                            |                |
| 617  | Easy   | Merge Two Binary Trees                                    | 合并二叉树                                 | 二叉树     | 递归                                     |                |
| 621  | Medium | Task Scheduler                                            | 任务调度器                                 | 数组       | 数学                                     |                |
| 647  | Medium | Palindromic Substrings                                    | 回文子串                                   | 字符串     | 暴力搜索                                 |                |
| 695  | Medium | Max Area of Island                                        | 岛屿的最大面积                             | 数组       | 深度优先搜索<br/>广度优先搜索            | 200            |
| 738  | Medium | Monotone Increasing Digits                                | 单调递增的数字                             | 数组       | 贪心算法                                 |                |
| 739  | Medium | Daily Temperatures                                        | 每日温度                                   | 数组       | 单调栈                                   |                |
| 752  | Medium | Open the Lock                                             | 打开转盘锁                                 | 字符串     | 广度优先搜索                             | 773, 127       |
| 773  | Hard   | Sliding Puzzle                                            | 滑动谜题                                   | 数组       | 广度优先搜索                             | 752            |
| 763  | Medium | Partition Labels                                          | 划分字母区间                               | 字符串     | 贪心算法                                 |                |
| 875  | Medium | Koko Eating Bananas                                       | 爱吃香蕉的珂珂                             | 数组       | 二分查找                                 | 1011           |
| 887  | Hard   | Super Egg Drop                                            | 鸡蛋掉落                                   | 数字       | 动态规划                                 |                |
| 1011 | Medium | Capacity To Ship Packages Within D Days                   | 在 D 天内送达包裹的能力                    | 数组       | 二分查找                                 | 875            |
| 1094 | Medium | Car Pooling                                               | 拼车                                       | 数组       | 差分数组                                 |                |
| 1109 | Medium | Corporate Flight Bookings                                 | 航班预订统计                               | 数组       | 差分数组                                 |                |
| 1143 | Medium | Longest Common Subsequence                                | 最长公共子序列                             | 字符串     | 动态规划                                 | 300, 516       |
| 1254 | Medium | Number of Closed Islands                                  | 统计封闭岛屿的数目                         | 数组       | 深度优先搜索<br/>广度优先搜索            | 200            |
| 1893 | Easy   | Check if All the Integers in a Range Are Covered          | 检查是否区域内所有整数都被覆盖             | 数组       | 差分数组                                 |                |
| 2406 | Medium | Divide Intervals Into Minimum Number of Groups            | 将区间分为最少组数                         | 数组       | 贪心<br/>差分数组                        |                |
| 2536 | Medium | Increment Submatrices by One                              | 子矩阵元素加 1                             | 数组       | 差分数组                                 |                |



### 剑指 offer

| 题号 | 难度 | 题目                       | 分类   | 思路                      | 相关                                        |
| ---- | ---- | -------------------------- | ------ | ------------------------- | ------------------------------------------- |
| 03   | 简单 | 数组中重复的数字           | 数组   | 哈希集合                  |                                             |
| 04   | 中等 | 二维数组中的查找           | 数组   | 二分查找                  | leetcode240                                 |
| 05   | 简单 | 替换空格                   | 字符串 | 正则                      |                                             |
| 07   | 中等 | 重建二叉树                 | 二叉树 | 递归                      | leetcode105<br/>leetcode106                 |
| 12   | 中等 | 矩阵中的路径               | 数组   | 回溯                      | leetcode79                                  |
| 13   | 中等 | 机器人的运动范围           | 数组   | 深度优先搜索              |                                             |
| 14   | 中等 | 剪绳子                     | 数字   | 动态规划                  |                                             |
| 16   | 中等 | 数值的整数次方             | 数字   | 快速幂                    |                                             |
| 20   | 中等 | 表示数值的字符串           | 字符串 | 模拟                      | leetcode65                                  |
| 26   | 中等 | 树的子结构                 | 二叉树 | 递归                      |                                             |
| 31   | 中等 | 栈的压入、弹出序列         | 数组   | 模拟                      |                                             |
| 32   | 中等 | 从上到下打印二叉树         | 二叉树 | 宽度优先搜索              | leetcode102                                 |
| 34   | 中等 | 二叉树中和为某一值的路径   | 二叉树 | 回溯                      | leetcode113                                 |
| 35   | 中等 | 复杂链表的复制             | 链表   | 哈希映射                  | leetcode138                                 |
| 36   | 中等 | 二叉搜索树与双向链表       | 二叉树 | 递归                      | leetcode114<br/>leetcode426                 |
| 38   | 中等 | 字符串的排列               | 字符串 | 回溯                      | leetcode46<br/>leetcode47                   |
| 44   | 中等 | 数字序列中某一位的数字     | 数字   | 数学                      | leetcode400                                 |
| 45   | 中等 | 把数组排成最小的数         | 数组   | 排序                      |                                             |
| 46   | 中等 | 把数字翻译成字符串         | 数字   | 深度优先搜索<br/>动态规划 |                                             |
| 47   | 中等 | 礼物的最大价值             | 数组   | 动态规划                  |                                             |
| 48   | 中等 | 最长不含重复字符的子字符串 | 字符串 | 滑动窗口                  | leetcode3                                   |
| 49   | 中等 | 丑数                       | 数字   | 动态规划                  | leetcode264                                 |
| 56   | 中等 | 数组中数字出现的次数       | 数组   | 位运算                    | leetcode136<br/>leetcode137<br/>leetcode260 |
| 60   | 中等 | n个骰子的点数              | 数字   | 动态规划                  |                                             |
| 63   | 中等 | 股票的最大利润             | 数组   | 预处理                    | leetcode121                                 |


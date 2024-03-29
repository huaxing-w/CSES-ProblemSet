# [CSES-Problem Set](https://cses.fi/problemset/list/ "link")

* 2024-02-15
    * 最近这几个题有点上强度了
        * [Longest_Palindrome.cpp](https://github.com/huaxing-w/CSES-ProblemSet/blob/main/String%20Algorithms/Longest_Palindrome.cpp)
            * 终于鼓起信心学习了马拉车算法，总算学会了，理解了以后甚至可以手搓
            * 简单来说就是维护几个变量
            * 通过对称点更新现在的点的半径
            * 暴力枚举看能不能把盒子扩大的更大
        * [Finding_Periods.cpp](https://github.com/huaxing-w/CSES-ProblemSet/blob/main/String%20Algorithms/Finding_Periods.cpp)
            * z函数模板题
        * [Minimal_Rotation.cpp](https://github.com/huaxing-w/CSES-ProblemSet/blob/main/String%20Algorithms/Minimal_Rotation.cpp)
            * 这个题没有想明白
            * 什么是最小表示法
* 2024-02-12
    * 开始吃素+少吃
        * [String_Matching](https://github.com/huaxing-w/CSES-ProblemSet/blob/main/String%20Algorithms/String_Matching.cpp)
            * 这个是一道非常经典的问题，这几年来我都一直用的是rolling hash来做这道题，前俩天学了下Z函数，才发现了新大陆
            * Z函数就是生成一个z数组，数组中的每个数表示当前后缀可以匹配多少前缀
        * [Finding_Borders.cpp](https://github.com/huaxing-w/CSES-ProblemSet/blob/main/String%20Algorithms/Finding_Borders.cpp)
            * z函数模板题，就是让你学习z函数的
* 2024-02-12
    * 平常的一天没什么可说的
        * [Word Combinations](https://github.com/huaxing-w/CSES-ProblemSet/blob/main/String%20Algorithms/Word_Combinations.cpp)
            * 这道字典树的题目太经典了，背包->字典树->循环优化，学习到了不少
* 2024-02-10
    * 新年快乐，希望自己新的一年能有所收获
        * 有一个经典的坐电梯问题，bitmask的具体应用
        * 还有一道数位dp，code已经写对了，爆int那边调了非常久，崩溃，调了2小时，不过最后还是过了。
* 2024-02-08
    * 因为健康原因，三天没刷题，健康最重要
        * alice和bob的游戏，如果俩个人都play optimal，那对于alice而言下次递归的时候是从子问题里的最小开始求解的
        * 背包的三种遍历所表达的不同意思，还是top down好写一点
            * amount在外侧循环，物品在内测循环从小到达，这个是在求可重复使用硬币，且顺序不一样就选一种方案，完全背包的模型
            * 物品在外侧循环，amount在内测从小到大循环，这还是一种完全背包，只不过方案数按set算，去重了相当于
            * 物品在外侧循环，amount在内测从大到小循环，最最经典的01背包问题，每个物品只使用一次
        * 除法取余，就是如何计算逆元
* 2024-02-05
    * 今天写了3道经典dp
        * 图形结合的dp，类似垒砖块？
        * 编辑距离，搞明白了三个状态的定义
        * 割长方形，踩坑了，需要枚举分割点
* 2024-02-04
    * 今天开始做dp的题目了
        * 复习了几个线性dp的入门题目
        * 01背包的标准题
        * 零钱兑换，以及零钱兑换的思考，为什么变换循环顺序可以排除重复的选项，如何从01背包的角度去思考
        * 记忆化搜索入门 
        * 数位dp的前驱题目？？？以及数位dp的中count参数的思考
* 2024-02-03
    * 今天学习了滑窗和会议室问题的拓展
        * 最大子数组和，如果给定滑窗大小要怎么做
        * 最多可以开几个会
* 2024-02-02
    * 今天主打一个复习
        * 如何用c++的平衡树结构去求解数据流中的中位数__gnu_pbds
        * 复习了一波 K个不同整数的子数组 问题，我做的是简单版，复杂版需要用到双指针套双指针
        * 负数求解余数时需要注意的问题
        * “俩数之和”的各种subarray问题
        * 三数之和+四数之和复习
        * 单调栈求每日温度问题
        * 经典二分搜索
* 2024-02-01
    * 今天做了几个结论题，之前都没有学习过
        * Shortest Processing Time first (SPT) 问题
        * bottleneck 读书问题 
* 2024-01-31
    * 今天做了1个题 Nested range count
        * 超级经典
        * 俄罗斯套娃，树状数组，差分数组的超级缝合怪 
* 2024-01-30
    * 学习了约瑟夫环问题
        * 第一次接触__gnu_pbds
* 2024-01-29
    * 陆陆续续做了一些题目，然后发现这些题目都非常的好，全是经典题目，非常值得写一些题解加强自己的记忆，所以决定建个repo来记录一下。

### LeetCode 解题思路

| 题目名称 | 题目思路 |
| - | - |
| 1. Two Sum | 目标值减去数组中其中一个值， 得到的结果是否在数组之内 |
| 2. Add Two Numbers | 加法累加 |
| 3. Longest Substring Without Repeating Characters | 使用 256 字符表记录 + 滑动窗口 |
| 4. Median of Two Sorted Arrays | 计算中位数， 区分奇数和偶数长度数组 |
| 5. Longest Palindromic Substring | 双重循环， 第一重循环里的值如果对上第二重循环里的值， 然后往回遍历判断是否为回文。 这个不是最优方案 |
| 6. Zigzag Conversion | 字符串之字形排列 |
| 7. Reverse Integer | 主要需要注意一个边界调节， 比如负值最大， 切换成正值会 overflow 等问题 |
| 8. String to Integer (atoi) | 主要注意数值越界， 以及 +- 空格等问题 |
| 9. Palindrome Number | 判断回文数字 |
| 10. Regular Expression Matching | 正则表达式匹配， 需要注意  `.*, *` 等用法， 边界条件有点多 |
| 11. Container With Most Water | 贪心， 一左一右向中间逼近 |
| 12. Integer to Roman | 数字转化为罗马数字 |
| 13. Roman to Integer | 罗马数字转化为十进制数字 |
| 14. Longest Common Prefix | 就是判断公共前缀 |
| 15. 3Sum | 排序一下， 先固定一个值， 然后另外两个值从左右往中间逼近 |
| 16. 3Sum Closest | 排序一下， 先固定一个值， 然后另外两个值从左右往中间逼近 |
| 17. Letter Combinations of a Phone Number | 列出来即可 |
| 18. 4Sum | 排序一下， 先固定一个值， 再固定一个值， 然后另外两个值从左右往中间逼近 |
| 19. Remove Nth Node From End of List | 简单的方式是先遍历一遍， 第二遍再删除。 一遍删除的方法可以使用递归处理 |
| 20. Valid Parentheses | 使用 stack 数据结构即可 |
| 21. Merge Two Sorted Lists | 根据大小进行合并 |
| 22. Generate Parentheses | 括号的排列组合， 需要注意是否合法 |
| 23. Merge k Sorted Lists | 每次选择最低值形成新链 |
| 24. Swap Nodes in Pairs | 就是每两个都向前头插入（前头可是 head 前一个值即自己生成的一个对象， 也可以是已经完成反转的最后一个值）， 这个顺序就反过来了， 然后往前走两个继续 |
| 25. Reverse Nodes in k-Group | 这题就是 24 将 2 两个数量变成输入值 k 个即可 |
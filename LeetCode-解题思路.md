
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
| 10. Regular Expression Matching | 正则表达式匹配， 需要注意  .*, * 等用法， 边界条件有点多 |
| 11. Container With Most Water | 贪心， 一左一右向中间逼近 |
| 12. Integer to Roman | 数字转化为罗马数字 |
| 13. Roman to Integer | 罗马数字转化为十进制数字 |
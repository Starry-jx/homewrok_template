# XXXX实验报告

## 学号：20201060276

## 实验目的：

编程实现经典的动态规划算法，理解动态规划算法设计的基本思想、程序实
现的相关技巧，加深对动态规划算法设计与分析思想的理解。通过程序的执行时
间测试结果，与理论上的时间复杂度结论进行对比、分析和验证。

## 实验原理

动态规划是一种在数学和计算机科学中使用的、用于求解包含重叠子问题的
最优化问题的有效方法。其基本思想是：将原问题分解为相似的子问题，在求解
的过程中通过子问题的解描述并求出原问题的解。动态规划的思想是多种算法的
基础，被广泛应用于计算机科学和工程领域，在查找有很多重叠子问题的情况的
最优解时有效。它将问题重新组合成子问题，为了避免多次解决这些子问题，它
们的结果都逐渐被计算并保存，从小规模的子问题直到整个问题都被解决。因此，
动态规划对每一子问题只做一次计算，具有较高的效率


## 实验内容

编程实现以上求解 0-1 背包问题的动态规划算法，并通过手动设置、生成随
机数获得实验数据。记录随着输入规模增加算法的执行时间，分析并以图形方式
展现增长率；测试、验证、对比算法的时间复杂度。

[experiment.c](experiment_2.c) 算法实现的C语言版本

## 实验预期结果与实际结果

实验结果：
不同背包，不同物品数量下，结果与运算时间：

![image](https://github.com/Starry-jx/homewrok_template/blob/main/%E5%AE%9E%E9%AA%8C%E4%BA%8C/%E6%88%AA%E5%9B%BE/1.jpg)

![image](https://github.com/Starry-jx/homewrok_template/blob/main/%E5%AE%9E%E9%AA%8C%E4%BA%8C/%E6%88%AA%E5%9B%BE/2.jpg)

![image](https://github.com/Starry-jx/homewrok_template/blob/main/%E5%AE%9E%E9%AA%8C%E4%BA%8C/%E6%88%AA%E5%9B%BE/3.jpg)

算法执行时间比较：


![image](https://github.com/Starry-jx/homewrok_template/blob/main/%E5%AE%9E%E9%AA%8C%E4%BA%8C/%E6%88%AA%E5%9B%BE/4.jpg)

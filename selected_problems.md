## abc161 d 队列  
**题意**: 定义一个good number x: x的每一对相邻数字的差的绝对值<=1, 求第k个good number. $1 <= k <= 10^5$.  
**解法**: 使用std::queue, 先把1 - 9 放进去, 每次取出一个数v, 放回(10 * v + ?)3个数.注意这里不需要std::priority__queue.  


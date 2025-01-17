[基于 matlab 程序对 PID 控制算法的理解](http://blog.csdn.net/sinat_23338865/article/details/53837634)

* PID 原理及普及
* 常用四轴的两种 PID 算法(单环 PID、串级 PID)
* 如何做到垂直起飞、四轴飞行时为何会飘、如何做到脱控？


# PID 原理及其普及
对自动控制系统的基本要求：稳、准、快！

* 稳定性（P 和 I 降低系统稳定性，D 提高系统稳定性）：在平衡状态下，系统受到某个干扰后，经过一段时间其被控量可以达到某一稳定状态；
* 准确性（P 和 I 提高稳态精度，D 无作用）：系统处于稳态时，其稳态误差；
* 快速性（P 和 D 提高响应速度，I 降低响应速度）：系统对动态响应的要求。一般由过渡时间的长短来衡量。

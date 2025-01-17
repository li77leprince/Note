# 01 理解指针

> 指针是一个特殊的变量,它里面存储的数值被解释成为内存里的一个地址。 要搞清一个指针需要搞清指针的四方面的内容： `指针的类型`、 `指针所指向的 类型`、 `指针的值或者叫指针所指向的内存区`、 `指针本身所占据的内存区`。

- 1、指针的类型

从语法的角度看， 你只要把 `指针声明语句里的指针名字去掉， 剩下的部 分就是这个指针的类型`。 这是指针本身所具有的类型。 例如

```
int*poi;    // 指针的类型是 int*
char*poi;  // 指针的类型是 char*
int**poi;   // 指针的类型是 int**
int(*poi)[6];//指针的类型是 int(*)[6]
int*(*poi)[6]; // 指针的类型是 int*(*)[6]
```

- 2、指针所指向的类型

通过指针来访问指针所指向的内存区时, 指针所指向的类型就决定了编译器将把那片内存区里的内容当做什么来看待。

从语法上看, 只需要把指针声明语句中的 `指针名字` 和 `名字左边的指针声明符 * 去掉`, 剩下的就是指针所指向的类型。 如下

```
int*poi;    // 指针所指向的类型是 int
char*poi;   // 指针所指向的类型是 char
int**poi;   // 指针所指向的类型是 int*
int(*poi)[6]; // 指针所指向的类型是 int()[6]
int*(*poi)[6]; // 指针所指向的类型是 int*()[6]
// 在指针的运算中, 指针所指向的类型有很大的作用.
// 指针的类型(即指针本身的类型)和指针所指向的类型是两个概念.
// 所以不要混淆这两个概念是学好指针的关键点之一, 否则前后矛盾, 越来越糊涂
```

- 3、指针的值 (或者叫指针所指向的内存区或地址)

指针的值是指针本身储存的数值, 这个值将会被编译器当作一个地址, 而不是一个一般的数值。  

32 bit 的机器中, 所有类型的指针的值都是一个 32 位整数, 因为里面的地址都是 32 bit 长。指针所指向的内存区就是从指针的值所代表的那个内存地址开始,长度为 `sizeof(指针所指向的类型)` 的内存区。

所以, 说一个指针的值是 xx, 就相当于说 该指针指向了以 xx 为首地址的一片区域; 说一个指针指向了谋块内存区域, 就相当于说该指针的值是这块内存区域的首地址。

对于未初始化的指针, 所指向的内存区是不存在的, 或者没什么意义。

- 4、指针本身所占据的内存区

指针本身占用了多大的内存, 可以使用 `sizeof(指针的类型)` 测试一下。在 32bit 位机器里指针本身占据了 4 个字节的长度。

`sizeof` 不是一个函数, 而是一个关键字应该都知道。不清楚的可以再网上看看。


# 02 指针的运算
>







- [ ] 指针学习篇 2

> 应该算是一个补充吧。

---

### 野指针
什么是野指针？
* 野指针, 就是指针指向的位置是不可知的(随机的、不正确的、没有明确限制的)。
* 野指针很可能触发运行时段错误 (Sgmentation fault)。
* ...

如何避免野指针：
* 解决方法 -> 在指针的解引用之前，一定确保指针指向一个绝对可用的空间。
* 常规的做法就是：
    * 1、定义指针时，同时初始化为NULL
    * 2、在指针解引用之前，先去判断这个指针是不是NULL
    * 3、指针使用完之后，将其赋值为NULL
    * 4、在指针使用之前，将其赋值绑定给一个可用地址空间
* 虽然日常开发中, 这方法显得很麻烦。根据实际情况, 去把握。 如果项目比较大的话, 还是建议这样做的。

NULL 的实质其实就是 0，然后我们给指针赋初值为 NULL，其实就是让指针指向 0 地址处。为什么指向 0 地址处？ 2 个原因。第一个原因是 0 地址处作为一个特殊地址（我们认为指针指向这里就表示指针没有被初始化，就表示是野指针）。第二个原因是这个地址 0 地址在一般的操作系统中都是不可被访问的，如果 C 语言程序员不按规矩（不检查是否等于 NULL 就去解引用）写代码直接去解引用就会触发段错误，这种已经是最好的结果了。
判断指针是否是野指针, 一般写成:
```
if(NULL != P)
```
而不写成
```
if (p != NULL)
```

>小结

定义指针一定初始化, 一定要初始化, 一定要初始化！

```
#define NULL (void*)0
int *p = NULL
```




http://www.qidic.com/42354.html




.

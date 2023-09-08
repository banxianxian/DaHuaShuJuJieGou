### list容器

list为一个双向链表,下面用int类型来介绍

1.初始化方式

注意：当初始化时规定了长度，则链表的长度就定了，不能超过这个长度,如果使用insert超过，可能会出错

​			如果没有规定长度，则链表的长度可以一直变长

```c++

	list<int> Myval;							//创建一个无限制长度的list容器
	list<int> Myval1(10);						//创建一个长度为10的链表，每个值赋值为0
	list<int> Myval2(10, 3);					//创建了一个长度为10的链表，每个赋值为3
	list<int> Myval3(Myval2);					//创建了一个链表将Myval2复制给Myval3
	list<int> Myval4{ 1,2,3,4,5,6 };			//创建了一个无限制长度链表前六个值赋值为(1,2,3,4,5,6)
```

2.迭代器

1.声明方式

```c++
	list<int>:: iterator itr1;
	auto itr1=Myval.begin();
```

2.
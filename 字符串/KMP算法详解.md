### KMP算法详解

[TOC]

#### 1.KMP的作用

​	KMP算法为字符串匹配算法，用于优化朴素模式算法。

#### 2.求解next数组

先看代码，再解释关键步骤，对于为什么有next数组不再解释。

下面next[i]代表的是从0到i-1的字符串的最大公共前后缀

```c++
void get_next(int* next, string T) {
    int k = -1, i = 0;
    next[0] = -1;
    while (i < T.size()) {
        if (k == -1 || T[k] == T[i]) {
            next[i + 1] = k + 1;
            k++;
            i++;
        }
        else {
            k = next[k];
        }
    }
}
```

##### 1.初始化条件next[0] = -1

理论上0前面没有不存在字符串，令next[0] = -1，是为了进行标记，作为后面回溯k = next[k]的一个终止条件，也可以定义为其它负数，不能为正数，可能会与其它的next[i]重合。

##### 2.为什么用k = next[k]回溯

![](https://github.com/banxianxian/image/blob/main/DaHuaShuJuJieGou/KMP.drawio.png?raw=true)

可以知道，只有当T[k] != T[i]时才会进入k=next[k], 的判断，i - 1 的串的公共最大前缀长度为k **(next[i - 1] = k )** 。

从该图可以知道，当T[k] != T[i - 1], 进行k = next[k]

1. 我们知道**i-1**的公共前后缀为长度为**k**，即图片上面的黄色部分。**A == B**。

2. **next[k]**，代表的是k的最大公共前后缀的长度即为上面的蓝色部分。**C==D**

3. 由**A\==B**，和D与E的长度均为next[k]的长度可以知道。**D==E**

从而**C==E**，如果这时**T[next[k]] == T[i - 1]** 即得到i的最大公共前后缀，如果不相等重复该过程直到k=-1 

##### 3.实现代码时需要注意的事项

上面的示例代码中的next数组的长度应该比字符串T的长度大1，避免循环是防范问越界，此时next的最后一个数据代表的是整个串的最大公共前后缀。

#### 3.总体代码

**注意循环条件判断时**，对T.size()，进行了数据类型转换，由**unsigned int** 转成了 **int**，因为**i**可能为**-1**，而i为int类型，**int**与**unsigned int**进行比**较等等计算**时，会转换为unsigned int。从而跳出循环

```c++
int main() {
    int next[6] = { 0 };
    string T = "abaab";
    get_next(next, T);
    string S = "abaababaab";
    int i = 0, j = 0;
    while (i < (int)T.size() && j < (int)S.size()) {
        if (i == -1 || T[i] == S[j]) {
            i++;
            j++;
        }
        else {
            i = next[i];
        }
    }

    if (i == T.size()) {
        cout << "successful" << endl;
    }
    else{
        cout << "fail" << endl;
    }

    return 0;
}
```




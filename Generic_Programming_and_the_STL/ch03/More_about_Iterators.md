## Ch03 : 再论Iterator

### 1. Iterator traits and Associatde Types

#### 1.1 Value Type
C++中的type inference机制非常有趣，只能作用于arugment上，而不能作用于返回值上。单纯地在模板类中将value_type定义的方法无法解决指针类的问题，因此引入了在STL中非常重要的概念**traits**.
一般类实现机制：

template<class Node> struct nodee_wrap
}

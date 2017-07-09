## Ch03 : 再论Iterator

### 1. Iterator traits and Associatde Types

#### 1.1 Value Type
C++中的type inference机制非常有趣，只能作用于arugment上，而不能作用于返回值上。单纯地在模板类中将value_type定义的方法无法解决指针类的问题，因此引入了在STL中非常重要的概念**traits**.
一般类实现机制：


    template<class Node> struct nodee_wrap{
      // 此处必须使用typedef, 因为template在instantialization之前无法知道Node类型的信息
      typedef Node value_type;
      Node* ptr;
    }
    // 全特化
    template<class Iterator>
    struct iterator_traits{
      typedef typename Iterator::value_type value_type
    }
    // 为指针专门提供一个偏特化
    template<class T>
    struct iterator_traits<T*> {
      typedef T value_type;
    }
    // 为const pointer再提供一个偏特化
    template<class T>
    struct iterator_traits<const T*>
    {
      typedef T value_type;
    }
    template<class InputIterator>
    typename iterator_traits<InputIterator>::value_type sum_noempty(InputIterator first, InputIterator last)
    {
      typename iterator_traits<InputIterator>::value_type result = first++;
      for (; first != last; ++first)
        result += *first;
      return result;
    }

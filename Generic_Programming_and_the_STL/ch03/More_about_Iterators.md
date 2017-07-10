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

#### 1.2 Difference Type

    template <class InputIterator, class T>
    typename iterator_traits<InputIterator>::difference_type
    count(InputIterator first, InputIterator last, const T& x){
      typename iterator_traits<InputIterator>::difference_type n = 0;
      for (; first != last; ++first)
        ++n;
      return n;
    }

#### 1.3 Reference Type and Pointer Type
处理方式类似的使用iterator_traits的方法

#### 1.4 Iterator tags
当同一算法遇上不同的Iterator时，可以进行“重载”，但是C++本身是不能够重载**concepts**, 因此就提供了一个**iterator_tag**来区分各种Iterator， 这样就出现了iterator_category.

每当我们定义一个新的iterator class时，就必须在这个class中定义五个嵌套型别：iterator_category, value_type, difference_type, pointer, reference, 要不就要针对class，让iterator_traits进行特化。


template<class Category, class Value, class Distance = ptrdiff_t, class Reference = Value&>
struct iterator{
  typedef Category iterator_category;
  typedef Value value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
};

**Note** iterator 应该是constant或者mutable, 两者的主要差别在于reference type和pointer type是T& 和T*, 或者是const T&和const T*.

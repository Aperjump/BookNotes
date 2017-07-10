## Ch04 : Function Objects

### 1. Predicate
在C++ primer，<algorithm>那章给我留下了非常深刻的印象，其中predicate印象最深。
书中提到，有些函数如`sort`，可以传入第三个参数作为比较两个元素大小的方式，常见的传入参数的方法大约有三种：
- Predicate
- function Objects
- Lambda expression


    template<class InputIterator, class Predicate>
    InputIterator find_if(InputIterator first, InputIterator last, Predicate pred)
    {
      while(first != last && !pred(*first))
        ++first;
      return first;
    }
我们当然可以使用传入函数的方式传递给Predicate, 但是还有另一种值得注意的方式 : Function objects.
Function object的优势在于可以利用class内部的局部状态实现一些效果。

    struct last_name_is
    {
      string value;
      last_name_is(const string& val) : val(val) { }
      bool operator()(const Person& x) const {
        retrun x.last_name == value;
      }
    }
    find_if(first, last, last_name_is("Simith"))

### 2. Function Object Concepts

#### 2.1 Unary and Binary Function Objects
基本的function object concepts是Generator, Unary Function和Binary Function， STL中定义的其他function object concept都是这三个concept的refinement.
Predicate就是Unary Function的一个refinement, 指需要返回true或者false的function object

#### 2.2 Associated Types
Associated Types指函数的arugment和返回值类型。Generator具有一个Associated Type, Unary Function有两个，Binary Function有三个，就像我们引入iterator_traits一样，我们也可以在function object中引入类似的概念

    template<class Arg, class Result>
    struct unary_function{
      typedef Arg argument_type;
      typedef Result result_type;
    };

    template<class Arg1, class Arg2, class Result>
    struct binary_function{
      typedef Arg1 first_argument_type;
      typedef Arg2 second_argument_type;
      typedef Result result_type;
    }

### 3. Function Object Adapters
Adapter是指将某种接口转化为另一接口的组件。

    template<class AdaptablePredicate>
    class unary_negate
    {
      private:
        AdaptablePredicate pred;
      public:
        typedef typename AdaptablePredicate::argument_type argument_type;
        AdaptablePredicate::result_type result_type;

        unary_negate(const AdaptablePredicate& x) : pred(x) { }
        bool operator()(const argument_type& x) const {
          return !pred(x);
        }
    };
STL中定义的有 `plus`, `minus`, `multiplies`, `modules`, `negate`, 基本的比较运算有`equal_to`, `not_equal_to`, `greater`, `less`, `greater_equal`等。

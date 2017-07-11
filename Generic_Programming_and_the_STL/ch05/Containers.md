## Ch05 : Containers

### 1. A Simple Case

	template<class T, size_t N>
	struct block {
		typedef T value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;

		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef pointer iterator;
		typedef const_pointer const_iterator;

		iterator begin() { return data; }
		iterator end() { return data + N; }

		const_iterator begin() const { return data; }
		const_iterator end() const { return data + N; }

		reference operator[](size_type n) { return data[n]; }
		const_reference operator[](size_type n) const { return data[n]; }

		size_type size() const { return N; }
		T data[N];
	};
就目前而言，block已经是**Assignable**和**Default Constructible**的model，然而还并不是**Equality Comparable**和**LessThan Comparable**的model。

	template<class T, size_t N>
	bool operator==(const block<T, N>& x, const block<T, N>& y)
	{
		for (size_t n = 0; n < N; ++n)
		{
			if (x.data[n] != y.data[n])
				return false;
			return true;
		}
	}
	template<class T, size_t N>
	bool operator<(const block<T, N>& x, const block<T, N>& y)
	{
		for (size_t n = 0; n < N; ++n)
		{
			if (x.data[n] < y.data[n])
				return true;
			else if (y.data[n] > x.data[n])
				return false;
			return false;
		}
	}
当且仅当T是**Equality Comparable**和**LessThan Comparable**的model是，block才成为该model。

### 2. Container Concepts
我们定义的block具有三个主要的功能： 
- 它包含元素
- 提供访问元素的方法
- 支持regular type的操作行为

#### (1) Element Containment
block的元素是block的一部分，block是单一连续的内存区域，每一个内存元素的地址都存在于这段内存区域内，主要特性包括：
- 两个containers不能重叠，同一个元素不能属于一个以上的containers
- 元素的生命期不能超过container的生命期
- container可以有固定的大小，但可变

#### (2) Iterators
- block定义了iterator和const_iterator， 所有泛型算法均可作用于iterator形成的range上
- reverse_iterator和const_reverse_iterator
- A[n]

#### (3) Container Hierarchy
Container(Input Iterator) -----> Forward Container(Forward Iterator) -----> Reversible Container(Bidirectional Iterator) 
-----> Random Access Container(Random Access Iterator)

### 3. 大小可变的Container Concepts

STL定义了两种大小可变的container, **Sequence Container**和**Associative Container**

#### (1) Sequence Container
Sequence Container是Forward Container的一个refinement.
Sequence必须具备**insert**和**erase**, insert(p, x)会将x插到p元素之前。


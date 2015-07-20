#pragma once

#include <algorithm>
#include <iterator>

// 返回一个布尔类型的值，表示两个序列中的元素是否相等，第一个序列由输入迭代器b和e界定，  
// 第二个序列是从输入迭代器b2指向的元素开始的与第一个序列等长的序列  
template <class InputIterator1, class InputIterator2>
bool my_equal(InputIterator1 b, InputIterator1 e, InputIterator2 b2)
{
	for (; b != e; ++b)
	{
		if (*b != *b2)
			return false;
		++b2;
	}

	return true;
}


// 在由正向迭代器b和e界定的序列中，查找由正向迭代器b2和e2界定的子序列，然后返回指向第一个匹配的子序列首元素的正向迭代器
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 my_search(ForwardIterator1 b, ForwardIterator1 e, ForwardIterator2 b2, ForwardIterator2 e2)
{
	for (; b != e; ++b)
	{
		if (my_equal(b2, e2, b))
			return b;
	}

	return e;
}


// 返回一个迭代器，指向一个序列中首次出现t值的元素，该序列由输入迭代器b和e界定 
template <class InputIterator, class Type>
InputIterator my_find(InputIterator b, InputIterator e, const Type& t)
{
	for (; b != e; ++b)
	{
		if (*b == t)
			return b;
	}

	return e;
}


// 返回一个迭代器，指向一个序列中首次满足p表达式的元素，该序列由输入迭代器b和e界定  
template <class InputIterator,class Predicate>  
InputIterator my_find_if(InputIterator b, InputIterator e,Predicate p) 
{  
	for (; b !=e; ++b)
	{
		if (p(*b))  
			return b;  
	}

	return e;  
}  


// 将由输出迭代器b和e界定的序列中的值复制到目标容器中，目标容器有输出迭代器d指定  
// 该函数假定在目标容器中有足够的空间存储复制过来的值，返回一个值指向目标容器末元素后面一个元素  
template <class InputIterator,class OutputIterator>  
OutputIterator my_copy(InputIterator b, InputIterator e, OutputIterator d) 
{  
	for ( ;b != e; ++b)  
		*d++ = *b;  
	return d;  
}  


// 排列容器以使在区间[b, e)中不等于t的元素位于这个域的头部
template <class ForwardIterator, class Type>  
ForwardIterator my_remove(ForwardIterator b, ForwardIterator, const Type& t) 
{  
	ForwardIterator first_fail = b;  
	for ( ;b != e; ++b) 
	{
		if (*b != t)  
			*first_fail++ = *b;  
	}

	return first_fail;  
}  


// 将与t不匹配的元素复制到由输出迭代器d指向的目标容器中  
template <class InputIterator, class OutputIterator, class Type>  
OutputIterator my_remove_copy(InputIterator b, InputIterator, OutputIterator d, const Type& t)		
{  
	for (; b != e; ++b)  
		if (*b != t)  
			*d++ = *b;  
	return d;  
}  


// 将是条件p为假的元素复制到由输出迭代器d指向的目标容器中  
template <class InputIterator, class OutputIterator, class Predicate>  
OutputIterator my_remove_copy_if(InputIterator b,InputIterator e, OutputIterator d, Predicate p) 
{  
	for (; b != e; ++b)  
		if (!p(*b))  
			*d++ = *b;  
	return d;  
}  


// 根据[b, e)中的元素运行函数f，将f的结果存储在d中  
template <class InputIterator, class OutputIterator, class Function>  
OutputIterator my_transform(InputIterator b, InputIterator e, OutputIterator d, Function f) 
{  
	for (; b != e; ++b)  
		*d++ = f(*b);  
	return d;  
}  


// 将由双向迭代器b和e界定的序列分成两部分，会将满足表达式p为真的元素放在容器的前面，不满足p为真的元素放在容器的后面。  
// 返回第一个不满足p为真的元素的迭代器，如果对于所有元素都满足p为真，则返回e  
// 另一个函数stable_partition，是两部分中的元素都保持原来在容器中的先后顺序  
template <class ForwardIterator, class Predicate>  
ForwardIterator my_partition(ForwardIterator b, ForwardIterator e, Predicate p) 
{  
	ForwardIterator first_fail = b;  
	for (; b != e; ++b)  
		if (p(*b))  
			swap(*first_fail++, *b);  
	return first_fail;  
}  


// accumulate带有三个形参：头两个形参指定要累加的元素范围，第三个形参则是累加的初值
template <class InputIterator, class Type>  
Type my_accumulate(InputIterator b, InputIterator e, Type t)
{  
	for (; b != e; ++b)  
		t += *b;  
	return t;  
} 
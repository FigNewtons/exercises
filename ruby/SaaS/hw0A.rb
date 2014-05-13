=begin 

------------------- SaaS: Homework 0 Part 1 --------------------
						  FigNewtons

sum - Given an array (of integers), this method 
returns the sum of its elements. If the array is 
empty, then sum returns 0.

max_2_sum - Returns the sum of the largest two
integers in an array. If the array has no elements,
then the method returns zero. If the array has one
element, then it simply returns the element.

sum_to_n? - Returns true if any two distinct elements
in the array sum to parameter n.


=end

def sum(array)
	array.empty? ? 0: array.inject(:+)
end


def max_2_sum(array)
	array.sort!.reverse!
	array.empty? ? 0: sum(array.first(2))
end


def sum_to_n?(array, n)
	return false if array.length < 2
	a = array.combination(2){|c| return true if sum(c) == n}
	return false
end


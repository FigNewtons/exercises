=begin

------------------- SaaS: Homework 0 Part 3 --------------------
						  FigNewtons

The class BookInStock has two attributes: the book's ISBN and 
price. Both attributes have accessor and mutator methods. 
The constructor method does error handling by making sure the
book's price is positive (not zero) and that the ISBN is not
an empty string. There is also a method that returns a formatted
string of the book price ex: $10.30


=end

class BookInStock

	attr_accessor :isbn
	attr_accessor :price

	def initialize(i, p)
		unless p > 0 
				raise ArgumentError.new("Negative price")
		end
		unless i.eql?("") == false 
				raise ArgumentError.new("Empty string for ISBN")
		end
		@isbn = i
		@price = p
	end
	
	def price_as_string
		"$%.2f" % @price
	end
end


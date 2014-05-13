=begin

------------------- SaaS: Homework 0 Part 2 --------------------
						  FigNewtons

hello - Returns a string saying "Hello, #{name}"

starts_with_consonant? - Returns true if the string
begins with a consonant. This is the regex used:
			/\A(?=[a-z])(?=[^aeiou])./

\A       begins at the start of the string
(?=pat)  checks if characters match pat without including
		 it in the matched text
[a-z]    matches to a lowercase letter
[^aeiou] matches to a nonvowel character
.        wildcard  

So in total, this pattern makes sure that the first character
is a lowercase consonant.

binary_multiple_of_4? - Returns true if the string
(when converted to an binary number) is divisible by 4. 
This is the regex used: /\A[01]+\z/

\z		continues to end of string
[01]+	matches one or more 0 or 1

Thus, this pattern finds a string containing only 0 or 1

=end

def hello(name)
	"Hello, " + name
end

def starts_with_consonant?(s)
	(s.downcase =~ /\A(?=[a-z])(?=[^aeiou])./) != nil
end

def binary_multiple_of_4?(s)
	return false if (s =~ /\A[01]+\z/) == nil
	s.to_i(2) % 4 == 0  
end






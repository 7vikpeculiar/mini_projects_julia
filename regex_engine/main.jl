include("./regex.jl")
using .Regex
println(matchStart("a","a"));
println(matchReg("abc","abc\$"));
println(searchReg("^abc","abcd"));
println(matchReg("c\$","cdd"));
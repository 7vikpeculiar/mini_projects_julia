module Regex 

export matchStart, matchReg, searchReg, matchStar, matchQuestion, matchPlus

function matchStart(pattern::String,input::String)
    if pattern == ""
        return true
    elseif input == ""
        return false
    elseif pattern == "."
        return true
    end
    return pattern == input
end

function matchReg(pattern::String,input::String)
    if pattern == ""
        return true
    elseif pattern == "\$" && input == ""
        return true
    elseif length(pattern) >= 2 && pattern[1] == '!' && pattern[2] in "^*?+.!"
        return matchStart(pattern[2:2],input[1:1]) && matchReg(pattern[3:end],input[2:end])
    elseif length(pattern) >= 2 && pattern[2] == '?'
        return matchQuestion(pattern,input)
    elseif length(pattern) >= 2 && pattern[2] == '*'
        return matchStar(pattern,input)
    elseif length(pattern) >= 2 && pattern[2] == '+'
        return matchPlus(pattern,input)
    else
        return matchStart(pattern[1:1],input[1:1]) && matchReg(pattern[2:end], input[2:end])
    end
end

function searchReg(pattern::String,input::String)
    if pattern[1:1] == "^"
        return matchReg(pattern[2:end],input)
    else
        return any([matchReg(pattern,input[i:end]) for i in 1:length(input)])
    end
end

function matchQuestion(pattern::String,input::String)
    # Either  0 or 1 so...
    # so if first char matches, then pattern (1?abc) remove first two chars, string ka first char
    # if first char doesnt match, then remove first two chars, string use the same
    if matchStart(pattern[1:1],input[1:1])
        return matchReg(pattern[3:end],input[2:end])
    else
        return matchReg(pattern[3:end],input)
    end
end

function matchStar(pattern::String,input::String)
    if matchStart(pattern[1:1],input[1:1])
        return matchReg(pattern,input[2:end])
    else
        return matchReg(pattern[3:end],input)
    end
end

function matchPlus(pattern::String,input::String)
    # Either 1 or more, so ...
    if matchStart(pattern[1:1],input[1:1])
        # After one match, + is the same as * now
        # a+ = a.a* 
        pattern_new = string(pattern[1:1],"*",pattern[3:end]);
        return matchStar(pattern_new, input[2:end])
    else
        return false
    end
end


end
-- This is a Lua global variable
some_variable = 3^(5 * 2)

-- This is a Lua function that calculates the factorial of a given number
function factorial(n)
    if n == 1 then
        return 1
    end
    return n * factorial(n - 1)
end

print("The cube of the number 3 is equal to " .. cube(3))
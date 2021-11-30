--[[
Descripttion: 
version: 
Author: ahtoh
Date: 2021-11-03 15:28:48
LastEditors: ahtoh
LastEditTime: 2021-11-16 17:11:01
--]]
--[[ 
function fact(n)
    if n == 0 then
        return 1
    else
        return n * fact(n - 1)
    end
end

print("Enter a number:")
a = io.read("*n")
print(fact(a))

print(1) ]]
--[[ 
    and：如果第一个操作数为“false”，则返回第一个操作数，否则返回第二个
    or：如果第一个操作数不为“false”，则返回第一个操作数，否则返回第二个操作数
 ]]
--[[  print(4 and 5) -- 5，第一个操作符不为false，所以返回5
 print(nil and 13) -- nil
 print(false and 13) -- false
 print(0 or 5) -- 0，0为真，只有nil和false为假，所以返回0
 print(false or "hi") -- hi，第一个操作符为false，所以返回hi
 print(nil or false) -- nil == false，所以返回false？ ]]
--  #!/usr/bin/env lua

N = 8

function isplaceok(a, n, c)
    for i = 1, n - 1 do
        if (a[i] == c) or (a[i] - i == c - n) or (a[i] + i == c + n) then
            return false
        end
    end
    return true
end

-- 打印棋盘

function printsolution(a)
    for i = 1, N do
        for j = 1, N do
            io.write(a[i] == j and 'X' or '-', ' ')
        end
        io.write('\n')
    end
    io.write('\n')
end

-- 把从‘n’到'N'的所有皇后放到期盼'a'上
function addqueen(a, n)
    if n > N then
        printsolution(a)
    else
        for c = 1, N do
            if isplaceok(a, n, c) then
                a[n] = c
                addqueen(a, n + 1)
            end
        end
    end
end

addqueen({}, 1)

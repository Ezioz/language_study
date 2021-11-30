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
--[[ N = 8
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
 ]]
--  html = [[
--      <html>
--      <head></head>
--      <body>
--      <a href="http://www.runoob.com">cai</a>
--      </body>
--      </html>
--  ]]
--  a = "xxxx"
--  print(#html .. #a)
-- 表
-- local tbl1 = {}
-- local tbl2 = {"apple", "pear", "orange"}
-- a = {}
-- a["key"] = "value"
-- key = 10
-- a[key] = 20
-- a[key] = a[key] + 11
-- for k,v in pairs(a) do
--     print(k .. ":" .. v)
-- end
-- for key,v in pairs(tbl2) do
--     print("key " .. key)
-- end
-- function testFun(tab, fun)
--     for k,v in pairs(tab) do
--         print(fun(k, v))
--     end
-- end
-- tab = {key1 = "val1", key2 = "val2"}
-- testFun(tab, function (key, val)
--     return key .. "=" .. val
-- end)
-- 线程可以同时多个运行，而协程任意时刻只能运行一个，并且处于运行状态的协程只有被挂起（suspend）时才会暂停。
-- 全局变量与局部变量
-- a = 5 -- 全局
-- local b = 10 -- 局部
-- function joke()
--     c = 20 -- 全局
--     local d = 100 -- 局部
--     print(c, d) -- 20, 100
-- end
-- joke()
-- print(c, d) -- 20, nil
-- do
--     local a = 6 -- 局部变量
--     b = 6 -- 全局
--     print(a, b) -- 6,6
-- end
-- print(a, b) -- 5, 6
-- a, b ,c = 0, 1
-- print(a, b, c) -- 0, 1, nil
-- a, b, c = a + 1, b + 1, b + 2
-- print(a, b, c) -- 1, 2, 3
-- a, b, c = 0 -- 如果要对多个变量赋值必须依次对每个变量赋值
-- print(a, b, c) -- 0, nil, nil
--[[ 
    应该尽可能的使用局部变量，有两个好处：
    1. 避免命名冲突。
    2. 访问局部变量的速度比全局变量更快。
 ]]
-- site = {}
-- site["key"] = "www.runoob.com"
-- print(site["key"])
-- print(site.key)
-- if 0 then
--     print("0 is true")
-- end
-- local function max(num1, num2)
--     if num1 > num2 then
--         return num1
--     elseif num1 == num2 then
--         print('None')
--     else
--         return num2
--     end
-- end
-- print('两值比较最大值为 ', max(10, 4))
-- print('两值比较最大值为 ', max(5, 6))
-- print('两值比较最大值为 ', max(10, 10))
-- lua中可以将函数作为参数传递给函数
-- myprint = function(params)
--     print('这是打印函数 - ##', params, '##')
-- end
-- function add(num1, num2, functionPrint)
--     local result = num1 + num2
--     functionPrint(result)
-- end
-- myprint(10)
-- add(2, 5, myprint)
-- myprint = function(params)
--     print('This is print function - ##', params, '##')
-- end
-- function add(num1, num2, functionPrint)
--     local result = num1 + num2
--     functionPrint(result)
-- end
-- -- 个人感觉还是因为函数可以赋值给变量，变量加()便可以调用该函数了
-- myprint(10)
-- add(2, 5, myprint)
-- lua的下标是从 1 开始的
-- string.find()，返回匹配串“开始和结束的下标”
-- s, e = string.find('www.runoob.com', 'runoob')
-- print(s, e)
-- function maximum(a)
--     local mi = 1 --1
--     local m = a[mi] -- 8
--     for i, value in ipairs(a) do
--         if value > m then
--             mi = i -- mi为下标
--             m = value -- m 为值
--         end
--     end
--     return m, mi
-- end
-- test1, test2 = maximum({8, 10, 23, 12, 5})
-- print(test1, test2)
-- print(maximum({8, 10, 23, 12, 5}))
-- 可变参数
-- function add(...)
--     local s = 0
--     for index, value in ipairs(...) do
--         s = s + value
--     end
--     return s
-- end
-- print(add(3, 4, 5, 6, 7))
-- 上面例子一直执行失败，不知道为什么
-- function average(...)
--     result = 0
--     local arg = {...}
--     for index, value in ipairs(arg) do
--         print(index, value)
--         result = result + value
--     end
--     print("总共传入 " .. #arg .. " 个数")
--     return result/#arg
-- end
-- print("平均值为 ", average(10, 5, 3, 4, 5, 6))
-- 也可以通过select("#"", ...) 来获取可变参数的数量
-- function average(...)
--     result = 0
--     local arg = {...}
--     for index, value in ipairs(arg) do
--         result = result + value
--     end
--     print("总共传入 " .. select("#", ...) .. " 个数")
--     return result/select("#", ...)
-- end
-- print("平均值为 ", average(10, 5, 3, 4, 5, 6))
-- function fwrite(fmt, ...)
--     return io.write(string.format(fmt, ...))
-- end
-- fwrite("runoob\n")
-- fwrite("%d%d\n", 1, 2)
-- select('#', ...)，返回可变参数的长度
-- select(n, ...) 返回从起点n开始到结束位置的所有参数列表
-- function f(...)
--     a = select(3, ...)
--     print(a)
--     print(select(3, ...))
-- end
-- f(0,1,2,3,4,5)
-- -- 两者好像差别不大啊，~。~

-- do
--     function foo(...)
--         for i = 1, select('#', ...), 1 do
--            local arg = select(i, ...)
--            print("arg", arg)
--         end
--     end
--     foo(1, 2, 3, 4)
-- end

-- do
--     function foo(...)
--         for i = 1, select("#", ...), 1 do
--             local arg = select(i, ...)
--             print("arg", arg)
--         end
--     end
--     foo(1, 2, 3, 4)
-- end

a = 21
b = 10
if a == b then
    print('Line 1 -a 等于 b')
else
    print('Line 1 -a 不等于 b')
end

if a ~= b then
    print('Line 1 -a 不等于 b')
else
    print('Line 1 -a 等于 b')
end


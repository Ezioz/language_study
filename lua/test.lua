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
-- a = 21
-- b = 10
-- if a == b then
--     print('Line 1 -a 等于 b')
-- else
--     print('Line 1 -a 不等于 b')
-- end
-- if a ~= b then
--     print('Line 1 -a 不等于 b')
-- else
--     print('Line 1 -a 等于 b')
-- end
-- array = {}
-- for i = -2, 2 do
--     array[i] = i * 2
-- end
-- for i = -2, 2 do
--     print(array[i])
-- end
-- array = {}
-- for i = 1, 3 do
--     array[i] = {}
--     for j = 1, 3 do
--         array[i][j] = i * j
--     end
-- end
-- 3 就是个数限制，数组长度
-- for i = 1, 3 do
--     for j = 1, 3 do
--         print(array[i][j])
--     end
-- end
-- array = {"Lua", "Tutorial"}
-- for i = 1, 2 do
--     print(array[i])
-- end
-- 泛型for迭代器，pairs 返回（保存）迭代函数、状态常量、控制常量
-- array = {'Google', 'Runoob'}
-- for key, value in pairs(array) do
--     print(key, value)
-- end
-- 无状态迭代器，不保留任何状态的迭代器
-- function square(iterator, currentN)
--     if currentN < iterator then
--         currentN = currentN + 1
--         return currentN, currentN * currentN
--     end
-- end
-- for i, n in square, 3, 0 do
--     print(i, n)
-- end
-- function square(v1, v2)
--     if v1 < v2 then
--         v1 = v1 + 1
--         return v1, v1 * v1
--     end
-- end
-- for i, n in square, 0, 3 do
--     print(i, n)
-- end
-- function sqa(v1, v2)
--     if v2 < v1 then
--         v2 = v2 + 1
--         return v2, v2 * v2
--     end
-- end
-- for i, v in sqa, 3, 0 do
--     print(i, v)
-- end
-- 迭代器先过一下
-- mytable = {}
-- mytable[1] = "Lua"
-- print(mytable[1])
-- mytable = nil
-- print(mytable[1])
-- mytable = {}
-- print('mytable 的类型是 ', type(mytable))
-- mytable[1] = 'Lua'
-- mytable['wow'] = 'before'
-- print('mytable 的索引为1 的元素为 ', mytable[1])
-- print('mytable 的索引为wow 的元素为 ', mytable['wow'])
-- alternatetable = mytable
-- print('alternatetable 索引为 1 的元素是 ', alternatetable[1])
-- print('mytable 索引为 wow 的元素是 ', alternatetable['wow'])
-- alternatetable['wow'] = 'after'
-- print('mytable 索引为 wow 的元素是 ', mytable['wow'])
-- -- 释放变量
-- alternatetable = nil
-- print('alternatetable 是 ', alternatetable)
-- -- mytable 仍然可以访问
-- print("mytable 索引为 wow 的元素是 ", mytable["wow"])
-- mytable = nil
-- print("mytable 是 ", mytable)
-- fruits = {'banana', 'origin', 'apple'}
-- print('连接后的字符串 ', table.concat(fruits))
-- print('连接后的字符串 ', table.concat(fruits, ', '))
-- print('连接后的字符串 ', table.concat(fruits, ', ', 2, 3))
-- table.insert(fruits, 'mango')
-- print('4: ', fruits[4])
-- table.insert(fruits, 2, 'grapes')
-- print('2: ', fruits[4])
-- print('last:', fruits[5])
-- table.remove(fruits)
-- print('last:', fruits[5])
-- print('before----------------------')
-- for k, v in ipairs(fruits) do
--     print(k, v)
-- end
-- print('after-----------------------')
-- table.sort(fruits)
-- for k, v in ipairs(fruits) do
--     print(k, v)
-- end
-- table.insert(fruits, 'zhu')
-- print('4: ', fruits[4])
-- table.insert(fruits, 2, 'jing')
-- print('2: ', fruits[2])
-- print('last: ', fruits[5])
-- table.remove(fruits, 5)
-- print('last: ', fruits[5])
-- print('before-------------')
-- for k, v in ipairs(fruits) do
--     print(k, v)
-- end
-- print('after--------------')
-- table.sort(fruits)
-- for k, v in ipairs(fruits) do
--     print(k, v)
-- end
-- tab1 = {[1] = 2, [2] = 4, [3] = 80, [4] = 10}
-- print(tab1[1])
-- print('tab1 max-length: ', table.maxn(tab1))
-- -- 注：table.maxn 在5.2版本之后该方法不存在了，本人使用的是5.1.5
-- function table_manx(t)
--     local mn = nil
--     for k, v in pairs(t) do
--         if mn == nil then
--             mn = v
--         end
--         if mn < v then
--             mn = v
--         end
--     end
--     return mn
-- end
-- print('tab1 max-length', table_manx(tab1))
-- print('tab1 len', #tab1)
-- 模块
-- package.path = './lua/?.lua'
-- local m = require('module')
-- print(m.constant)
-- m.func1()
-- m.func3()
--[[ test
    require 文件加载策略
    1. 用于搜索lua文件的路径存放在全局变量 package.path 中
    2. 当lua启动后，会以环境变量 LUA_PATH 的值来初始环境变量，如果没有
    找到该变量，则使用一个编译时定义的默认路径来初始化
    3. 如果没有 LUA_PATH 这个环境变量，也可以自定义设置，在当前用户根目录下
    打开 .profile 文件，xxxxx
 ]]
-- c 包，在使用前必须加载并连接，在大多数系统中，最容易实现的方式是通过动态链接库机制
-- lua在一个叫 loadlib 函数内提供了所有的动态链接库功能，这个函数的两个参数：库的绝对路径和初始化函数
-- 元表metatable，允许改变table 的行为。fuck!
-- local testsr = 'hello test'
-- local testtbl = {name = 'test', age = 6666}
-- print('teststr metatable is ->', getmetatable(testsr))
-- print('testtbl metatable is ->', getmetatable(testtbl))
-- local testMetatbl = {}
-- local finaltbl = setmetatable(testtbl, testMetatbl)
-- dump(finaltbl, 'finaltbl ->')
-- print('testtbl metatable is ->', getmetatable(testtbl))
-- 元表看这个链接：https://www.bilibili.com/read/cv9624282
-- xx = {23}
-- print(xx[2])
-- kk = {}
-- kk = {__index = {[2] = 66}}
-- setmetatable(xx, kk) -- 设定后一个表是前一个表的元表
-- print(xx[2]) -- 并不改变xx表
-- ---------------
-- x = {12}
-- kk = {
--     __index = function(xx, aaaa)
--         if aaaa == 2 then
--             return 666
--         end
--     end
-- }
-- setmetatable(x, kk)
-- print(x[2])
-- ---------------
-- x = {23, 5, 7}
-- o = {66, -1, 2}
-- k40 = {
--     __add = function(tbl, tbl2)
--         for i = 1, #tbl do
--             tbl[i] = tbl[i] + tbl2[i]
--         end
--         return tbl
--     end
-- }
-- setmetatable(x, k40)
-- abc = x + o
-- for i = 1, #abc do
--     print(abc[i])
-- end
-- -------------------
-- function table_maxn(t)
--     local mn = 0
--     for k, v in pairs(t) do
--         if mn < k then
--             mn = k
--         end
--     end
--     return mn
-- end
-- mytable =
--     setmetatable(
--     {1, 2, 3},
--     {
--         __add = function(mytable, newtable)
--             for i = 1, table_maxn(newtable) do
--                 table.insert(mytable, table_maxn(mytable) + 1, newtable[i])
--             end
--             return mytable
--         end
--     }
-- )
-- secondtable = {4, 5, 6}
-- mytable = mytable + secondtable
-- for k, v in ipairs(mytable) do
--     print(k, v)
-- end
-- 协同程序，一个具有多个线程的程序可以同时运行几个线程，而协同程序却需要彼此协作的运行。
-- 暂且一放
-- 面向对象
--[[ oop
    tab 描述对象的属性
    function 用来表示方法
    类，可以通过table + function 模拟出来
 ]]
-- account = {blance = 0}
-- function account.withdraw(v)
--     account.blance = account.blance - v
-- end
-- account.withdraw(100.00)
-- 元类
-- 这个例子需要再看看
-- rectangle = {area = 0, length = 0, breadth = 0}
-- function rectangle:new(o, length, breadth)
--     o = o or {}
--     setmetatable(o, self)
--     self.__index = self
--     self.length = length or 0
--     self.breadth = breadth or 0
--     self.area = length * breadth
--     return o
-- end

-- function rectangle:printarea()
--     print("area is :", self.area)
-- end
-- r = rectangle:new(nil, 10, 20)
-- print(r.length)
-- r:printarea()
-- -------------------------https://segmentfault.com/a/1190000022299831
-- local people = {name = ''}

-- function people:say()
--     print('people : ' .. self.name)
-- end

-- function people:new(name)
--     local o = {name = name}
--     setmetatable(o, {__index = self})
--     return o
-- end

-- local teacher = {}
-- function teacher:sayup()
--     print('teacher : ' .. self.name)
-- end
-- setmetatable(teacher, {__index = people})

-- local xiaohua = people:new('xiaohua')
-- xiaohua:say()
-- local xiaoming = teacher:new('xiaoming')
-- xiaoming:say()
-- xiaoming:sayup()
-- ---------------------------------------------------

people = {name = ''}

function people:say()
    print('people : ' .. self.name)
end

function people:new()
    local o = {name = name}
    setmetatable(o, {__index = self})
    return o
end

local teacher = {}
function teacher.sayup(self)
    print('teacher :' .. self.name)
end

setmetatable(teacher, {__index = people})

local xiaohua = people:new('xiaohua')
xiaohua:say()
local xiaoming = teacher:new('xiaoming')
xiaoming:say()
xiaoming.sayup(teacher)

-- self:https://zhuanlan.zhihu.com/p/115159195
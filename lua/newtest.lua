--[[
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-02 14:07:29
LastEditors: ahtoh
LastEditTime: 2021-12-03 09:10:40
--]]
--[[
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-02 14:07:29
LastEditors: ahtoh
LastEditTime: 2021-12-02 14:07:30
--]]
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
-- x = {23, 4, 5}
-- o = {4, 2, 2}
-- k4 = {
--     __add = function(tab1, tab2)
--         for i = 1, #tab1 do
--             tab1[i] = tab1[i] + tab2[i]
--         end
--         return tab1
--     end
-- }
-- setmetatable(x, k4)
-- abc = x + o
-- for i=1, #abc do
--     print(abc[i])
-- end
-- a = {'test', 1}
-- b = {__index = {1, 2, 3, 4}}
-- c = setmetatable(a, b)
-- for k, v in ipairs(c) do
--     print(k, v)
-- end
-- --------------------------------------------------
-- local ffi = require('D:/Program Files/Binaries-LuaDist-batteries-0.9.8-Windows-x86/bin/libffi.dll')
-- ffi.cdef [[
--     void Sleep(int ms);
--     int poll(struct pollfd *fds, unsigned long nfds, int timeout);
-- ]]
-- local sleep
-- if ffi.os == 'Windows' then
--     function sleep(s)
--         ffi.C.Sleep(s * 1000)
--     end
-- else
--     function sleep(s)
--         ffi.C.poll(nil, 0, s * 1000)
--     end
-- end
-- for i = 1, 160 do
--     io.write('.')
--     io.flush()
--     sleep(0.01)
-- end
-- io.write('\n')

-- function add(...)
--     local s = 0
--     for i, v in ipairs {...} do
--         s = s + v
--     end
--     return s
-- end
-- print(add(3, 4, 5, 6, 7))

function add(...)
    local c = 0
    for i, v in ipairs {...} do -- 注意，此处ipairs 后是 {} 
        c = c + v
    end
    return c
end

print(add(3, 4, 5, 6, 7))

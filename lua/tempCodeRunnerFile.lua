square = shape:new()
-- -- 派生类方法 new
-- function square:new(o, side)
--     o = o or shape:new(o, side)
--     setmetatable(o, self)
--     self.__index = self
--     return o
-- end
-- -- 派生类方法 printarea
-- function square:printarea()
--     print('zheng area is ', self.area)
-- end
-- -- 创建对象
-- mysquare = square:new(nil, 10)
-- mysquare:printarea()
-- rectangle = shape:new()
-- -- 派生类方法new
-- function rectangle:new(o, length, breadth)
--     o = o or shape:new(o)
--     setmetatable(o, self)
--     self.__index = self
--     self.area = length * breadth
--     return o
-- end

-- -- 派生类方法 printarea
-- function rectangle:printarea()
--     print('rect angle area is', self.area)
-- end
-- -- 创建对象
-- myrectangle = rectangle:new(nil, 10, 20)
-- myrectangle:printarea()

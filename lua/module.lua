--[[
Descripttion: 
version: 
Author: ahtoh
Date: 2021-12-01 10:33:40
LastEditors: ahtoh
LastEditTime: 2021-12-01 10:33:41
--]]

module1 = {}
module1.constant = 'this is changliang'

function module1.func1()
    io.write('this is public function\n')
end

local function func2()
    print('this is the private function\n')
end
function module1.func3()
    func2()
end

return module1

function test_class(cpp_arg)
    print ("in test_class-------------------------------------------------------------------------------------------------------")

    -- arg a is lua function, arg cpp_arg is C++ void* type.
    tb = {["ohhahha"] = "value", ["fuck_xxx"] = "nice"}
    a = function() print(".............@$#%") end

    -- global C++ function test. 
    global_foo(255, 12345, 9966, 77899, "^_^", tb, 56, a, cpp_arg)

    -- class static function test.
    foo_t:static_foo(255, 12345, 9966, 77899, "^_^", tb, 56, a, cpp_arg)

    -- class constructor test.
    reg_ptr = test_reg_t:new(255, 12345, 9966, 77899, "^_^", tb, 56, a, cpp_arg)

    -- class method test.
    reg_ptr:dump(255, 12345, 9966, 77899, "^_^", tb, 56, a, cpp_arg)

    -- test parent class method
    reg_ptr:foo()

    -- class property test code.
    print ("test index function:", reg_ptr.field)
    reg_ptr.field = 667788
    print ("test index function:", reg_ptr.field)
    -- 

    -- test lambda function
    -- reg_ptr.lua_obj = function () print("oh field nice") end
    reg_ptr.ok = "jjjjjjjj"
    print ("reg_ptr.ok:", reg_ptr.ok)

    obj = reg_ptr:creat_ptr()
    obj:foo()
    reg_ptr:test_ptr(obj)
    obj:delete()
    print ("test_class end------------------------------")

    --tclass_t:new()
    --tclass_t:foo()

    -- test class deconstructor .
    reg_ptr:delete()
    return 0
end

function lua_performance_test()
end


local gtb = {}
for i = 1, 1000*1000 do
gtb[i] = i
end

function base_logic(arg)

    local tb  = {}
    -- 构建10个元素的table
    for i  = 1, 10 do
        tb[i] = i;
    end

    -- tb 中10次查找
    fun = function ()
        for i  = 1, 10 do
            local ret = gtb[i];
        end
    end

    -- 10 个判断语句
    if (arg == 1) then
        fun()
    elseif (arg == 2) then
        fun()
    elseif (arg == 3) then
        fun()
    elseif (arg == 4) then
        fun()
    elseif (arg == 5) then
        fun()
    elseif (arg == 6) then
        fun()
    elseif (arg == 7) then
        fun()
    elseif (arg == 8) then
        fun()
    elseif (arg == 9) then
        fun()
    else
        fun()
    end
end

function test_lua()

per_begin()
for i = 1, 1000*1000 do
performance_test()
end
local x = get_cost()
print ("in lua cost:", x)

per_begin()
for i = 1, 1000*1000 do
performance_test()
end
local x = get_cost()
print ("in lua invoke C func cost:", x)

-- test lua table performance

local uid = 15698
local tb = {}
per_begin()
for i = 1, 1000*1000 do
tb[uid + i] = i
end
local x = get_cost()
print ("in lua insert table cost:", x)

-- find table
per_begin()
for i = 1, 1000*1000 do
local d = tb[uid + i]
end
local x = get_cost()
print ("in lua hitfind table cost:", x)

-- find table
per_begin()
for i = 1, 1000*1000 do
local d = tb[uid + 1000*1000]
end
local x = get_cost()
print ("in lua find table cost:", x)


-- 基本逻辑函数测试
per_begin()
for i = 1, 1000*1000 do
    base_logic(i % 10)
end
local x = get_cost()
print ("\nin base logic cost:", x)

end

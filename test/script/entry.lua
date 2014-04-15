require "a"
require "b"

print "Hello World In Luaaaaaaaa"

afun1()
afun2()
bfun1()
bfun2()

function callback(p)
   p:func1(123)

   logfatal("TEST_MODULE", "fatal log!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
   logerror("TEST_MODULE", "error log!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
   logwarn("TEST_MODULE", "warn log!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
   loginfo("TEST_MODULE", "info log!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
   logtrace("TEST_MODULE", "trace log!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
   logdebug("TEST_MODULE", "debug log!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")

   for i = 0, 10 do
      local rand_val = get_rand(0, 3)
      print("rand_val:" .. rand_val)
   end
end

user_t = {}
user_t.__index = user_t

function user_t:new()

   local ret = {}
   setmetatable(ret, self)
   return ret

end

function user_t:func1()
   print("func1!!!!!!!!!!!!!!!!!!!!!!!!")
end

g_u = user_t:new()

cpp_callback(g_u)


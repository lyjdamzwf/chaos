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
end
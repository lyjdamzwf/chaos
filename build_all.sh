sh autogen.sh
./configure
make

if [ ! -d lib ];
then
mkdir lib;
fi

cp -rf chaos/log/libchaos_log.a lib
cp -rf chaos/network/libchaos_network.a lib
cp -rf chaos/task_service/libchaos_task_service.a lib
cp -rf chaos/thread/libchaos_thread.a lib
cp -rf chaos/utility/libchaos_utility.a lib

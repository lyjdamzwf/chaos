def_dir=/usr/local

if [ ! -z $1 ]; then
    def_dir=$1
fi

echo "install directory:"$def_dir

aclocal
libtoolize
autoconf
autoheader
automake --add-missing
./configure --prefix=$def_dir
make


#!/bin/sh

aclocal
libtoolize
autoconf
autoheader
automake --add-missing

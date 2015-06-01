INSTALL NLTEMPLATE LIB
----------------------

You need cmake and make. Do this...

``` bash
  cd ./NLTemplate
  mkdir ./build
  cd ./build
  # If you need a 32bit version do this:
  # cmake -DCMAKE_CXX_FLAGS=-m32 -DCMAKE_SHARED_LINKER_FLAGS=-m32 ../
  cmake -G "Unix Makefiles" ../
  make
  su -c 'make install'
  su -c 'echo "/usr/local/lib/nltemplate/" > /etc/ld.so.conf.d/nltemplate.conf'
  su -c 'ldconfig'

```

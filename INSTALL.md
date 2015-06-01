INSTALL NLTEMPLATE LIB
----------------------

You need cmake and make. Do this...

``` bash
  cd ./NLTemplate
  mkdir ./build
  cd ./build
  cmake -G "Unix Makefiles" ../
  make
  su -c 'make install'
  su -c 'echo "/usr/local/lib/nltemplate/" > /etc/ld.so.conf.d/nltemplate.conf'
  su -c 'ldconfig'

```

::Edit this path or it won't compile
set gbdk_root=F:\IDE+Compilers\gbdk\bin

mkdir output

%gbdk_root%\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o output/demo.o demo.c
%gbdk_root%\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o output/demo.gb output/demo.o
Installation:
```
wget -qO- www.sifflez.org/lectures/compil/lab1/dragon-tiger.tar.gz | tar zxv
```

```
cd dragon-tiger/
```

## task 1
```
rm -f hello.o hello.bin
src/driver/dtiger -o hello.o hello.tig
clang++ hello.o src/runtime/posix/libruntime.a -o hello.bin -no-pie
./hello.bin
```

## task 2
```
rm -f fibonacci.o fibonacci.bin
src/driver/dtiger -o fibonacci.o fibonacci.tig
clang++ fibonacci.o src/runtime/posix/libruntime.a -o fibonacci.bin -no-pie
./fibonacci.bin
```

## task 3
```
rm -f read_unsigned.o read_unsigned.bin
src/driver/dtiger -o read_unsigned.o read_unsigned.tig
clang++ read_unsigned.o src/runtime/posix/libruntime.a -o read_unsigned.bin -no-pie
./read_unsigned.bin
```

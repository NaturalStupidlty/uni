### Installation:
```
wget -qO- www.sifflez.org/lectures/compil/lab2/dragon-tiger.tar.gz | tar zxv
```

```shell
./configure
```
### Building
```
make clean
make
```

## Tasks

### Support for integers
```
echo "1*2" | src/driver/dtiger --dump-ast -
```

### Support for more binary operators and adding precedence rules
```
echo "3 + 2 * 2" | src/driver/dtiger --dump-ast -
```

### Support for the boolean OR operator
```
echo "a | b" | src/driver/dtiger --dump-ast -
```
### Support for if then else constructs
```
echo "if a then b" | src/driver/dtiger --dump-ast -
```

### AST evaluator for simple Tiger int expressions

`IntegerLiteral`
```
echo "3" | src/driver/dtiger --eval -
```

`BinaryOperator`
```
echo "3 + 2 * 2" | src/driver/dtiger --eval -
```

`Sequence`
```
echo "3 + (2 + 1) * 2" | src/driver/dtiger --eval -
```

`IfThenElse`
```
echo "if 3 < 2 then 1 else 2" | src/driver/dtiger --eval -
```
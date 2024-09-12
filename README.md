# competitive-programming

## g++

By default macOS does not have `g++` installed. However, we can install `g++` (which is part of GCC - GNU Compiler Collection) via Homebrew.

1. Install [Homebrew](https://brew.sh) if it's not already installed.
2. Install [GCC](https://formulae.brew.sh/formula/gcc) (which includes `g++`) using Homebrew:
```bash
brew install gcc
```
3. Homebrew installs GCC binaries with version numbers (e.g., `g++-14`) to the path `/usr/local/bin/g++-14`. I use `g` as a shortcut for `g++` with flags. To achieve this, you can set up a function in your `~/.zshrc` that includes the specific flags you want to use every time you compile with `g`:
```bash
g() {
    # Output filename
    output="${1%.*}.out"
    # Replace '14' with the installed GCC version number
    g++-14 -fdiagnostics-color=always -std=c++17 -Wall -Wshadow "$1" -o "$output"
}
```
4. Reload your `.zshrc` to apply the changes:
```bash
source ~/.zshrc
```
Now, when you type `g demo.cpp`:
```bash
g demo.cpp
```
This will run:
```bash
g++-14 -fdiagnostics-color=always -std=c++17 -Wall -Wshadow demo.cpp -o demo.out
```

## bits/stdc++.h

https://codeforces.com/blog/entry/70957
https://forums.developer.apple.com/forums/thread/723393
fatal error: 'bits/stdc++.h' file not found

Try creating the bits directory simply at this location:
/usr/local/include/
(usr is in MACINTOSH HD location)
The final location of the header should be: /usr/local/include/bits/stdc++.h

## M&C

### 2024-08-05

- [x] https://informatics.msk.ru/mod/statements/view.php?id=249 (F-J)
- [x] https://informatics.msk.ru/mod/statements/view.php?id=2587 (все задачи)
- [x] https://informatics.msk.ru/mod/statements/view.php?id=2585 (A-N)

### 2024-08-09

- [x] https://informatics.msk.ru/mod/statements/view.php?id=280 (P-R)
- [x] https://informatics.msk.ru/mod/statements/view.php?id=208 (I-O)
- [x] https://informatics.msk.ru/mod/statements/view.php?id=282 (все задачи)

### 2024-08-12

- [x] https://informatics.msk.ru/mod/statements/view.php?id=248 (J-P)

### 2024-08-16

- [x] https://informatics.msk.ru/mod/statements/view.php?id=254 (A-B)
- [x] https://informatics.msk.ru/mod/statements/view.php?id=253 (все задачи)

### 2024-08-19

- [x] https://informatics.msk.ru/mod/statements/view.php?id=268 (все задачи)
- [x] https://informatics.msk.ru/mod/statements/view.php?id=2550 (A-B)

### 2024-08-23

- [x] https://informatics.msk.ru/mod/statements/view.php?id=211 (A-M кроме B,K,M)

### 2024-08-26

- [x] https://informatics.msk.ru/mod/statements/view.php?id=250 (все задачи)

### 2024-08-30

- [x] https://informatics.msk.ru/mod/statements/view.php?id=207 (C,F,I)
- [x] https://informatics.msk.ru/mod/statements/view.php?id=206 (все задачи)

### 2024-09-05

- [x] https://codeforces.com/group/u8pLzn9xS6/contest/547800

### 2024-09-07

- [ ] https://acmp.ru/asp/do/index.asp?main=section&id_section=1
- [ ] https://informatics.msk.ru/mod/statements/view.php?id=271 Квадратичные сортировки (F, G, H, I)
- [ ] https://informatics.msk.ru/mod/statements/view.php?id=1129 Быстрая сортировка (В)
- [ ] https://informatics.msk.ru/mod/statements/view.php?id=1121 Сортировка слиянием (А, В)

чтобы перейти на 1 уровень:
сортировки (сорт слиянием, быстрая сорт, пузырковая сорт, сорт вставками, квадратичная сорт)
бинарный поиск
динамическое програмирование
графы

## TODO

Rate Limiting with Redis
Postgresql vacuum 
Isolation rules
Difference between TCP and Websocket
Checking if IPv4 Address in Network Prefix

round_robin
ip_hash
least_conn

Что такое свойство ACID в базе данных?
Уровни изоляции в SQL
  Serializable
  Repeatable reads
  Read committed
  Read uncommitted


Алгоритмы балансировки нагрузки
  Static load balancing
    Round-robin method
    Weighted round-robin method
    IP hash method

  Dynamic load balancing 
    Least connection method
    Weighted least connection method
    Least response time method
    Resource-based method

Rate Limiting 


что такое solid
какой формат использует grpc - бинарный
контракты
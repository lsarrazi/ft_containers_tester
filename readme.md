# ft_containers tester 🏴‍☠️ 

## Installation

Go into your project folder and type:
```bash
git clone https://github.com/lsarrazi/ft_containers_tester.git tester && cd tester
```

### Installation + Base Test 🍮

```bash
git clone https://github.com/lsarrazi/ft_containers_tester.git tester && cd tester && ./test.sh base/*/*
```

Set your project path in **test.sh**

```bash
ftcontainers_path=".." # Path to your project headers
```

## Usage

Run all base tests
```bash
./test.sh base/*/*
```

Run all base tests + all bonus tests
```bash
./test.sh base/*/* bonus/*/*
```

Run specific container only
```bash
./test.sh base/list/*
```

Run specific test only
```bash
./test.sh base/list/constructor
```
### Debug mode
Run debug mode (specific test only)
```bash
./test.sh debug base/list/constructor
```

Debug mode displays compilation errors and runs lldb in case of crash.

## Dependencies

This script depends on the following programs: **optional*
- **Compiler**: clang++, g++ *(Could be set in test.sh)*
- **Debugger**: lldb, gdb *(Could be set in test.sh)*
- **Debugging tool:** valgrind*
- **Shell**: bash

### Install LLDB and valgrind 👍

```bash
sudo apt-get install valgrind lldb-10 && ln -s /usr/bin/lldb-10 /usr/local/bin/lldb
```

## Informations

Each test attempts to debug a particular function. The tests may depend on different functions.

You will be able to find these files in each test directory:

- **log.txt**: The compilation logs
- **expected.txt**: The output that your library should produce to succeed the test
- **out.txt**: The actual output that your library produce
- **diff.txt**: The difference between expected.txt and output.txt
- **valgrind.txt**: The output of valgrind

Each test is executed independently of the others in its own executable.

Tests are compiled and run in parallel to maximize performance.

The majority of the original tests are copies from https://www.cplusplus.com/reference/stl/

Here is what it looks like:

![alt text](./res/tester.png "./test.sh base/list/*")

## Author / Contributor

**Everyone can contribute by enhancing a test or adding a new one. Just make a pull request**

- lsarrazi 👑
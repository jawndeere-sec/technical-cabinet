# Reading Files Incrementally

## The Shape

The log explorer needed to inspect a file without loading the entire thing into memory. The reusable shape is:

1. Receive a path.
2. Construct an `std::ifstream` from it.
3. Stop early if the file did not open.
4. Keep one `std::string` for the current line.
5. Let `std::getline` replace that string on each iteration.
6. Retain only the state the result needs, such as a running count.

The stream is the connection to the file. It does not mean the whole file has been copied into one giant string.

```cpp
std::ifstream file(path);

if (!file.is_open()) {
    return 2;
}

std::string line;
while (std::getline(file, line)) {
    // inspect this line
}
```

The `while` condition does two jobs: it attempts to extract the next line and converts the resulting stream state to true or false. The body runs only when a line was extracted successfully.

## Finding A Substring Anywhere

`std::string::find` returns the starting position of a match. If it finds nothing, it returns `std::string::npos`.

```cpp
if (line.find("Failed password") != std::string::npos) {
    failedAttempts += 1;
}
```

This is an exact, case-sensitive substring search. It is not a parser and does not know what an SSH event is.

The earlier Workweek pattern used this:

```cpp
line.rfind("Password:", 0) == 0
```

That is useful for testing whether a line **starts with** a prefix. It failed for authentication logs because those lines started with a timestamp and the desired text appeared later.

## Command-Line Paths And Exit Status

For this invocation:

```text
./log-explorer fixtures/auth.log
```

`argc` is `2`, `argv[0]` names the executable, and `argv[1]` contains the supplied path. Check `argc` before touching `argv[1]`.

The log explorer used separate statuses:

```text
0  processing succeeded
1  required path was missing
2  supplied path could not be opened
```

That distinction lets a shell or another program determine what happened without parsing human-readable output.

## What A Match Proves

If the counter reports three, it proves that three lines in the supplied bytes contained the exact text `Failed password`.

It does **not** prove that:

- the file came from `sshd`;
- the records are authentic;
- three distinct people or hosts were involved;
- the activity was an attack;
- every failed SSH authentication format was counted.

A useful accidental test made this boundary obvious: running the counter against its own source found one match because the source contained the search literal. The program was correct; the supposed zero-match fixture was not.

## Resource Lifetime

The `std::ifstream` closes its owned file when the stream object is destroyed at the end of its scope. EOF stops further extraction, but EOF itself is not what closes the file. The ownership side of this mechanism is covered in [Classes: RAII](../classes/notes.md#raii-making-object-lifetime-own-resource-lifetime).

[`file-input.cpp`](file-input.cpp) keeps the complete reusable CLI shape in one small example. It is compile-verified and expects a filepath when run.

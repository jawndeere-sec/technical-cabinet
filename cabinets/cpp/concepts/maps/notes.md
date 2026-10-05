# Maps And Associative Counting

## The Problem Shape

A single integer works when I only need one total. It stops being enough when the result must retain a separate count for every distinct source:

```text
"192.0.2.10"    → 2
"198.51.100.7"  → 1
```

That is a key-value relationship. The source token is the key, and its running count is the value.

```cpp
std::map<std::string, int> sourceCounts;
```

Each key in an `std::map` is unique. The map owns one integer value for each source string rather than relying on matching positions across separate arrays.

## Counting First And Repeated Occurrences

The Log Explorer used:

```cpp
sourceCounts[source] += 1;
```

`operator[]` follows two different paths:

```text
Key absent:
    insert the key with int's default value, 0
    increment 0 to 1

Key present:
    retrieve the existing value
    increment it again
```

This is convenient for counters, but it has an important side effect: `operator[]` is not a read-only lookup. Asking for a missing key inserts it. Use `find` or `at` when an accidental insertion would be wrong.

## Scope Owns The Accumulation Window

The map must exist before the loop whose observations it accumulates:

```cpp
std::map<std::string, int> sourceCounts;

while (/* another record exists */) {
    // extract one source
    sourceCounts[source] += 1;
}
```

Declaring the map inside the loop would create and destroy a fresh container for every record. Declaring it inside the file-processing function but before the loop gives it the desired lifetime: one empty map per file-processing call, retained across every line in that file.

## Iterating And Printing

`std::cout` has no default formatting rule for an entire map. Iterate over its entries and choose the representation explicitly:

```cpp
for (const auto& entry : sourceCounts) {
    std::cout << entry.first << ": " << entry.second << '\n';
}
```

- `entry.first` is the key.
- `entry.second` is the value.
- `const` prevents the output pass from changing the entries.
- `&` avoids copying each key-value pair.
- `auto` lets the compiler spell the map's pair type.

Trying to stream `sourceCounts` directly produced an `invalid operands to binary expression` diagnostic because no matching `operator<<` exists for `std::map`.

## Why `std::map` Here

`std::map` keeps keys ordered. That made the Log Explorer's summary deterministic even when source tokens appeared in the opposite order in the input.

An `std::unordered_map` can also associate each source with a count and often provides faster average lookup, but its iteration order is not guaranteed. Deterministic output was more useful than that tradeoff for this small CLI.

## Keep Separate Claims Separate

The Log Explorer's total failure count changed as soon as a line contained `Failed password`. Its source map changed only after both source delimiters were found successfully.

That means:

```text
failedAttempts may be greater than the sum of sourceCounts
```

A map entry such as `192.0.2.10: 2` proves that two matching records yielded that exact source token. The map does not validate IP syntax, authenticate the input file, establish distinct network attempts, or prove malicious activity.

[`map-counting.cpp`](map-counting.cpp) isolates the reusable counting and ordered-output mechanism. Its output is verified by [`map-counting.expected.txt`](map-counting.expected.txt).

Related: [Reading files incrementally](../file-input/notes.md)

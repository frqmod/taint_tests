# taint_tests
Set of test suites for taint tracking, compile.sh will compile `*.c` in current directory.

Every test follows the same basic concept:
1. User inputs 32 bytes into the `userInput` buffer (`0x1337000 - 0x1337020`)
2. `userInput` is transformed in some way that would place data into the `taintBuffer` buffer (`0x2337000 - 0x2337020`)
3. This should taint a portion of the `taintBuffer`, or in most cases, all of it.

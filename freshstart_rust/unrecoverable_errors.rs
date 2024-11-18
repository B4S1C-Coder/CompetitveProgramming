// When panics occur, the failure message is printed, program will unwind, clean up the stack
// and quit. Unwinding means rust walks back up the stack and cleans up the data from each function
// it encounters.

// There is also a way to just abort without cleaning up. In this case, the memory that was being
// used by the program must now be cleaned up by the operating system.

fn main() {
    panic!("Oh no! The program panicked!");
}

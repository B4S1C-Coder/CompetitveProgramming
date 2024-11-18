fn take_ownership(target: String) {
    println!("Ownership of '{target}' has been taken.");
}

fn take_ownership_and_return(target: String) -> String {
    println!("Ownership of '{target}' has been taken.");
    println!("Returning ownership ...");
    return target;
}

fn main() {

    // These are essentially primitve types and they implement the Copy trait
    // Here there is no difference between shallow copy and deep copy.
    let x = 69; // Fixed size, stored on stack
    let y = x;  // Essentially a copy of x on the stack, so both y and x are valid

    // These are complex types and they cannot implement the Copy trait (as below),
    // they implement the drop trait which specify how the memory should be freed.

    let mut s = String::from("damn"); // stored on heap, mutable, unkown size (size not fixed at compile time)
    s.push_str(" fat");

    // This is a shallow copy, only the ptr, len, capacity of s are copied again in the stack
    // so both the ptr's of n and s point to the same address of the heap. So, when both go
    // out of scope both will try to free up the memory in heap. To solve this problem,
    // below essentially s is moved to n and so s is no longer valid (does not exist anymore)
    // so when n goes out of scope the memory in the heap will be freed up (only once, as we needed).

    // let n = s; // essentially std::move(s), s is no longer valid from here on. This is a shallow
    // copy (described above).

    // This is a deep copy, ptr len capacity are copied in the stack and the data in the heap is
    // copied as well in the heap. So ptr of n points to a different location in heap that stores
    // the same data as s (this data is a copy of the data of s).
    let n = s.clone(); // both n and s are valid

    println!("x = {x}, y = {y}"); // Works
    println!("s = {s}, n = {n}"); // Error, with let n = s

    // Similar is the case with functions
    let myStr: String = String::from("fck");
    // take_ownership_and_return(myStr); // myStr is no longer valid after this
    // had myStr would've been of a primitive type such as i32, f64, etc. or a type which
    // implements the copy trait, myStr would've still been valid after this function call.
    
    // Functions can also return ownerships
    let myStr = take_ownership_and_return(myStr);

    println!("{myStr}");
}

fn main() {
    let mut s: String = String::from("rust");
    // &s is a reference to s, it does NOT have ownership of s.
    // this is an immutable reference, we cannot alter s using this reference
    print_first_char(&s); // when &s goes out of scope s is NOT removed.
    alter_string(&mut s); // mutable reference to s, can alter s.

    // There can only be one mutable reference to a particular thing at a time
    // let r1 = &mut s; // No problem (the &mut s was used up by alter_string and got deleted)
    // let r2 = &mut s; // Problem

    // println!("{r1} {r2}"); // results in ERROR as r1 a mutable reference still exists
    // This is by design in rust, this is to prevent data race conditions, where two mutable
    // references might try to modify the underlying value at the same time.
    
    // let r3 = &s;     // no problem
    // let r4 = &s;     // no problem
    // let r5 = &mut s; // problem

    // println!("{r3} {r4} {r5}"); // error
    // This happens because we cannot have a mutable reference to a thing when immutable references
    // to it are still there because the users of the immutable reference don't expect the
    // underlying value to change.
    
    let r6 = &s; // no problem
    let r7 = &s; // no problem
    println!("{r6} {r7}"); // immutable references have been used here, so above problem won't occur

    let r8 = &mut s; // no problem
    println!("{r8}");

    println!("s = {s}");  // s is still valid since it's ownership never changed.
}

fn print_first_char(string: &String) {
    // We can use s here, but this function does NOT have ownership of s so when it goes
    // out of scope s will NOT be removed.
    println!("{}", string.chars().collect::<Vec<_>>()[0]);
}

fn alter_string(string: &mut String) {
    string.push_str(" language");
}

// This causes an error because &s will get deallocated when this function goes out of scope
// so the returned reference would point to an invalid address in memory.
// fn dangling() -> &String {
//     let s = String::from("dangling.");
//     &s
// }

// Instead we can just return the ownership (in case of a type which implements Drop trait)
// or a copy of the value (in case of a type which implements Copy trait)
fn no_dangling() -> String {
    let s = String::from("no dangling.");
    s
}

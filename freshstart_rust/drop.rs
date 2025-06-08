struct SomeSmartPointer {
    data: String,
}

impl Drop for SomeSmartPointer {
    fn drop(&mut self) { // Rust calls this automatically, we can't explicitly call this
        println!("Dropping SomeSmartPointer with data `{}`", self.data);
    }
}

fn main() {
    let a = SomeSmartPointer { data: String::from("Data1") };
    drop(a); // std::mem::drop,  used to forcefully drop something
    // drop() has taken ownership of "a" and as such "a" is no longer valid. You can still shadow
    // "a" etc.
    let b = SomeSmartPointer { data: String::from("Data2") };

    println!("SomeSmartPointers created.");
}

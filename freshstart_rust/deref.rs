use std::ops::Deref;

struct MySmartPointer<T>(T); // Tuple struct

impl<T> MySmartPointer<T> {
    fn new(x: T) -> MySmartPointer<T> {
        MySmartPointer(x)
    }
}

impl<T> Deref for MySmartPointer<T> {
    type Target = T;
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

// Deref coercion
// The below function would work for a reference to MySmartPointer<String> as well
fn hello(name: &str) {
    println!("Hello, {name}!");
}

fn main() {
    let x = 5;
    let y = &x;
    let z = Box::new(x); // points to a copied value of x
    let s = MySmartPointer::new(x);

    assert_eq!(5, x);
    assert_eq!(5, *y);
    assert_eq!(5, *z);
    assert_eq!(5, *s);

    // The following conversion was done by Rust automatically because Rust implements Deref
    // coercion:
    // &MySmartPointer<String> --deref--> &String --[ String --deref--> &str]--> &str

    let x = MySmartPointer::new(String::from("Shadow"));
    hello(&x);

    println!("Done!");
}

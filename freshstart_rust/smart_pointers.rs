// Smart pointers in rust are generally made using structs and must implement the Deref and Drop
// traits. Both String & Vec<T> count as smart pointers as they own some memory and allow us to
// manipluate it. Smart pointers are a general design pattern & many libraries have their own smart
// pointers and we can even make our own. Only the following smart pointers will be discussed:
//
// -> Box<T> for allocating values on the heap
// -> Rc<T> reference counting type that enables multiple ownership (similar to std::shared_ptr)
// -> Ref<T> and RefMut<T> accessed through RefCell<T>, a type that enforces the borrowing rules at
// runtime instead of compile time

use crate::List::{Cons, Nil};

fn main() {
    let val_on_heap = Box::new(5);
    println!("val on heap = {val_on_heap}");

    // Enabling recursive tyes with boxes
    // We can define recursive types via boxes. Eg. cons list datastructure
    // Eg. (1, (2, (3, Nil)))
    
    let list = Cons(1, Box::new(Cons(2, Box::new(Cons(3, Box::new(Nil))))));

}

enum List {
    Cons(i32, Box<List>),
    Nil,
}

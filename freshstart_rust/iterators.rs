fn main() {
    let v1 = vec![1, 2, 3];
    let v1_iter = v1.iter();
    
    // The loop takes ownership of the iterator "v1_iter" and makes it mutable under the hood,
    // with this process "v1_iter" get consumed.
    for val in v1_iter {
        println!("Got: {val}");
    }
    
    // We declare it as mut because calling next(), consumes an element from the iterator and
    // as a result it's internal state changes. When we implement the Iterator trait for any
    // type, we generally have to always implement the next method, as the other methods defined
    // in this trait call next() within their implementations. Mehtods which call next() are known
    // as consuming adapters.
    let mut v1_iter = v1.iter();
    assert_eq!(v1_iter.next(), Some(&1));
    assert_eq!(v1_iter.next(), Some(&2));
    assert_eq!(v1_iter.next(), Some(&3));
    assert_eq!(v1_iter.next(), None);

    // Iterator adapters are methods that do not consume an interator, instead produce different
    // iterators by changing some aspect of the original iterator.
    
    // Iterator adapters are lazy, meaning the closure in the below line won't be called as long
    // as this iterator is NOT CONSUMED. We will get a warning for the same (if we don't use
    // .collect() or any method that consumes the iterator.

    // |------Collection-| |-----Iterator----------| |--- consumes the iterator & gives collection
    let v1_iter: Vec<i32> = v1.iter().map(|x| x + 1).collect();

    assert_ne!(v1, v1_iter);

    filters_by_size();
    println!("done.");
}

// IMPORTANT:
// The values that we get from the calls of next() are immutable references to the values in the
// vector. If we need an iterator which takes ownership of v1 (the vector) and returns owned values
// we use into_iter(), if need to iterate over mutable references, we use iter_mut()

#[derive(Debug, PartialEq)]
struct Shoe {
    size: u32,
    style: String,
}

// The closure here captures "shoe_size" from it's environment i.e. the scope of shoes_in_size()
fn shoes_in_size(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
    shoes.into_iter().filter(|s| s.size == shoe_size).collect()
}

fn filters_by_size() {
    let shoes = vec![
        Shoe { size: 10, style: String::from("kkd") },
        Shoe { size: 13, style: String::from("kkd") },
        Shoe { size: 10, style: String::from("kkd") },
    ];

    let in_my_size = shoes_in_size(shoes, 10);

    assert_eq!(in_my_size, vec![
        Shoe { size: 10, style: String::from("kkd") },
        Shoe { size: 10, style: String::from("kkd") },
    ]);
}

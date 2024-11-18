use std::collections::HashMap; // HashMap<K, V>

fn main() {

    let key1 = String::from("key1");
    let val1 = 69;

    // For types that implement the Copy trait, they would be simply copied to the HashMap
    // but types which implement do not implement the Copy trait (instead they MAY implement
    // the Drop trait) simply have their ownership moved to the HashMap.

    let mut scores: HashMap<String, i32> = HashMap::new();
    scores.insert(key1, val1); // Ownernship moved, key1 no longer valid, but val1 still valid
    scores.insert(String::from("key2"), 42);

    let score: Option<&i32> = scores.get(&String::from("key1"));

    match score {
        Some(t) => println!("{}", *t),
        None => println!("No such key.")
    }

    // Alternate ways
    if let Some(t) = scores.get("key1") {
        println!("{}", t);
    }

    // Another way
    let score: Option<i32> = scores.get("key1").copied();

    match score {
        Some(t) => println!("{}", t),
        None => println!("No such key.")
    }

    // Yet another way (if not found then score = -69 else score = corrs. val in hashmap)
    let score: i32 = scores.get("key7").copied().unwrap_or(-69);
    println!("{}", score);

    // Insert only if key is NOT present
    // Will insert (Hello, 90) only if Hello is NOT already present
    
    // scores.entry() returns and enum Entry
    // or_insert() returns a mutable reference to the value of the key if it exists,
    // otherwise it insert the (key, value) and returns a mutable reference to this
    // newly inserted value.
    scores.entry(String::from("Hello")).or_insert(90);
}

fn some_function() {
    println!("some");
}

fn main() {
    println!("main");
    some_function();
    say_hello("bitch".to_string());
    primitive_hello("oo");
    
    // Statements: perform some action and do not return a value
    // Expression: evaluates to a resultant value

    let a = {
        let nn = 69;
        nn + 1 // Notice there is NOT a ; here, this is an expression and will return the computed value i.e. 70
    };

    println!("Value of a is {a}");

    let a = get_naughty_number();

    println!("Naughty number: {a}");

    let mut num: i32 = 68;
    plus_one(&mut num);

    println!("Incremented: {num}");
}

fn say_hello(name: String) {
    println!("Hello, {name}!");
}

fn primitive_hello(name: &str) {
    println!("Primitive hello, {name}");
}

fn get_naughty_number() -> i32 { 69 }

fn plus_one(target: &mut i32) {
    *target = *target + 1;
}

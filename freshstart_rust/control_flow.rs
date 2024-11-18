use std::io;

fn main() {
    let nums: [i32; 2] = [69, 42];

    let mut num = String::new();
    
    // Take input
    print!("Enter num> ");
    io::Write::flush(&mut io::stdout()).expect("Couldn't flush.");

    io::stdin().read_line(&mut num).expect("Couldn't read.");

    // Convert to i32
    let num: i32 = match num.trim().parse() {
        Ok(t) => t, Err(_) => {
            println!("Invalid. Number");
            return;
        }
    };
    
    // |&i| i == num is a closure (anonymous function) that takes reference
    // to each element and performs the comparision.
    if nums.iter().any(|&i| i == num) {
        println!("Naughty number!");
    } else {
        println!("Not a naughty number");
    }

    let condition: bool = true;
    // Both must have the same type
    let conditional_var: i32 = if condition {69} else {42};

    println!("{conditional_var}");

    let mut counter: i32 = 0;

    loop {
        counter += 1;
        println!("[{counter}] In infinite loop.");

        if counter >= 2 { break; }
    }

    while counter != 4 {
        println!("[{counter}] In while loop");
        counter += 1;
    }

    for element in nums {
        println!("Element of nums: {element}");
    }
    
    // equivalent to: for (int i = 3; i > 0; i--) {...}
    for number in (1..4).rev() {
        println!("{number}");
    }
}

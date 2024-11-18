use std::cmp::Ordering; // Ordering type is an enum that we'll use in the match expression
use std::io;
use rand::Rng;

fn main() {
    // a ..= b means range from a to b both inclusive, ..= is the right-inclusive range litreal
    let secret_number = rand::thread_rng().gen_range(1..=100);

    // println! and print! are macros and NOT functions
    println!("Guess Number!"); // Automatically flushes the output buffer

    // loop keyword creates an infinite loop
    loop {
        print!("Enter your guess> "); // Does not automatically flashes the output buffer

        // The OS writes all the output to an output buffer in memory as it is faster to write
        // in memory as opposed to a device (such as a console). When we "flush" the output
        // buffer, we are essentially telling the OS that clear this buffer and write all the
        // contents to the device (in our case the console i.e. standard output).
        
        // In case of Rust, this buffer is managed by rust itself (the standard library) which
        // in turn might be managed through OS buffers (by the OS).
        
        // We manually have to flush the output buffer, we pass a mutable reference to stdout
        io::Write::flush(&mut io::stdout()).expect("Failed to flush");
        
        // ALTERNATE WAY (equivalent to above, flush here still belongs to
        // io::Write and is NOT an attribute of stdout)
        // use std::io::{self, Write};
        // io::stdout().flush().expect("Failed to flush");

        // Variables are immutable by default in Rust
        let mut guess = String::new(); // Returns an instance of String

        // If successful, there will be Ok variant of Result enum and expect will return the number
        // that we want from the Ok value. Err variant of Result contains the error value
        
        // Similar to scanf("%s", &buffer); std::getline(std::cin, buffer);
        io::stdin() // read_line returns a variant of Result enum
            .read_line(&mut guess) // read a line from the standard input and append it to guess
            .expect("Failed to read line.");

        // Shodwing the value of guess, basically reuse the variable name guess instead of creating
        // two unqiue variables like guess and guess_str, here we are converting the input string
        // to a number, u32 is unsigned 32 bit integer.

        // parse method returns a variant of Result (which is an enum)
        // let guess: u32 = guess.trim().parse().expect("Input was not a number.");
        
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num, Err(_) => {
                println!("Please enter a valid number!");
                continue;
            },
        };

        println!("You guessed: {}", guess);
        
        // This is a match expression and each element in {} is an arm of the match expression
        // the cmp method can be called on anything that can be compared, returns a variant of
        // the Ordering enum and we are handling each case in the respective arms of the expression.
        match guess.cmp(&secret_number) {
            Ordering::Less    => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal   => {
                println!("You win!");
                break;
            },
        }
    }
}

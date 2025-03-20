use std::cmp::Ordering;
use std::io;
use rand::Rng;

fn main() {
  let secret_number: u32 = rand::thread_rng().gen_range(1..=100);
  println!("Guess the number!");

  loop {
    print!("Enter your guess> ");
    io::Write::flush(&mut io::stdout()).expect("Failed to flush");

    let mut guess = String::new();
    io::stdin().read_line(&mut guess).expect("Failed to read line");

    let guess: u32 = match guess.trim().parse<u32>() {
      Ok(num) => num,
      Err(_) => {
        println!("Please enter a valid number");
        continue;
      },
    };

    println!("You guessed: {}", guess);
    match guess.cmp(&secret_number) {
      Ordering::Less => println!("Too small!"),
      Ordering::Greater => println!("Too big!"),
      Ordering::Equal => {
        println!("You win!");
        break;
      },
    }
  }
}
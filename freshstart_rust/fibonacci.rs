use std::io;

fn main() {
    let mut n = String::new();

    print!("Enter number of terms for fibonacci> ");
    io::Write::flush(&mut io::stdout()).expect("Couldn't flush");

    io::stdin().read_line(&mut n).expect("Couldn't read");

    match n.trim().parse::<u32>() {
        Ok(t) => {
            for i in 0..t {
                let result: u32 = fibonacci(i);
                print!("{result} ");
            }
        },
        Err(_) => {
            println!("Invalid input. Exiting ...");
            return;
        }
    }
}

fn fibonacci(n: u32) -> u32 {
    if (n == 0) || (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

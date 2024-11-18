use std::io;

fn get_float_input(prompt: &str) -> f64 {
    let mut result = String::new();

    print!("{prompt}");
    io::Write::flush(&mut io::stdout()).expect("Couldn't flush");

    io::stdin().read_line(&mut result).expect("Couldn't read");

    let result: f64 = result.trim().parse().expect("Invalid input.");
    return result;
}

fn main() {

    println!("Choose conversion:\n1)C -> F\n2) F -> C\n3) Quit");

    loop {
        let mut choice = String::new();
        // Take input
        print!("Enter choice> ");
        io::Write::flush(&mut io::stdout()).expect("Couldn't flush");

        io::stdin().read_line(&mut choice).expect("Couldn't read");

        let choice: u32 = match choice.trim().parse() {
            Ok(t) => t, Err(_) => {
                println!("Invalid choice.");
                continue;
            }
        };

        match choice {
            1 => {
                let target: f64 = get_float_input("Temp in C> ");
                let result: f64 = cel_to_fah(&target);
                println!("{result} F");
                continue;
            },
            2 => {
                let target: f64 = get_float_input("Temp in F> ");
                let result: f64 = fah_to_cel(&target);
                println!("{result} C");
            },
            3 => { break; },
            _ => { continue; },
        };
    }
}

fn cel_to_fah(cel: &f64) -> f64 { (9.0/5.0)*cel + 32.0 }
fn fah_to_cel(fah: &f64) -> f64 { (5.0/9.0)*(fah - 32.0) }

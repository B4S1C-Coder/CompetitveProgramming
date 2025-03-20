use std::env;
use std::process;

use minigrep::Config;

fn main() {
    // Command line args, args[0] is the executable name itself
    let args: Vec<String> = env::args().collect();
    
    let config = Config::build(&args).unwrap_or_else(|err| {
        println!("Error pasing args: {err}");
        process::exit(1);
    });

    println!("Searching for '{}' in {}", config.query, config.file_path);

    // Read the contents
    if let Err(e) = minigrep::run(config) {
        println!("Application error: {e}");
        process::exit(1);
    }
}


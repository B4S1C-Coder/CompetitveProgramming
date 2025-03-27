use std::env;
use std::process;

use minigrep::Config;

fn main() {
    // We use the env::args() iterator directly, we give the ownership of env::args() to config
    let config = Config::build(env::args()).unwrap_or_else(|err| {
        eprintln!("Error pasing args: {err}");
        process::exit(1);
    });

    // Read the contents
    if let Err(e) = minigrep::run(config) {
        eprintln!("Application error: {e}");
        process::exit(1);
    }
}


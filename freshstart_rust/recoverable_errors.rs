use std::fs::File;
use std::io::ErrorKind;

fn main() {
    let file_result: Result<File, std::io::Error> = File::open("test.txt");
    // Err(ref err) has been used to prevent the change of ownership.
    // OR we could use &file_result.
    // the ownership of std::io::Error part of file_result changed here
    if let Err(err) = &file_result {
        //  now err owns the std::io::Error part of file_result
        match err.kind() {
            ErrorKind::NotFound => println!("File not found."),
            other_error => println!("Error: {:?}", other_error)
        }
    }

    // now we go out of scope so the std::io::Error part of file_result is now
    // destroyed / no longer valid. This causes problems with the match expression
    // below which checks for the std::io::Error part of file_result, but it no
    // longer exists.
    
    // Each arm of match must return the same type
    let _file = match file_result {
        Ok(file) => file,
        Err(err) => match err.kind() {
            ErrorKind::NotFound => match File::create("test.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("File creation failed: {:?}", e)
            },
            other_error => panic!("Error: {:?}", other_error)
        },
    };

    // much cleaner code that does the same thing:

    let _file = File::open("test2.txt").unwrap_or_else(|error| {
        if error.kind() == ErrorKind::NotFound {
            File::create("test2.txt").unwrap_or_else(|error| {
                panic!("File creation failed: {:?}", error);
            })
        } else {
            panic!("Error: {:?}", error);
        }
    });

    // unwrap will return value inside Ok and if Result is Err will call panic!
    let _file = File::open("test.txt").unwrap();

    // (preferred) expect lets us choose the panic message
    let _file = File::open("test2.txt").expect("Failed to open file");
}

// Propagating the errors, let the code calling the function handle the error
fn some_operation() -> Result<String, std::io::Error> {
    let file_result = File::open("test69.txt");

    let mut file = match file_result {
        Ok(file) => file,
        Err(e) => return Err(e), // Returned the std::io::Error variant
    };

    let mut username = String::new();

    match file.read_to_string(&mut username) {
        Ok(_) => Ok(username), // Returned the String variant
        Err(e) => Err(e)       // Returned the std::io::Error variant
    }
}

// This function can be written in a much cleaner way via the ? operator
// ? means that file will contain the Ok value if all goes well, otherwise
// the Err value would be returned by the entire function. The wokring is
// similar to as above.
fn cleaner_some_op() -> Result<String, std::io::Error> {
    let mut file = File::open("test69.txt")?;
    let mut username = String::new();
    file.read_to_string(&mut username)?;
    Ok(username)
}

// Can be made even shorter
fn more_cleaner() -> Result<String, std::io::Error> {
    let mut username = String::new();
    File::open("test69.txt")?.read_to_string(&mut username)?;
    Ok(username)
}

// Even shorter lol
fn lol() -> Result<String, std::io::Error> {
    std::fs::read_to_string("test69.txt")
}

// ? can be used on Result<T, E> (T, Error) and Option<T> (T, None)
// ? attempts to convert the error value to the return type of the function
// therefore the function must have Result, Option or a type that implements FromResidual trait
// as the return type. We can even use it in main() as:
//                          any kind of error
//fn main() -> Result<(), Box<dyn std::error::Error>> {
//    let _file = File::open("test69.txt")?;
//    Ok(())
//}
//
//main function can return any type that implements the std::process::Termination trait

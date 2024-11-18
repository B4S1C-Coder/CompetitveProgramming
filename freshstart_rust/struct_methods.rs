use std::io;

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32
}

// In impl block Seldf is alias for the type the impl block is for.
// Methods always have self (alias for self: &Self) as the first parameter
// and can only operate on the type (represented by Self).
// Associated functions do not require an instance to operate on
impl Rectangle {
    fn area(&self) -> u32 { // method
        self.width * self.height
    }

    fn perimeter(&self) -> u32 { // method
        2 * (self.width + self.height)
    }

    fn square(size: u32) -> Self { // associated function
        Self {width: size, height: size}
    }
}

fn main() {

    let mut width = String::new();
    let mut height = String::new();

    print!("Enter width> ");
    io::Write::flush(&mut io::stdout()).expect("No flush");
    io::stdin().read_line(&mut width).expect("No read");

    print!("Enter height> ");
    io::Write::flush(&mut io::stdout()).expect("No flush");
    io::stdin().read_line(&mut height).expect("No read");

    let width: u32 = match width.trim().parse::<u32>() {
        Ok(t) => t, Err(_) => {return;}
    };

    let height: u32 = match height.trim().parse::<u32>() {
        Ok(t) => t, Err(_) => {return;}
    };

    let my_rect = Rectangle {width, height};

    println!("Area: {}, Perimeter: {}", my_rect.area(), my_rect.perimeter());

    let _my_square = Rectangle::square(69);
}

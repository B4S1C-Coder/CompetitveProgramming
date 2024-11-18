use crate::garden::vegetables::Asparagus;

// The compiler will look for code in the following locations
// 1) src/garden.rs
// 2) src/garden/mod.rs

// So instead of creating a garden.rs file in src, we could have
// also created a mod.rs file in the src/garden/ directory
pub mod garden; // include the code in src/garden.rs

fn main() {
    let plant = Asparagus {};
    println!("growing {plant:?}");
}

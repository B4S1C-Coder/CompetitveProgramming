// EXTRACTING A FUNCTION
// If this function did not exist, we'd have to duplicate this code whenever we
// had to find the largest element in an array. But by extracting this code to
// a function we avoided code duplication.

fn largest_i32(list: &[i32]) -> &i32 {
    let mut largest: &i32 = &list[0];

    for element in list {
        if element > largest {
            largest = element;
        }
    }

    largest
}

fn largest_char(list: &[char]) -> &char {
    let mut largest: &char = &list[0];

    for element in list {
        if element > largest {
            largest = element;
        }
    }

    largest
}

// We can further reduce duplication via generic types
// PartialOrd is a trait. We need this because the comparision operation
// i.e. ">" cannot be performed on all possible types, it can only be performed
// on types which implement the PartialOrd trait. Standard library implements the
// said trait on both i32 and char

fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> &T {
    let mut largest: &T = &list[0];

    for element in list {
        if element > largest {
            largest = element;
        }
    }

    largest
}

// In structs (similarly for enums)
struct Part<T> { x: T, y: T } // x and y MUST be of same type
struct Point<T, U> { x: T, y: U } // x, y can be of same or different types

impl<T: std::fmt::Display> Part<T> {
    fn display(&self) -> (&T, &T) {
        println!("Part({} {})", &self.x, &self.y);
        (&self.x, &self.y)
    }
}

// Method restricted to Part<f64>
impl Part<f64> {
    fn magnitude(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

impl<T: std::fmt::Display, U: std::fmt::Display> Point<T, U> {
    fn display(&self) -> (&T, &U) {
        println!("Point({} {})", &self.x, &self.y);
        (&self.x, &self.y)
    }

    fn mix<L, M>(self, other: Point<L, M>) -> Point<T, M> {
        Point { x: self.x, y: other.y }
    }
}

fn main() {
    let lst1 = [69, -69, 96, 34];
    let lst2 = ['a', 'b', 'c', 'd'];

    println!("{}, {}", largest_i32(&lst1), largest_char(&lst2));
    println!("{}, {}", largest(&lst1), largest(&lst2));

    let part: Part<i32> = Part { x: 34, y: 56 };
    let part2 = Part { x: 45.67,  y: 43.23 };
    let point: Point<i32, f64> = Point { x: 69, y: 42.69 };
    let point2 = Point { x: 32, y: 'x' };

    let mixed = point.mix(point2); // point, point2 ownership moved, no longer valid

    mixed.display();
    part.display();

    println!("{}", part2.magnitude());
}

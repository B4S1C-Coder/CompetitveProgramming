// Lifetimes are another kind of generic that ensure the references are valid as long as
// they need to be. Usually the lifetimes are implicit and inferred, but we need to
// annotate them whenever lifetimes of references can be related in a few different ways.

// ############################################################

// Without the lifetime annotations the code won't compile. The help text in the error states:
// this function's return type contains a borrowed value, but the signature does not say whether
// it is borrowed from `x` or `y`

// It basically states that the we don't know for sure whether the reference we return is of x
// or is of y, we also don't know the relationship between the lifetimes of x and y, so we can't
// guranttee whether the returned reference would remain valid for the required duration or not.

// By adding the lifetime paramters we define this relationship and allow the borrow checker to
// perform it's analysis.

// Lifetime annotations don't change how long any of the references lives. Rather, they define the
// relationships of lifetimes of different references with eachother without affecting the
// lifetimes.

// This signature with lifetime paramters tells Rust that the returned reference is valid as long
// as both the parameters are valid.
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    let result = longest("abcd", "xyzpqrs");
    println!("Longest is: {}", result);

    let phrase = String::from("I am not a King. I am not a God. I am worse.");

    // String.split(delimeter) returns an iterator which contains elements separated
    // by delimeter.

    let parts = phrase.split('.');

    for part in parts {
        println!("part ---> {}", part);
    }

    // The iterator maintains an internal cursor, essentially at which postion (or on
    // which element) the iterator is currently on.
    
    // Iterator.next returns the value at the current position of the internal cursor
    // and advances the internal cursor to the next position. The returned value is
    // wrapped in Some of and Option<> since, when the cursor is at the last element,
    // there is no next element so next() will return None of Option<>.

    // Hence this returns the first sentence of phrase.
    let sentence = phrase.split('.').next().unwrap();

    let i = ImportantExcerpt {
        part: sentence
    };

    println!("{}", i);

    static_demo();

    println!("{}", i.level());
    // Means, "Sundar ladki tum un gore ladkon ka kya karogi, un gore gore ladkon ka kya karogi."
    i.bolkar_wapis_kardo("Billo bagge bileya da ki karegi, bagge bagge bileya di ki karegi.");
    
    let p1 = "Daddy ji de cash ute kari jave aish sada bapu zimidar kitho laike daive car.";
    let p2 = "Devil'an de naal na tu khed nakhro, vardaat hundi da pata ni lagnaa.";

    let longest2 = longest_with_announcement(p1, p2, i);
    println!("Result: {}", longest2);
}

fn static_demo() {
    // Will remain valid throughout the scope of the program.
    // Text here is stored in the program's binary and so is always available (not neccesarily
    // accessible outside it's scope). All string literals have this reference
    let _s: &'static str = "I am inevitable.";
}

// Structs can also hold references, but we will need to specify the lifetime parameters.
struct ImportantExcerpt<'a> { part: &'a str }

impl std::fmt::Display for ImportantExcerpt<'_> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "ImportantExcerpt({})", self.part)
    }
}

// Lifetime names for struct fields are always declared after impl and then used after the
// struct's name as those lifetimes are part of the struct's type.

impl<'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 { 69 }

    // example where 3rd lifetime elision rule applies
    fn bolkar_wapis_kardo(&self, samachar: &str) -> &str {
        println!("Yaatrigan krpya dhyaan dijiye: {}", samachar);
        self.part
    }
}

// Lifetime Elision Rules
// These are patterns and rules built into the rust compiler that allow it
// to infer the lifetime parameters in common situations and environments.

// Lifetimes on function or method parameters are called Input Lifetimes and
// those on return types are known as Output Lifetimes.

// The following rules are used by the compiler. These apply to fn and impl blocks

// RULE - 1 --> Compiler assigns a lifetime parameter to each parameter that's a reference.
// RULE - 2 --> If there is exactly one input lifetime paramter then that lifetime is
// assigned to all the output lifetimes.
// RULE - 3 --> If there are multiple input lifetime parameters, but one of them is
// &self or &mut self because this is a method, the lifetime of self is assigned to all
// output lifetime parameters.

// Example with everything
fn longest_with_announcement<'a, T>(
    x: &'a str, y: &'a str, ann: T
) -> &'a str
where
    T: std::fmt::Display
{
    println!("Announcement: {}", ann);
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

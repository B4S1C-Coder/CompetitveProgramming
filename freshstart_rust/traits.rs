// Traits define the functionality a particular type has and can share with other types.
// They can be used to define shared behaviour in an abstract way. It can be used to
// specify that a generic type is any type that has a certain behaviour.

// Traits are similar to interfaces in some languages (with some differences).

// A type's behaviour consists of the methods that can be called on that type.
// Trait definitions are a way to group method signatures together to define a set of
// behaviours necessary to accomplish some purpose.

// We only provide the signatures. The compiler enforces that each type that implements
// the Summary trait will implement the methods in the trait i.e. summarize & some_method.
// But we can provide default implementations if needed.
pub trait Summary {
    fn summarize(&self) -> String;
    fn some_method(string: &str) -> String;
    fn default_method() {
        println!("This is the default implementation.");
    }
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
    fn some_method(string: &str) -> String { String::from(string) }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
    fn some_method(string: &str) -> String { String::from(string) }
    fn default_method() { println!("Custom implementation."); }
}

// TRAITS AS PARAMETERS
// Function that accepts (reference since &) any type that implements the Summary trait.
pub fn notify(item1: &impl Summary, item2: &impl Summary) {
    println!("ALERT!\n-----\n{}\n-----\n{}\n-----", item1.summarize(), item2.summarize());
}

// Above is equivalent to: (Only T would mean both item should have same type)
pub fn notify_verbose<T: Summary, U: Summary>(item1: &T, item2: &U) {
    println!("ALERT!\n-----\n{}\n-----\n{}\n-----", item1.summarize(), item2.summarize());
}

// Specifying mupltiple Traits

pub fn some_func<T: std::fmt::Display + std::cmp::PartialOrd, U: Summary + std::fmt::Display>(
    _param1: &T, _param2: &U) -> i32 { 69 }

// The above signature is hard to read. We can write the equivalent signature via where clause
pub fn some_o_func<T, U>(_param1: &T, _param2: &U) -> i32
where
    T: std::fmt::Display + std::cmp::PartialOrd,
    U: Summary + std::fmt::Display
{ 69 }
// This is much easier to read
// Return a type that implements Summary trait (below won't work).
// Working example would be covered in future files.
/*
pub fn random_inst(axis: bool) -> impl Summary {
    if axis {
        NewsArticle {
            headline: String::from("some title"),
            location: String::from("some loc"),
            author: String::from("some author"),
            content: String::from("some content")
        }
    } else {
        Tweet {
            username: String::from("some_user"),
            content: String::from("some content"),
            reply: false,
            retweet: true
        }
    }
}
*/

// The conditional things we did in generics can be done with the traits as well
// with similar / same syntax.

pub struct Pair<T> { x: T, y: T }
// No condition, applicable for all, Self is alias for Pair<T>
impl<T> Pair<T> {
    pub fn new(x: T, y: T) -> Self {
        Self { x,y }
    }
}

// Only applicable for Pair<T> where inner type T implements PartialOrd and Display
impl<T: std::fmt::Display + std::cmp::PartialOrd> Pair<T> {
    pub fn cmp_display(&self) {
        if self.x >= self.y {
            println!("The largest member is x = {}", self.x);
        } else {
            println!("The largest member is y = {}", self.y);
        }
    }
}

fn main() {
    let news = NewsArticle {
        headline: String::from("some title"),
        location: String::from("some loc"),
        author: String::from("some author"),
        content: String::from("some content")
    };

    println!("{}", news.summarize());
    
    println!("{}", NewsArticle::some_method("damn!"));
    
    let tweet = Tweet {
        username: String::from("some_user"),
        content: String::from("some content"),
        reply: false,
        retweet: true
    };

    println!("{}", tweet.summarize());
    println!("{}", Tweet::some_method("damn again!"));

    NewsArticle::default_method();
    Tweet::default_method();

    notify(&tweet, &news);
    notify_verbose(&news, &tweet);
}

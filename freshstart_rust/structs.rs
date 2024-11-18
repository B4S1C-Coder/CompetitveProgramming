struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

// Rust also supports tuple structs, useful when you want to give a name to a particular
// tuple but naming each field would be redundant or verbose

#[derive(Debug)]
struct Point(i32, i32, i32); // Represents point in 3D space (x, y, z)

// Rust also supports unit like structs which behave similar to ()
// they are useful when we are implementing traits and don't have any data

struct GoToSleep;

fn main() {
    let mut user1: User = User {
        username: String::from("user1"),
        email: String::from("usr1@email.com"),
        active: true,
        sign_in_count: 69,
    };

    let pt = Point(69, 42, -69);
    println!("pt is {pt:?}"); // possible because of #[derive(Debug)] above Point
    println!("( {} {} {} )", pt.0, pt.1, pt.2);

    let _command = GoToSleep;

    // We can access and modify the struct's field as follows:
    // print_user(&user1);

    // In order to modify, the entire instance of the struct must be mutable,
    // you CANNOT mark only a particular field as mutable
    user1.email = String::from("usr1_new@email.com");
    // print_user(&user1);

    let user2: User = build_user("user2", "usr2@email.com");
    // print_user(&user2);

    let user1_duplicate: User = build_user_with_short_hand(user1.username, user1.email);
    // print_user(&user1_duplicate);

    let user1_another_dup = User {
        username: String::from("Another duplicate of user1"),
        ..user1_duplicate // Rest of the fields (not explicitly defined like above) set by user1
    };

    print_user(&user1_another_dup);
}

fn print_user(user: &User) {
    println!("=====\n{}\n{}\n{}\n{}\n=====\n",
        user.username, user.email, user.sign_in_count, user.active);
}

fn build_user(username: &str, email: &str) -> User {
    User {
        username: username.to_string(),
        email: email.to_string(),
        sign_in_count: 1,
        active: true
    }
}

fn build_user_with_short_hand(username: String, email: String) -> User {
    User {
        username,
        email,
        sign_in_count: 1,
        active: true
    }
}

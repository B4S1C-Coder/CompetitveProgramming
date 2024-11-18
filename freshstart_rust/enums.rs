#[derive(Debug)]
enum IpAddrKind {
    V4,
    V6
}

// Variants can have values associated with them
enum newIpKind {
    V4(u8, u8, u8, u8),
    V6(String)
}

#[derive(Debug)]
struct IpAddr {
    kind: IpAddrKind,
    address: String
}

// Advantage of using enums over unit structs
enum Message {
    Quit,
    Move {x: i32, y: i32},
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn display_info(&self) {
        println!("impl blocks also applicable for enums!");
    }
}

// The above is equivalent to
struct QuitMessage; // unit struct
struct MoveMessage {
    x: i32, y: i32
}
struct WriteMessage(String); // tuple struct
struct ChangeColorMessage(i32, i32, i32); // tuple struct

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1)
    }
}

fn main() {
    let _four = IpAddrKind::V4;
    let _four = newIpKind::V4(127, 0, 0, 1);
    let _sixs = newIpKind::V6(String::from("::1"));

    let df = Some(68);
    let df = plus_one(df);

    let home = IpAddr {
        kind: IpAddrKind::V4,
        address: String::from("127.0.0.1")
    };

    let loopback = IpAddr {
        kind: IpAddrKind::V6,
        address: String::from("::1")
    };

    println!("home = {home:#?}");
    println!("loopback = {loopback:#?}");

    // if let allows you to handle values that match one pattern while ignoring the rest
    let config_max = Some(3u8);
    match config_max {
        Some(max) => println!("{max} is max."),
        _ => (), // All other cases
    };

    // The above with if let
    if let Some(max) = config_max {
        println!("{max} is max.");
    }

}

#[derive(Debug)]
enum Data {
    Int(i32), Float(f64), Text(String)
}

fn main() {
    // let v: Vec<i32> = Vec::new();
    let mut v = vec![69, 42, -32];

    v.push(6);

    let third: &i32 = &v[2]; // immutable reference to third element
    println!("Third element ---> {}", third);

    let third: Option<&i32> = v.get(2); // third element
    match third {
        Some(third) => println!("Third element ---> {}", third),
        None => println!("No third element.")
    }

    for i in &mut v {
        *i *= 100;
    }

    for i in &v {
        println!("{}", i);
    }

    let some_data: Vec<Data> = vec![
        Data::Int(69), Data::Float(45.43), Data::Text(String::from("Hello"))
    ];

    println!("{:?}", &some_data[1]);

}

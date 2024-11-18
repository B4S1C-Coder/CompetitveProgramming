// Module tree for this crate
// crate
//  └── front_of_house
//      ├── hosting
//      │   ├── add_to_waitlist
//      │   └── seat_at_table
//      └── serving
//          ├── take_order
//          ├── serve_order
//          └── take_payment


mod front_of_house {
    pub mod hosting {
        pub fn add_to_waiting_list() {}
        pub fn seat_at_table() {}
    }

    pub mod serving {
        pub fn take_order() {}
        fn serve_order() {} // not accessible outside
        fn take_payment() {} // not accessible outside
    }

    pub struct Food { // accessible outside
        pub name: String, // accessible outside
        price: u32, // not accessible outside
    }

    pub enum Appetizer { // accessible outside & all variants also accessible outside
        Soup,
        Salad
    }
}

pub fn eat_at_restaurant() {
    // Absolute path
    crate::front_of_house::hosting::add_to_waiting_list();

    // Relative path
    front_of_house::hosting::add_to_waiting_list();
}

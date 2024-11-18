pub fn add(left: u64, right: u64) -> u64 {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test] // This attribute indicates that this is a testing function
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4); // Asserts that result of add(2, 2) is 4
    }

    #[test]
    fn will_fail() {
        panic!("You shall NOT PASS!");
    }
}

use adder::add;

#[test]
fn integration_add_test() {
    let result = add(2, 2);
    assert_eq!(result, 4);
}

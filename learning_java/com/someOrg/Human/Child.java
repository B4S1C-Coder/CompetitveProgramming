package com.someOrg.Human;

public class Child extends Parent {

    public Child() {
        // super gives you access to the parent class and its methods
        super(69); // constructor of parent class

        // usually java would have automatically called super()
        // when instantiating child instance, but the parent has a custom
        // constructor as a result of which Java cannot directly call super()

        // and we have to call it explicity.
        // also super() [constructor of parent] can only be the first statement
        // this is obvious as before setting the child the parent needs to be
        // set up first.
        System.out.println("Child constructor called");
    }
    
    public void childSpecificMethod() {
        super.parentSpecificMethod();
        System.out.println(super.getAge());
        System.out.println("Child specific method called");
        System.out.println(super.getName());
    }
}

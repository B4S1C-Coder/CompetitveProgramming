package com.someOrg;

public class organizationalException extends Exception {
    public organizationalException() {
        super("Organization has failed.");
    }

    public organizationalException(String s) {
        super(s);
    }
}

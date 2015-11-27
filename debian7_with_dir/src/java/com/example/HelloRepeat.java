package com.example;

class HelloRepeat {
    private native int helloRepeat(String name, int times);

    static{ System.loadLibrary("HelloRepeatJni"); }

    public static void main(String[] args) {
	(new HelloRepeat()).helloRepeat(args[0], Integer.parseInt(args[1]));
    }
}

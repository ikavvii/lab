void main() {  // java compact source file - implicitly declared class
    int myInteger = Integer.MAX_VALUE;
    System.out.println(myInteger);
    System.out.println(myInteger+1); // wraps around

    myInteger = Integer.MIN_VALUE;
    System.out.println(myInteger);
    System.out.println(myInteger-1);

    byte myByte = Byte.MAX_VALUE;
    System.out.println(myByte);
    System.out.println(myByte+2);

    myByte = (byte) (myByte + 2); // overflow
    System.out.println(myByte);

    myByte = Byte.MIN_VALUE;
    System.out.println(myByte);

    short myShort = Short.MAX_VALUE;
    System.out.println(myShort);
    System.out.println(myShort + 1); // numeric promotion - no overflow
    System.out.println(Short.MIN_VALUE);

    long myLong = Long.MAX_VALUE;
    System.out.println(myLong);
    System.out.println(myLong + 1);  // overflow

    myLong = Long.MIN_VALUE;
    System.out.println(myLong);
    System.out.println(myLong - 1); // underflow

    // float overflow and underflow
    float myFloat = Float.MAX_VALUE;
    System.out.println(myFloat);
    System.out.println(myFloat + 1);
    System.out.println(myFloat + 1.0);

    myFloat = Float.MIN_VALUE;
    System.out.println(myFloat);
    System.out.println(myFloat - 1.0);
    System.out.println(myFloat - 1);

    double myDouble = Double.MAX_VALUE;
    System.out.println(myDouble);

    // overflow using multiplication table
    // TODO

    char myChar = Character.MAX_VALUE;
    System.out.println(myChar);
    System.out.println((int ) myChar);
    System.out.println(myChar + 1); // no overflow
    myChar = (char) (myChar + 1); // putting back the char into variable after overflow
    System.out.println((int) myChar); // printing numeric value


}

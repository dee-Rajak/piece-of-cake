package classes_and_objects;

/**
 * Sample1
 */
class Sample1 {

    int a, b, c;

    //initialization - block 1
    {
        System.out.println("Initialization-block 1 is executed, setting (a=10).");
        a = 10;
    }
    //initialization - block 2
    {
        System.out.println("Initialization-block 2 is executed, setting (b=20).");
        b = 20;
    }

    //user-defined parameterless constructor
    Sample1(){
        System.out.println("User-defined parameter less constructor is executed, setting (c=60).");
        c = 60;
    }

}

/**
 * InitializationBlock
 */
public class InitializationBlock {

    public static void main(String[] args) {
        System.out.println("Learning initialization-block to yk what i mean.");
        Sample1 obj = new Sample1();
        System.out.println("Instance field, a = " + obj.a);
        System.out.println("Instance field, b = " + obj.b);
        System.out.println("Instance field, c = " + obj.c);
    }    
}
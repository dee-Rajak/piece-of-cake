package classes_and_objects;

/**
 Sample
 */
class Sample {

    //public field
    public int pubInt = 5;
    //private field
    private int priInt = 10;

        //getter-setter for priInt
        public int getPriInt() {
            return priInt;
        }
        public void setPriInt(int priInt) {
            this.priInt = priInt;
        }

    //public method
    public void showPublicMethod() {
        System.out.println("The showPublicMethod() is a public method.");
    }
    //private method
    // private void showPriivateMethod() {
        // System.out.println("The showPrivateMethod() is a private method.");
    // }
}

/**
 * LearnPublicPrivate
 */
public class LearnPublicPrivate {

    public static void main(String[] args) {
        System.out.println("Learning access control using public and private modifier.");
        //create obj for public field and method
        Sample objA = new Sample();
        System.out.println("Priinting public field : " + objA.pubInt);
        objA.showPublicMethod();

        //create obj for private field and method
        // Sample objB = new Sample();
        // System.out.println("Printing private field : " + objB.priInt);
        // objB.showPrivateMethod();

        /*
            Compile-time error for previous two statements
        */
            Sample objB = new Sample();
            System.out.println("Printing private field : " + objB.getPriInt());
            objB.setPriInt(45);
            System.out.println("Printing private field after using setter: " + objB.getPriInt());
    }
}
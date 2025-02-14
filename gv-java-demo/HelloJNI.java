public class HelloJNI {

    public native void hello();

    public static void main(String[] args) {
        System.loadLibrary("hellojni");

        HelloJNI hello = new HelloJNI();
        hello.hello();
    }
}
interface resizeable{
    int resizewidth();
    int resizeheight();

}
class rectangle implements resizeable{
    @Override
    public int resizewidth() {
        return 8;
    }
    @Override
    public int resizeheight() {
        return 9;
    }
}
public class demo2 {
    public static void main(String[] args) {
        rectangle r1=new rectangle();
        System.out.println("The resize height of rectangle is "+ r1.resizeheight());
        System.out.println("The resize width of rectangle is "+ r1.resizewidth());
    }
}
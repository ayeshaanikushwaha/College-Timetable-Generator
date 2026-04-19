public class constructerDemo {
    public static void main(String[] args) {
        Constructer c=new Constructer(5, 7, 2);
        int volume=c.volume();
        System.out.println("Volume is: "+volume);
    }
}
class Constructer{
    int width;
    int height;
    int depth;  
    public Constructer(int width,int height,int depth){
        this.width=width;
        this.height=height;
        this.depth=depth;
    }
    public int volume(){
        return width*height*depth;
    }
}


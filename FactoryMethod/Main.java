import framework.*;
import idcard.*;

public class Main{
    public static void main(String[] args){
        Factory factory = new IDCardFactory();
        Product card1 = factory.create("Jon");
        Product card2 = factory.create("Bob");
        Product card3 = factory.create("Michel");
        card1.use();
        card2.use();
        card3.use();
    }
}

package idcard;
import framework.*;

public class IDCard extends Product{
    private String owner;
    IDCard(String owner){
        System.out.println("creating the " + owner + "'s' card ...");
        this.owner = owner;
    }
    public void use(){
        System.out.println("use the " + owner + "'s' card ...");
    }
    public String getOwner(){
        return owner;
    }
}

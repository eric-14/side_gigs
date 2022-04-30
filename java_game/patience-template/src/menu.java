import java.util.Scanner;
public class menu {
    public void printmenu(){
        System.out.println(
           "card game: \n"
            + "1)Show pack \n"
            + "2)Shuffle cards \n"
            + "3)Deal Card \n"
            + "4)Make move to the previous pile\n"
            + "5)Make move last card onto the pile skipping over 2 piles\n"
            + "6)Amalgate piles in the middle\n"
            + "7)Show all displayed cards\n"
            + "8)Play me for once\n"
            + "9)Show the top top ten results all games so far\n"
            + "10)Quit"
    

        );
    }
    
    public int input(){
        System.out.println("\n Choose a function ");
        Scanner scan = new Scanner(System.in);
        int choice= scan.nextInt();
        scan.close();
        return choice;

    }
   
     
    //main function test the menu
    // public static void main(String []args){
    //     menu menu1 = new menu();
    //     menu1.printmenu();    }
}


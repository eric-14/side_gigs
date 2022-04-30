/**
 * The Game of patience main class
 * @author Faisal Rezwan, Chris Loftus and Lynda Thomas
 * @version 3.0
 */
import java.util.*;
import java.util.ArrayList;
import java.util.Random;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.*;

import javafx.stage.Stage;
import uk.ac.aber.dcs.cs12320.cards.gui.javafx.CardTable;

public class Game extends Application {
    public ArrayList<String> get_deck(){
        //provide the path for the cards

        //array to hold the cards
        ArrayList<String> cardlist = new ArrayList<String>();
        getfile cards = new getfile();
        cardlist = cards.getpath();

        return cardlist;

    }
    static int count= 0;
    public ArrayList<String> card_list = get_deck();
    //card_list = get_deck();



    public static ArrayList<Game> games = new ArrayList<>();
    public ArrayList<String> cards_delt = new ArrayList<String>();
    public Game(){
        this.count = this.count +1;
        games.add(this);
        this.card_list = get_deck();
//        for(int k=0; k < card_list.size();k++){
//            System.out.println("line 41 \t" + card_list.get(k));
//        }

        func3_dealcard(cards_delt);
        func2_shuffle(card_list);
    }

    private CardTable cardTable;
    //array to keep track of the cards delt
    
    //array contains the total number of cards
    public void user_interface(){
        menu menu1 = new menu();
        //function to print user options
        menu1.printmenu();
        //function to get the user data
        int req_func = menu1.input();
        switch (req_func) {
            case 1:
                func_showpack(card_list);
                break;
            case 2:
                System.out.println("Shuffle will not work when the game has started");
                break;
            case 3:
                func3_dealcard(cards_delt);
                break;
            case 4:
                 try {
                    make_move2(cards_delt);
                } catch (WrongPlayException e) {
                    System.out.println("Error message "+ e.getMessage() );
                }
                break;
            case 5:
                try {
                    make_move1(cards_delt);
                } catch (WrongPlayException e) {
                    System.out.println("Error message "+ e.getMessage() );
                }
                
                break;
            case 6:
                func_amal(cards_delt);
                break;
            case 7:
                func_display(cards_delt);
                break;
            case 8:
                play_once(cards_delt);
                break;
            case 9:
                top_ten();
                break;
            case 10:
                quit();
                break;
        
            default:
                break;
        }
    }

    @Override
    public void start(Stage stage) {
        cardTable = new CardTable(stage);
        // The interaction with this game is from a command line
        // menu. We need to create a separate non-GUI thread
        // to run this in. DO NOT REMOVE THIS.


        Runnable commandLineTask = () -> {
            // REPLACE THE FOLLOWING EXAMPLE WITH YOUR CODE
//            ArrayList<String> cardStrings = new ArrayList<>();
//            cardStrings.add("3h.gif");
//            cardStrings.add("tc.gif");


          // cardTable.cardDisplay(cardStrings);
            
            //shuffle the cards randomly

            func2_shuffle(card_list);
            cardTable.cardDisplay(card_list);
            //display the cards on the deck
          //  cardTable.cardDisplay(cards_delt);
        };
       
        Thread commandLineThread = new Thread(commandLineTask);
        // This is how we start the thread.
        // This causes the run method to execute

        commandLineThread.start();
        // System.out.println("line 75 game.getCard()" + card_list.get(0));
        
    }
    
    public void quit(){
        
        Platform.exit();
    }
    public ArrayList<String> getCard(){return card_list;}
    //function to display the cards



    public void func_showpack(ArrayList<String> card_list){
        System.out.println("line 152 show pack "+ card_list.size() + card_list.get(1));

        Platform.runLater(new Runnable(){
            @Override
            public void run() {
                Stage secondaryStage = new Stage();
                CardTable cardTable = new CardTable(secondaryStage);
                System.out.println("libne 151 inside the show pack func "+card_list.size());
                cardTable.cardDisplay(card_list);
            }
        });



    }
    //Shuffling will only occur when the game starts
    private void func2_shuffle(ArrayList<String> cards){
        Collections.shuffle(cards);
    }
    //function to deal a card
    public String func3_dealcard(ArrayList<String> cards_delt){
        //int number_of_card=52;
       // Random rand = new Random();
        // int card = rand.nextInt(number_of_card);
        int card = this.card_list.size()-1;
        String card_ = this.card_list.get(card);

        this.card_list.remove(card);

        cards_delt.add(card_);
        return card_;
    }
    
    public void make_move1(ArrayList<String> card_delt) throws WrongPlayException{
        if(card_delt.size() > 1){
                int last = card_delt.size()-1;
                String last_card = card_delt.get(last);
                String previous_card = card_delt.get(last-1);
                //move if the last_card muches the previous one in number or suit

                if(last_card.charAt(0) == previous_card.charAt(0) ||last_card.charAt(1) == previous_card.charAt(1)){
                    //if true remove the previous card and the last card from their current positions
                    //Then add the last card to the position of the previosu card
                    card_delt.remove(last);
                    card_delt.remove(last-1);
                    
                    card_delt.add(last-1,last_card);
                }
        }else{
             throw new WrongPlayException("Play more hands before this move");
        }
    }
    
    public void make_move2(ArrayList<String> card_delt) throws WrongPlayException{
        
        if(card_delt.size() > 3 ){
                int last = card_delt.size()-1;
                String last_card = card_delt.get(last);
                String previous_card = card_delt.get(last-3);
            if(last_card.charAt(0) == previous_card.charAt(0) ||last_card.charAt(1) == previous_card.charAt(1)){
                 
                 card_delt.remove(last);
                 card_delt.remove(last-3);
                
                 card_delt.add(last-3,last_card);
            }
        }else{
            throw new WrongPlayException("Play more hands before this move");
        }
    }
    
    public void func_amal(ArrayList<String> card_delt){
        int size = card_delt.size();
        
        //iterate the cards delt from the back
        for(int i = size-1;i>0;i--){
            String last_card = card_delt.get(i);
            
            //compare the last card with the previous cards in the deck
            for(int j=size-2;j>0;j--){
                //compare the suit of cards
                String previous_card = card_delt.get(j);
                if(last_card.charAt(1) == previous_card.charAt(1) ){
                    card_delt.remove(i);
                    card_delt.remove(j);
                   

                    //replace the previous card with the last card
                    card_delt.add(j,last_card);
                }
            }
        }

        }
    
    public void func_display(ArrayList<String> card_delt){
        System.out.println(" \t CARDS DELT \t");
        for(int i=0; i < card_delt.size();i++){
            
            System.out.println(card_delt.get(i));
        }
    }
    

    public Boolean isMakemove1(ArrayList<String> card_delt){
           if(card_delt.size() > 1){
                int last = card_delt.size()-1;
                String last_card = card_delt.get(last);
                String previous_card = card_delt.get(last-1);
                //move if the last_card muches the previous one in number or suit

                if(last_card.charAt(0) == previous_card.charAt(0) ||last_card.charAt(1) == previous_card.charAt(1)){
                   return true;
                }
                return false;
            }else{
                return false;
            }
    }
    

    public Boolean isMakemove2(ArrayList<String> card_delt){
         
        if(card_delt.size() > 3 ){
                int last = card_delt.size()-1;
                String last_card = card_delt.get(last);
                String previous_card = card_delt.get(last-3);
            if(last_card.charAt(0) == previous_card.charAt(0) ||last_card.charAt(1) == previous_card.charAt(1)){
                 return true;
            }
            return false;
        }else{
           return false;
        }
    }
    public void play_once(ArrayList<String>card_delt){
        if(isMakemove1(card_delt)==true && isMakemove2(card_delt) == true){
            try {
                make_move2(card_delt);
            } catch (WrongPlayException e) {
                
                System.out.println("Error Message \t" + e.getMessage());
            }
            
        }else{
            try {
                make_move1(card_delt);
            } catch (WrongPlayException e) {
                
                System.out.println("Error Message \t" + e.getMessage());
            }
            
        }
    }

    //for all instances of the game show the size of card_delt
    //create size instance for each class and count to keep record of number of games
    public void top_ten(){
        Hashtable<Integer,Game> top_ten = new Hashtable<>();
        ArrayList<Integer> score =  new ArrayList<>();
        //getting the score of all games
        for(int i=0;i < games.size();i++){
            //number of piles. game with 1 pile is highest value
           int no_piles =  games.get(i).cards_delt.size();
            top_ten.put(no_piles,games.get(i));
        }
        //getting the top scoring games
        TreeMap<Integer, Game> tm
            = new TreeMap<Integer, Game>(top_ten);


        Set<Integer> keys = tm.keySet();
        Iterator<Integer> itr = keys.iterator();
  
        // traverse the TreeMap using iterator
        while (itr.hasNext()) {
            Integer i = itr.next();
            System.out.println(i + " " + tm.get(i));
        }
    }
    
    

    public static void main(String args[]) {
        
        Game game = new Game();
        game.user_interface();
        //game.get_deck();
       // System.out.println("line 333" + game.card_list.size());
        game.func3_dealcard(game.cards_delt);

        game.func3_dealcard(game.cards_delt);

//
//        game.func3_dealcard(game.cards_delt);
//
//        game.func3_dealcard(game.cards_delt);
//
//        game.func3_dealcard(game.cards_delt);
//
//
//        game.func3_dealcard(game.cards_delt);
//
//        game.func3_dealcard(game.cards_delt);
//
//        game.func3_dealcard(game.cards_delt);
//
//        game.func3_dealcard(game.cards_delt);
//
//        game.func3_dealcard(game.cards_delt);
//
//
//        game.func3_dealcard(game.cards_delt);
//        game.func_showpack(game.card_list);
        
        try{
              game.make_move1(game.cards_delt);
              game.make_move2(game.cards_delt);
        }
        catch(WrongPlayException e){
            e.getMessage();
        }
        game.func_display(game.cards_delt);
      
       
       
        //System.out.println("line 101 card delt" + game.func3_dealcard());
        Application.launch(args);
        
    }
}

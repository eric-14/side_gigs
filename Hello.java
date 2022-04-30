import java.io.*;
import java.nio.charset.Charset;
import java.util.Random;
import java.util.*;
import com.opencsv.*;
import java.lang.Integer;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.util.*;
import org.jfree.chart.ChartFactory;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.data.general.Series;
import org.jfree.data.statistics.HistogramDataset;
import org.jfree.chart.ChartFrame;
//import math.commons



class Hello{
    public static void main(String[] args)throws Exception{
    
        FileWriter filewriter = new FileWriter("indext.csv");


        long s = 1597;
        Random randnum = new Random();
        randnum.setSeed(s);

        List<List<String[]>> rec1019 = new ArrayList<List<String[]>>(); 
        //String file_name =  System.getProperty("user.dir") +"\\eric.txt";

        List<String []> rd1 = new ArrayList<String[]> ();
        List<String []> rd0 = new ArrayList<String[]> ();
    

        FileReader file =  new FileReader("assignment2.csv");
        CSVReader assignment2 = new CSVReaderBuilder(file)
                                  .withSkipLines(1)
                                  .build();
                                  
        String[] record;
        
       
        
        while((record= assignment2.readNext()) != null ){
                if(record.length < 6){
                    continue;
                }
                int col_val = Integer.parseInt(record[6]);
                int col_val2 = Integer.parseInt(record[4]);
                if(col_val2 == 1){
                    String tmp[] = {record[3],record[1]};
                    rd1.add(tmp);
                }else if(col_val2 == 0){
                    String tmp[] = {record[3],record[1]};
                    rd0.add(tmp);
                }
                if(col_val >= 2010 && col_val <= 2019  ){
                    List<String[]> row1 = new ArrayList<String[]>();

                   // for(String cell: record){
                    row1.add(record);
                        
                
                    rec1019.add(row1);   
            }
         }
          //  System.out.println("line 51 " + rec1019.size());

            int size_rec1019 = rec1019.size();

            int rand_row =  randnum.nextInt(size_rec1019);

            List<String[]> indext = rec1019.get(rand_row);

            
            
            File indextf = new File("indext.csv");
                
            FileWriter output = new FileWriter(indextf);
            CSVWriter writer = new CSVWriter(output);
    
            writer.writeAll(indext);
          
           writer.close();

           File mydata = new File("mydata.csv"); 
           FileWriter output1 = new FileWriter(mydata);
           CSVWriter writer1 = new CSVWriter(output1);
                
          for(List<String[]> row: rec1019){
            writer1.writeAll(row);  
          }
           

         writer1.close();
           
         System.out.println("Hello World");
              
        

        assignment2.close();
        
        
        // System.out.println( "line 102" + rd1.size() + " " + rd0.size());
        // for(int i=0;i<5 ;i++){
        //     System.out.println( rd1.get(i).toString());
        // }

     
       
       
       DefaultCategoryDataset data1 = new DefaultCategoryDataset();
       DefaultCategoryDataset data2 = new DefaultCategoryDataset();
        
    
        for(String[] row :rd0){
            float value;
            try{
                value = Float.parseFloat(row[0]);
                data1.setValue(value,"price",row[1]);
            }catch(Exception e){e.printStackTrace();}
            
           // data1.setValue(value,"price",row[1]);
            
        }
        
        for(String[] row :rd1){
            float value;
            try{
                value = Float.parseFloat(row[0]);
                data1.setValue(value,"price",row[1]);
            }catch(Exception e){e.printStackTrace();}
        }
            
        
        JFreeChart barchart1  = ChartFactory.createBarChart(
                "Companies with revenue decoupling",
                "companies",
                "electricity price",
                data1
                
        );
      
        JFreeChart barchart2  = ChartFactory.createBarChart(
            "Companies without revenue decoupling",
            "companies",
            "electricity price",
            data2
            );

            CategoryPlot plot1 = barchart1.getCategoryPlot();
            CategoryPlot plot2 = barchart2.getCategoryPlot();
        
            //plot1.setRangeGridlinePaint(Color.black);
            ChartFrame chartf1 = new ChartFrame("CD",barchart1,true);
            ChartFrame chartf2 = new ChartFrame("CD",barchart2,true);
            chartf1.setVisible(true);
            chartf1.setSize(300,200);

            chartf2.setVisible(true);
            chartf2.setSize(300,200);
    }
    public static void regression(List<String []>price,List<String[]> _rdi,List <String []>reptrifectai,List<String []>tot,int bias){
        /*
            I was shot on time debugging this takes time and the time period given was too shot. Otherwise i could have gotten an A.
        */
    }
}

   

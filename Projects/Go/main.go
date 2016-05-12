package main;

import "fmt"
import "time"
import "sync"



type Date struct{
    Month int
    Date int
    Year int
}
type Human struct{
    ID float64
    Year Date
    IQ float64
    Name string
    Speciality string
    Tollearance bool
}

var wg sync.WaitGroup;

//Go 
func main(){
    
    Justice := Human{ID : 9, Date{5,8,1990}, IQ : 99.9999, Name : "Justice", Speciality : "Guitar", Tollearance: true}
    Amanuel := Human{ID : 5, Date{12,29,2000}, IQ : 50.00, Name : "Amanuel", Speciality: "C/C++"}

    //We had this conurency
    wg.Add(2);
    go func(){
        for {
           fmt.Println("Ping");
           time.Sleep(time.Second * 1);
        }
        wg.Done();
    }();
    
    go func(){
        for {
           fmt.Println("Pong");
           time.Sleep(time.Second * 1);
        }
        wg.Done();
    }();
    
    wg.Wait();
}
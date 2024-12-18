#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;
class Bill{
    private:
    string Item;
    int Rate, Quantity;
    public:
    Bill():Item(""), Rate(0), Quantity(0){}
    void setItem(string item){
        Item=item;
    }
    void setRate(int rate){
        Rate=rate;
    }
    void setQuantity(int quantity){
        Quantity=quantity;
    }
    string getItem(){
        return Item;
    }
    int getRate(){
        return Rate;
    }
    int getQuantity(){
        return Quantity;
    }
   
};
void addItem(Bill b){
    bool close=false;
    while(!close){
        int choice;
        cout<<"\t1.Add"<<endl;
        cout<<"\t2.Exit"<<endl;
        cout<<"\tenter choice:"<<endl;
        cin>>choice;
        if(choice==1){
            system("cls");
            string item;
            int rate, quantity;
            cout<<"\tEnter item name:";
            cin>>item;
            b.setItem(item);
             cout<<"\tEnter rate:";
            cin>>rate;
            b.setRate(rate);
             cout<<"\tEnter quantity:";
            cin>>quantity;
            b.setQuantity(quantity);
            ofstream out("D:\\bill.txt", ios::app);
            if(!out){
                cout<<"\tError:file can't be opened!";
                }
                else{
                    out<<"\t"<<b.getItem()<<":"<<b.getRate()<<":"<<b.getQuantity()<<endl<<endl;
                }
                out.close();
                cout<<"\t Item added succesfully"<<endl;
                Sleep(3000);
        }
        else if(choice==2){
            system("cls");
            close=true;
            cout<<"\tBack to main menu!"<<endl;
            Sleep(3000);
        }
    }
}
void printBill(Bill b){
    system("cls");
    int count=0;
    bool close=false;
    while(!close){
        system("cls");
        int choice;
        cout<<"\t1.Add Bill"<<endl;
        cout<<"\t2.Close session."<<endl; 
        cout<<"\tenter choice:";
        cin>>choice;
        if(choice==1){
            string item;
            int quantity;
             cout<<"\tEnter Item:";
             cin>>item;
             cout<<"\tEnter quantity:";
             cin>>quantity;
             ifstream in("D:\\bill.txt");
             ofstream out("D:\\bill Temp.txt");
             string line;
             bool found=false;

             while(getline(in, line)){
                stringstream ss;
                ss<<line;
                string itemName;
                int itemRate, itemQuantity;
                char delimeter;
                ss>>itemName>>delimeter>>itemQuantity>>delimeter>>itemRate;
                if(item==itemName){
                    found=true;
                    if(quantity<=itemQuantity){
                        int amount= itemRate*quantity;
                        cout<<"\tItem Name | Quantity | Rate | Amount"<<endl;
                        cout<<"\t"<<itemName<<"\t"<<quantity<<"\t"<<itemRate<<"\t"<<amount<<endl;
                        int newQuantity=itemQuantity-quantity;
                        itemQuantity=newQuantity;
                        count+=amount;
                        out<<"\t"<<itemName<<":"<<itemRate<<":"<<itemQuantity<<endl<<endl;
                    }
                    else{
                        cout<<"\tSorry,"<<item<<"ended!"<<endl;
                    }
                }
                else{
                    out<<line<<endl;
                }
             }
             if(!found){
                cout<<"\tItem not avaialable"<<endl;
             }
             out.close();
             in.close();
             remove("D:\\bill.txt");
             rename("D:\\bill Temp.txt","D:\\bill.txt");
        }
        else if(choice==2){
            close=true;
            cout<<"\tCounting Bill"<<endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout<<endl;
    cout<<"\tThanks for purchasing,Your Bill---->"<<count<<endl;
    Sleep(3000);
}
 int main(){
        Bill b;
        bool exit=false;

        while(!exit){
            system("cls");
            int val;
            cout<<"\tWelcome to supermarket billing system"<<endl;
            cout<<"\t**************************************"<<endl;
            cout<<"\t\t1.Add Item"<<endl;
            cout<<"\t\t2.Print Bill"<<endl;
            cout<<"\t\t3.exit"<<endl;
            cout<<"\t\tenter choice:";
            cin>>val;
            if(val==1){
                system("cls");
                addItem(b);
                Sleep(3000);
            }
            else if(val==2){
                printBill(b);
            }
            else if(val==3){
                system("cls");
                exit=true;
                cout<<"\tGood luck!"<<endl;
                Sleep(3000);
            }
        }
    }
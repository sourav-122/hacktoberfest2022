import java.util.*;
class Account_node //node class for storing details and nodes.
{
    int Account_no;
    String Name;
    String Address;
    double Balance;
    Account_node next;
   
    Account_node (String name,String addr,int ac,double bal)
    //constructor to accept details and store.
    {
        Account_no=ac;
        Address=addr;
        Name=name;
        Balance=bal;
        next=null;//initialize next to null.
    }
}
class Bank //Bank class for performing operations.
{
    Account_node head;//initial node is assigned head.
    Scanner sc=new Scanner(System.in);
   
    void create() //Create method to Create list.
    {
        int ans=0;
        int i=0;
        Account_node node[]=new Account_node[10];
        //array of object for accepting nodes one after other.
        do {
            System.out.println("Enter your name:");
            String name=sc.next();
            System.out.println("Enter your address:");
            String addr=sc.next();
            System.out.println("Enter your account number:");
            int ac_no=sc.nextInt();
            System.out.println("Enter your initial amount (must be>500)");
            double bal=sc.nextDouble();
            if(bal<500)
                 //Balance condition.
                System.out.println("Balance must be greater than 500.Try again!");
            else
            {
                //passing details to above calss.
              node[i]=new Account_node(name,addr,ac_no,bal);
              System.out.println("Do you want to continue adding nodes?If yes press 1 else 0");
              //to add nodes in list.
              ans=sc.nextInt();
              if(head==null)  //if head ==null data is stored in first node.
                  head=node[i];
              else //if head is not null data is stored in last node.
              {
                  Account_node n=head;
                  while(n.next!=null) {
                      n=n.next;
                  }
                  n.next=node[i];
              }
              System.out.println("Account created successfully..");
              i++;
            }
        }while (ans==1);//nodes will added as long as user wants.
    }
    void insert()//method to insert node at end.
    {
        System.out.println("Enter your name:");
        String name=sc.next();
        System.out.println("Enter your address:");
        String addr=sc.next();
        System.out.println("Enter your account number:");
        int ac_no=sc.nextInt();
        System.out.println("Enter your amount balance");
        double bal=sc.nextDouble();
        //passing data ti class Account_node.
        Account_node node=new Account_node(name,addr,ac_no,bal);
        if(head==null) //condition if this is first node.
        {
            head=node;
        }
        else
        {
            Account_node n=head; //variable n assigned head of list.
            while(n.next!=null) //traversing till last node.
            {
                n=n.next;
            }
            n.next=node;//putting address to new last node.
        }System.out.println("Inserted sucessfully at the end.");
    }
    public void insertAtStart()//method to insert node at start.
    {
        System.out.println("Enter your name:");
        String name=sc.next();
        System.out.println("Enter your address:");
        String addr=sc.next();
        System.out.println("Enter your account number:");
        int ac_no=sc.nextInt();
        System.out.println("Enter your amount balance");
        double bal=sc.nextDouble();
         Account_node node=new Account_node(name,addr,ac_no,bal);
         node.next=null;
         node.next=head;//new node will point to initial node.
         head=node;//head will point to node created.
         System.out.println("Inserted sucessfully at the start.");
    }
     public void insertAt(int index) //method to insert node at a particular index
    {
            if (index == 0)
            //if index is zero that means we have to insert at the start.
                insertAtStart();
            else //when index is not 0.
            {
                try
                {
                        Account_node n = head; //n points to head.
                        for (int i = 0; i < index - 1; i++) //for loop till we find the required index.
                        {
                            n = n.next;
                        }
                        System.out.println("Enter your name: "); //details
                        String name = sc.next();
                        System.out.println("Enter your address:  ");
                        String addr = sc.next();
                        System.out.println("Enter your account number:  ");
                        int ac_no = sc.nextInt();
                        System.out.println("Enter the account balance: ");
                        double bal = sc.nextDouble();
                        Account_node node = new Account_node(name, addr, ac_no, bal);//passing values to Account_node
                        node.next = null;
                       
                        node.next = n.next;
                        //changing the reference in the new node from null to the reference in the preceeding node.
                        n.next = node; //changing the preceeding's node n's reference to new node's address
                        System.out.println("Inserted successfully at the index: " + index);
                }catch (NullPointerException n)
                {
                    System.out.println("Oops ! This index is not available!");
                }
        }

    }

    void delete(int index) //method to delete a node at a particular index.
    {
        if(head==null) //condition to check if list is present.
            System.out.println("List is empty!");
        else //When list is present
        {
            if (index == 0) //deleting the head.
                head = head.next; //changing the head pointer.
            else  //when element to be deleted is not head.
            {
                Account_node n = head; //n pointing to head
                Account_node n1 = null; //Temporary Node n1
                for (int i = 0; i < index - 1; i++)
                //for loop to find the node preceeding the node to be deleted.
                    n = n.next;
                n1 = n.next; //n1 is temporary node to get the reference part of node to be deleted.
                n.next = n1.next; //this puts address of the succeeding element in the preceeding node.
            }
            System.out.println("Deleted successfully!");
        }
    }
    void display() //method to display the list
    {
        if(head==null) //if list is empty.
            System.out.println("List is empty!");
        else //when list is not empty
        {
            int i = 1;
            Account_node node = head; //node points to head.

                while (node.next != null)  //condition to traverse through the list.
                {
                    System.out.println("     Customer " + i );
                    System.out.println("Customer name: " + node.Name);
                    System.out.println("Customer account no.: " + node.Account_no);
                    System.out.println("Customer address: " + node.Address);
                    System.out.println("Customer balance: " + node.Balance);
                    node = node.next;
                    i++;
                    System.out.println();
                }
                //printing last node explicitly because it doesnt get printed in the loop.
                System.out.println("     Customer " + i );
                System.out.println("Customer name: " + node.Name);
                System.out.println("Customer account no.: " + node.Account_no);
                System.out.println("Customer address: " + node.Address);
                System.out.println("Customer balance: " + node.Balance);

        }
    }
    void deposit() //method to deposit in a particular account.
    {
        if (head == null)
            System.out.println("List is empty!");
        else
        {
            Account_node node = head;
            System.out.println("Enter the account number in which you want to deposit: ");
            int ac_no = sc.nextInt();
            while (node.Account_no != ac_no)
            //traversing through list to find the account number.
            {
                node = node.next;
                if (node == null)
                //when reached the last node without finding the account number.
                {
                    System.out.println("The bank account with ac number " + ac_no + " is not found!");
                    return;
                }
            }
            System.out.println("Enter the amount you want to deposit: ");
            double bal = sc.nextDouble();
            node.Balance = node.Balance + bal; //increamenting the initial balance.
            System.out.println("Amount Deposited successfully!!");
        }
    }
    void Withdraw()//method to withdraw money from a particular account.
    {
        if (head == null)
            System.out.println("List is empty!");
        else
        {
                 if (head == null)
                    System.out.println("List is empty!");
                else
                {
                    Account_node node = head;
                    System.out.println("Enter the account number in which you want to withdraw: ");
                    int ac_no = sc.nextInt();
                    while (node.Account_no != ac_no)
                    //traversing through list to find the account number.
                    {
                        node = node.next;
                        if (node == null)
                        //when reached the last node without finding the account number.
                        {
                            System.out.println("The bank account with ac number " + ac_no + " is not found!");
                            return;
                        }
                    }
                    System.out.println("Enter the amount you want to withdraw: ");
                    double bal = sc.nextDouble();
                    if (node.Balance - bal < 500) //500 must be present in the ac at any given time.
                    {
                        System.out.println("Insufficient balance!!");
                    }
                    else
                    {
                        node.Balance = node.Balance - bal; //increamenting the initial balance.
                        System.out.println(bal + " Rs. withdrawn successfully from account number " + ac_no);
                    }
                }
        }
    }

}
public class Assignment3
{
    public static void main(String[] args)
    {
        int choice;
        int index;
        Scanner sc = new Scanner(System.in);
        Bank bk=new Bank(); //object of bank class
        do{
        System.out.println("Enter your choice: ");
        System.out.println("1.Create a list: ");
        System.out.println("2.Display the list: ");
        System.out.println("3.Insert the data at the end:  ");
        System.out.println("4.Insert the data at the start: ");
        System.out.println("5.Insert the data at a particular index: ");
        System.out.println("6.Delete some data: ");
        System.out.println("7.Deposit money:");
        System.out.println("8.Withdraw money: ");
        int op=sc.nextInt();
        switch (op)
        {
            case 1:
                bk.create();//function to create.
                break;
            case 2:
                bk.display();//function to display.
                break;
            case 3:
                bk.insert();//function to insert.
                break;
            case 4:
                bk.insertAtStart();//Insert at start.
                break;
            case 5:
                System.out.println("At what index you want to insert: ");
                index=sc.nextInt();
                bk.insertAt(index);
                break;
            case 6:
                System.out.println("At what index you want to delete: ");
                index=sc.nextInt();
                bk.delete(index);//function to delete.
                break;
            case 7:
                bk.deposit();//function to deposit.
                break;
            case 8:
                bk.Withdraw();//function to withdraw.
                break;
            default:
                System.out.println("Invalid input!");
        }
            System.out.println();
            System.out.println("If you want to continue press 1");
            choice=sc.nextInt();
        }while (choice==1);
        System.out.println("  Thank You!");
    }
}

#include <iostream>
#include<cstdlib>
using namespace std;

class Node   //Creating the node
{
public:
    Node* next;
    string name, ic_num;
    Node()
    {
        next = NULL;
    }
};

//Declaring the Booking_systems and assigning its characteristics
class Booking_system//Singly list data structure
{
private:
    Node* head12; Node* tail12;
    Node* head5; Node* tail5;
    int size12;  int size5;
    int stockBalance12, stockBalance5;
    int inStock12_5, inStock5;//initial stock of 12.5 kg and 5 kg seperately
    int Price12_5, Price5;//Prices of 12.5 kg and 5 kg seperately

public:
    Booking_system()
    {
        head12 = NULL; tail12 = NULL;
        size12 = 0; size5 = 0;
        inStock12_5 = 0; inStock5 = 0;
        stockBalance12 = 0, stockBalance5 = 0;
        Price12_5 = 0;   Price5 = 0;
    }
    Node* gethead12() { return head12; }
    Node* gettail12() { return tail12; }
    Node* gethead5() { return head5; }
    Node* gettail5() { return tail5; }

    void retailer_menu()//Menu that the retailer use
    {
        char choice;
        do
        {
            cout << "\n\n\n\t\t______________QUEUE BOOKING SYSTEM FOR RETAILER_______________" << endl;
            cout << "\n\n\tNo        Functions                       Description" << endl;
            cout << "\n\t1\tNew Stock \t\t\tFill your stock" << endl;
            cout << "\n\t2\tDeliver the 12.5 Kg \t\tDelivery of 12.5kg booking" << endl;
            cout << "\n\t3\tDeliver the 5 Kg \t\t\Delivery of 5 kg booking" << endl;
            cout << "\n\t4\tQueue List \t\t\tBooking detail" << endl;
            cout << "\n\t5\tStock detail\t\t\tCurrent Stocks" << endl;
            cout << "\n\t6\tExit \t\t\t" << endl;
            cout << "\n\n\tEnter your choice :-";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                system("cls");            //To clear screen before displaying the following menu
                cout << "\n\t\t______________DETAILS OF AVAILABLE CYCLINDERS _______________" << endl;
                int stock12_5, stock5;
                int Pri12_5, pri5;
                cout << "\n\tNumber of 12.5 KG Litro gas in stock :-";
                cin >> stock12_5;
                cout << "\n\tPrice of 12.5 KG Litro gas :-";
                cin >> Pri12_5;
                cout << "\n\tNumber of 5 KG Litro gas in stock:-";
                cin >> stock5;
                cout << "\n\tPrice of 5 KG Litro gas:-";
                cin >> pri5;
                inStock12_5 = stock12_5; inStock5 = stock5;
                Price12_5 = Pri12_5; Price5 = pri5;
                break;
            }
            case '2':
                system("cls");
                cout << "\n\t\t______________DELIVERY STATUS _______________" << endl;
                deliverd12();
                break;
            case '3':
                system("cls");
                cout << "\n\t\t______________DELIVERY STATUS _______________" << endl;
                deliverd5();
                break;
            case '4':
                system("cls");
                Queue_list();
                break;
            case '5':
                system("cls");
                cout << "\n\n\n\n\t______________ STOCK COUNT  _______________" << endl;
                cout << "\n\tItem Type\t\t\tStock Count" << endl;
                cout << "\n\t12.5KG Litro\t\t\t" << inStock12_5 - stockBalance12 << endl;
                cout << "\t5.0KG Litro\t\t\t" << inStock5 - stockBalance5 << endl;
            case '6':
                break;
            default:
                cout << "\n\t\t\======== Invalid input ========";
            }
        } while (choice != '6');
    }

    void insert_Customer()//Insertion of a customers detail
    {
        string name, NIC, type;
        cout << "\n\t Name of customer :- ";
        cin.ignore(); cin >> name;
        cout << "\n\t Enter NIC number :- ";
        cin.ignore(); cin >> NIC;
        cout << "\n\t Enter Item type(Only mention the weight 12.5 or 5 KG) :- ";
        cin.ignore(); cin >> type;
        if (type == "12.5")
        {
            if (size12 < inStock12_5)
            {
                Node* NewCustomer = new Node;
                NewCustomer->name = name;
                NewCustomer->ic_num = NIC;
                Node* current = head12;
                bool isavalable = false;
                for (int i = 0; i < size12; i++)
                {
                    if (NewCustomer->ic_num == current->ic_num)
                    {
                        isavalable = true;
                        break;
                    }
                    current = current->next;
                }
                if (isavalable == true)
                {
                    cout << "\n\t========== You already have a booking!!!! =============" << endl;
                }
                else
                {
                    if (head12 == NULL)
                    {
                        head12 = NewCustomer;
                        tail12 = NewCustomer;
                        size12++;
                        stockBalance12++;
                    }
                    else
                    {
                        tail12->next = NewCustomer;
                        tail12 = NewCustomer;
                        size12++;
                        stockBalance12++;
                    }
                    cout << "\n\t============ New customer Inserted successfully ================";
                }
            }
            else
            {
                cout << "\n\t ============== Sorry!!! Out of stock =============\n";
            }
        }
        else if (type == "5")
        {
            if (size5 < inStock5)
            {
                Node* NewCustomer = new Node;
                NewCustomer->name = name;
                NewCustomer->ic_num = NIC;
                Node* current = head5;
                bool isavalable = false;
                for (int i = 0; i < size5; i++)
                {
                    if (NewCustomer->ic_num == current->ic_num)
                    {
                        isavalable = true;
                        break;
                    }
                    current = current->next;
                }
                if (isavalable == true)
                {
                    cout << "\n\t========== You already have a booking!!!! =============" << endl;
                }
                else
                {
                    if (head5 == NULL)
                    {
                        head5 = NewCustomer;
                        tail5 = NewCustomer;
                        size5++;
                        stockBalance5++;
                    }
                    else
                    {
                        tail5->next = NewCustomer;
                        tail5 = NewCustomer;
                        size5++;
                        stockBalance5++;
                    }
                    cout << "\n\t============ New customer Inserted successfully ================";
                }
            }
            else
            {
                cout << "\n\t ============== Sorry!!! Out of stock =============\n";
            }
        }
    }

    void Booking_detail()//Function used to Check the status of a customers booking
    {
        system("cls");
        string ic;
        int quiue_pos12, quiue_pos5;
        cout << "\t______________________ BOOKING DETAIL _____________________" << endl;
        cout << "\n\tInsert your NIC number :- ";
        cin >> ic; cout << endl;
        Node* current12 = head12;
        bool isAvailable12 = false;
        Node* current5 = head5;
        bool isAvailable5 = false;
        for (int i = 0; i < size12; i++)
        {
            if (current12->ic_num == ic)
            {
                isAvailable12 = true;
                quiue_pos12 = i + 1;
                break;
            }
            current12 = current12->next;
        }
        for (int i = 0; i < size5; i++)
        {
            if (current5->ic_num == ic)
            {
                isAvailable5 = true;
                quiue_pos5 = i + 1;
                break;
            }
            current5 = current5->next;
        }
        if (isAvailable12 == true)
        {
            cout << "\tName \t\t\t=\t" << current12->name << endl;
            cout << "\tNIC number \t\t=\t" << current12->ic_num << endl;
            cout << "\tItem type \t\t=\t" << "12.5 KG" << endl;
            cout << "\tQueue Number is \t=\t" << quiue_pos12 << endl;
            cout << endl;
        }

        if (isAvailable5 == true)
        {
            cout << "\tName \t\t\t=\t" << current5->name << endl;
            cout << "\tNIC number \t\t=\t" << current5->ic_num << endl;
            cout << "\tItem type \t\t=\t" << "5 KG" << endl;
            cout << "\tQueue Number is \t=\t" << quiue_pos5 << endl;
        }

        else if (isAvailable12 == false && isAvailable5 == false)
        {
            cout << "\n\t============ Your are not in the Queue ==============\n" << endl;
        }
    }

    void deleteFirst12()//Function delivers the 12.5 kg cylinder to the first person in the que
    {
        if (head12 == NULL)
            cout << "\n\n\t\t============= No orders ===============" << endl;
        else
        {
            Node* temp = head12;
            if (size12 == 1)
            {
                delete temp;
                head12 = NULL;
                tail12 = NULL;
                size12 = 0;
            }
            else
            {
                head12 = head12->next;
                delete temp;
                size12--;
                stockBalance12--;
            }
        }
    }
    void deleteLast12()//function used to cancel a booking
    {
        if (head12 == NULL)
            cout << "\n\t============= Queue is empty ==============" << endl;
        else
        {
            Node* temp = tail12;
            if (size12 == 1)
            {
                delete temp;
                head12 = NULL;
                tail12 = NULL;
                size12 = 0;
            }
            else
            {
                Node* current = head12;

                for (int i = 0; i < size12 - 2; i++)
                {
                    current = current->next;
                }
                tail12 = current;
                tail12->next = NULL;
                delete temp;
                size5--;
                stockBalance12--;
            }
        }
    }
    void deleteFirst5()//Function delivers the 5 kg cylinder to the first person in the que
    {
        if (head5 == NULL)
            cout << "\n\n\t\t============= No orders ===============" << endl;
        else
        {
            Node* temp = head5;
            if (size5 == 1)
            {
                delete temp;
                head5 = NULL;
                tail5 = NULL;
                size5 = 0;
            }
            else
            {
                head5 = head5->next;
                delete temp;
                size5--;
                stockBalance5--;
            }
        }
    }
    void deleteLast5()
    {
        if (head5 == NULL)
            cout << "\n\t============= Queue is empty ==============" << endl;
        else
        {
            Node* temp = tail5;
            if (size5 == 1)
            {
                delete temp;
                head5 = NULL;
                tail5 = NULL;
                size5 = 0;
            }
            else {
                Node* current = head5;

                for (int i = 0; i < size5 - 2; i++)
                {
                    current = current->next;
                }
                tail5 = current;
                tail5->next = NULL;
                delete temp;
                size5--;
                stockBalance5--;
            }
        }
    }
    void Delete_booking()//function used to cancel a booking
    {
        system("cls");
        string ic, type;  int pos;
        cout << "\t______________________ CANCEL THE BOOKING _____________________" << endl;
        cout << "\n\tInsert your NIC number :- ";
        cin >> ic;
        cout << "\n\t Enter Item type(Only mention the weight 12.5 or 5 ) :- ";
        cin.ignore(); cin >> type;
        Node* current12 = head12;
        bool isavalable12 = false;
        Node* current5 = head5;
        bool isavalable5 = false;
        if (type == "12.5")
        {
            for (int i = 0; i < size12; i++)
            {
                if (current12->ic_num == ic)
                {
                    isavalable12 = true;
                    pos = i;
                    break;
                }
                current12 = current12->next;
            }
            if (isavalable12 == true)
            {
                if (pos == 0)
                    deleteFirst12();
                else if (pos == size12 - 1)
                    deleteLast12();
                else
                {

                    Node* current = head12;
                    for (int i = 0; i < pos - 1; i++)
                    {
                        current = current->next;
                    }
                    Node* temp = current->next;
                    current->next = temp->next;
                    delete temp;
                    size12--;
                    stockBalance12--;
                }
                cout << "\n\n\t =============== Successfully Deleted the Booking =====================" << endl;
            }
            else
            {
                cout << "\n\t==================== Sorry !! You are not in the Queue =====================" << endl;
            }
        }
        else if (type == "5")
        {
            for (int i = 0; i < size5; i++)
            {
                if (current5->ic_num == ic)
                {
                    isavalable5 = true;
                    pos = i;
                    break;
                }
                current5 = current5->next;
            }
            if (isavalable5 == true)
            {
                if (pos == 0)
                    deleteFirst5();
                else if (pos == size5 - 1)
                    deleteLast5();
                else
                {

                    Node* current = head5;
                    for (int i = 0; i < pos - 1; i++)
                    {
                        current = current->next;
                    }
                    Node* temp = current->next;
                    current->next = temp->next;
                    delete temp;
                    size5--;
                    stockBalance5--;
                }
                cout << "\n\n\t =============== Successfully Deleted the Booking =====================" << endl;
            }
            else
            {
                cout << "\n\t==================== Sorry !! You are not in the Queue =====================" << endl;
            }
        }
        else
        {
            cout << "\n\t==================== Sorry !! Your Input Type is Invalid =====================" << endl;
        }
    }

    void customerMenu()//The menu that the customer sees
    {
        char choice;
        do
        {
            cout << "\n\n\n\n\t______________CYLINDER BOOKING SYSTEM FOR CUSTOMER_______________" << endl;
            cout << "\n\n\tNo        Functions                       Description" << endl;
            cout << "\n\t1\tBooking \t\t\tTo Book  gas cylinder" << endl;
            cout << "\n\t2\tBooking detail\t\t\tSearch using customer NIC number" << endl;
            cout << "\n\t3\tDelete\t\t\t\tDelete your booking" << endl;
            cout << "\n\t4\tExit\t\t\t\t" << endl;
            cout << "\n\n\tEnter you choice :-";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                system("cls");
                int pri12 = Price12_5;
                int pri5 = Price5;
                cout << "\n\n\n\n\t______________ CYLINDER BOOKING _______________" << endl;
                cout << "\n\tItem Type\t\tStock\t\tPrice" << endl;
                cout << "\n\t12.5KG Litro\t\t" << inStock12_5 - stockBalance12 << "\t\t" << pri12 << endl;
                cout << "\t5.0KG Litro\t\t" << inStock5 - stockBalance5 << "\t\t" << pri5 << endl;
                cout << "\n\t________________ Add your detail ________________" << endl;
                insert_Customer();
                break;
            }
            case '2':
                Booking_detail();
                break;
            case '3':
                Delete_booking();
                break;
            case '4':
                cout << "\n\t============= Exit =======================";
                break;
            default:
                cout << "\n\t =============== Invalid input ===============\n";
            }
        } while (choice != '4');
    }

    void Queue_list()
    {
        system("cls");
        cout << "\n\n\n\t\t\t_______________________QUEUE LIST FOR 12.5 KG CYLINDER_________________" << endl;
        cout << "\n\n\tPosition in the queue\t\t\tName\t\t\tNIC number\n" << endl;
        Node* Current12 = head12;
        for (int i = 0; i < size12; i++)
        {
            cout << "\t" << i + 1 << "\t\t\t\t\t" << Current12->name << "\t\t\t" << Current12->ic_num << "\t\t" << endl;
            Current12 = Current12->next;
        }
        cout << "\n\n\n\t\t\t_______________________QUEUE LIST FOR 5 KG CYLINDER_________________" << endl;
        cout << "\n\n\tPosition in the queue\t\t\tName\t\t\tNIC number\n" << endl;
        Node* Current5 = head5;
        for (int i = 0; i < size5; i++)
        {
            cout << "\t" << i + 1 << "\t\t\t\t\t" << Current5->name << "\t\t\t" << Current5->ic_num << "\t\t" << endl;
            Current5 = Current5->next;
        }
    }

    void deliverd12()
    {
        if (head12 == NULL)
            cout << "\n\n\t\t============= No orders ===============" << endl;
        else
        {
            Node* temp = head12;
            if (size12 == 1)
            {
                delete temp;
                head12 = NULL;
                tail12 = NULL;
                size12 = 0;
            }
            else
            {
                head12 = head12->next;
                delete temp;
                size12--;
            }
            cout << "\n\n\t\t============= DELIVERED SUCCESSFULLY ===============" << endl;
        }
    }
    void deliverd5()
    {
        if (head5 == NULL)
            cout << "\n\n\t\t============= No orders ===============" << endl;
        else
        {
            Node* temp = head5;
            if (size5 == 1)
            {
                delete temp;
                head5 = NULL;
                tail5 = NULL;
                size5 = 0;
            }
            else
            {
                head5 = head5->next;
                delete temp;
                size5--;
            }
            cout << "\n\n\t\t============= DELIVERED SUCCESSFULLY ===============" << endl;
        }
    }
};
int main()
{
    Booking_system aa;
    char choice;
    do
    {
        system("cls");
        cout << "\n\n\n\t\t______________QUEUE BOOKING SYSTEM______________" << endl;//The main menu
        cout << "\n\n\tNo        Functions                       Description" << endl;
        cout << "\n\t1\tRetailer \t\t\tFor retailer menu Enter 1" << endl;
        cout << "\n\t2\tCustomer \t\t\tFor customer menu Enter 2" << endl;
        cout << "\n\t3\tExit \t\t\t" << endl;
        cout << "\n\n\tEnter you choice :-";
        cin >> choice;
        switch (choice)
        {
        case '2':
            system("cls");
            aa.customerMenu();
            break;
        case '1':
            system("cls");
            aa.retailer_menu();
            break;
        case '3':
            cout << "\n\t=================== Thank you for visiting =====================";
            break;
        default:
            cout << "\n\n\t ============== Invalid input ==================";
        }
    } while (choice != '3');
}
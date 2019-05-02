#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

class DayOfYear
{
private:
    string daystr;
    string  * ptr = &daystr;
    int D;
    int J;
    int K;
     //MONTH= J
    //DAY= K
    //numb of days in year = D

public:

    void print ();
    DayOfYear (int d);
    ~DayOfYear();
    void calculate ();
    void month();


};


DayOfYear::DayOfYear (int d)
{
    D = d;
}


void DayOfYear::calculate()
{
    int tempday;

    if(D >= 60)
    {
        tempday= D+1;
    }else
    {
        tempday = D;
    }

    int L= tempday+37+68569;
    int N= 4*L/146097;
    L = L-(146097*N+3)/4;
    int I= 4000*(L+1)/1461001;
    L= L-1461*I/4+31;
    J= 80*L/2447;
    K= L-2447*J/80;
    L= J/11;
    J= J+2-12*L;

    //month= J
    //DAY= K
}

void DayOfYear::month()
{

    switch(J){
        case 1:
            ptr->append("January ");
            break;
        case 2:
            ptr->append("February ");
            break;
        case (3):
            ptr->append("March ");
            break;
        case 4:
            ptr->append("April ");
            break;
        case 5:
            ptr->append("May ");
            break;
        case 6:
            ptr->append("June ");
            break;
        case 7:
            ptr->append("July ");
            break;
        case 8:
            ptr->append("August ");
            break;
        case 9:
            ptr->append(" September ");
            break;
        case 10:
            ptr->append(" October ");
            break;
        case 11:
            ptr->append(" November ");
            break;
        case 12:
            ptr->append(" December ");
            break;
        default:
            ptr->append(" December ");
            break;
    }
}


void DayOfYear::print ()
{

    string temp;
    calculate ();

    ptr->append("Day ");
    temp = to_string(D);
    ptr->append(temp);

    ptr->append(" would be ");
    month();

    temp = to_string(K);
    ptr->append(temp);


    cout <<daystr<<endl;
}

DayOfYear::~DayOfYear(){}


int main()
{
    int day;

    cout << "-------------------------------------------------" << endl;
    cout << "Please enter the day:" << endl;
    cin >> day;

    DayOfYear D (day);

    D.print();

    return 0;
}


#include <iostream>
#include<cmath>

/*
Mohammad Al-Tawil 
sec(1)
118256
*/

using namespace std;

// this is a global variable to show in all function
double c_value, yc_value, err_value;
 


// my functions
double calculateMyFunction(double);
void claculateBisectionFunction(double , double , double);



// main function
void main() {

    double valueOfDaltaFunction = 5 * pow(10, -9);
    double valueOf_A = -2.4, valueOf_B = -1.6;

    claculateBisectionFunction(valueOf_A, valueOf_B, valueOfDaltaFunction);



    cout << "Valu of c :  "<<c_value <<endl<< "Value of yc :  " << yc_value <<endl<< "Value of err :  " << err_value<<endl<<endl;
}


// implementaion of calculateMyFunction
double calculateMyFunction(double x_value) 
{
    double Result = exp(x_value) - 2 - x_value;
    return Result;
}


// implementaion of claculateBisectionFunction
void claculateBisectionFunction(double a_value, double b_value, double dalta_value) 
{
    err_value = abs(b_value - a_value);

    double ya = calculateMyFunction(a_value), yb = calculateMyFunction(b_value);


    if (ya * yb > 0) 
    { 
        return; 
    }




    double max1_value = abs(1 + round((log(0.8) - log(dalta_value)) / log(2)));


    int x = 1;
    while ( x < max1_value ) 
    {
        c_value = (a_value + b_value) / 2;


        yc_value = calculateMyFunction(c_value);


        if (yc_value == 0) 
        {
            a_value = c_value;
            b_value = c_value;
        } 
        else if (yb * yc_value > 0) 
        {
            b_value = c_value;
            yb = yc_value;
        }
        else 
        {
            a_value = c_value;
            ya = yc_value;
        }
        if (b_value - a_value < dalta_value) 
        { 
            break; 
        }
        x++;
    }

}
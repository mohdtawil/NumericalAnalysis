#include <iostream>
#include <cmath>

/*
Mohammad Al-Tawil
sec(1)
118256
*/

using namespace std;


// this is a global variable to show in all function
double c_value, yc_value, err_value, dx, ac;




// my functions
double calculateMyFunction(double);
void claculateBisectionFunction(double, double, double, double, double);



// main function
void main()
{

    double  a_value, b_value, valueOfDaltaFunction = 5 * pow(10, -9), epsolin = 5 * pow(10, -9), max1 = 50;


    cout << "Please Enter valu of a : ";
    cin >> a_value;

    cout << "Please Enter valu of b : ";
    cin >> b_value;


    claculateBisectionFunction(a_value, b_value, valueOfDaltaFunction, epsolin, max1);


    cout << "Valu of c :  " << c_value << endl << "Value of yc :  " << yc_value << endl << "Value of err :  " << err_value << endl << endl;
}



// implementaion of calculateMyFunction
double calculateMyFunction(double x_value)
{
    double Result = exp(x_value) - 2 - x_value;
    return Result;
}



// implementaion of claculateBisectionFunction
void claculateBisectionFunction(double a_value, double b_value, double dalta_value, double epsolin_value, double max1_value)
{
    double ya, yb;


    err_value = abs(b_value - a_value);



    ya = calculateMyFunction(a_value); yb = calculateMyFunction(b_value);


    if (ya * yb > 0) { return; }



    int x = 1;


    while (x < max1_value);
    {
        dx = yb * (b_value - a_value) / (ya * yb);

        c_value = b_value - dx;

        yc_value = calculateMyFunction(c_value);

        ac = c_value - a_value;

        if (yc_value == 0)
        {
            return;
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
        dx = min(abs(dx), ac);
        if (abs(dx) < dalta_value)
        {
            return;
        }
        if (abs(yc_value) < epsolin_value)
        {
            return;
        }
        x++;
    }

}
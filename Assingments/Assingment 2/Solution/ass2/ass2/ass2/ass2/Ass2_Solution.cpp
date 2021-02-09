#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

/*

    Name:   Mohammad Al-Tawil
    StuID:  118256
    Sec:    1

*/


// Initialize A array and set a size value 3x3
const int A_array_row = 3;
const int A_array_col = 3 + 1;
double A_array[A_array_row][A_array_col];  //= { {4,1,-1,13},{1,-5,-1,-8},{2,-1,-6,-2} }

// Initialize X array and set a size value 3
const int X_array_row = 3;
double X_array[X_array_row];



// Fill The X_array Declaration
void Fill_X_Array();

// Calculate a Subject Matter Declaration
void Make_Subject_Matter();

// Calculate a Equation Declaration
void Calculate_Equation();

// Print Result Declaration
void Print_Result();


void main()
{

    Fill_X_Array();

    Make_Subject_Matter();

    Calculate_Equation();

    Print_Result();
}

// Fill The X_array Implmention
void Fill_X_Array()
{

    cout << "Welcome...\n\n" << "Please Fill The Array" << endl << endl;

    int x = 0;

    int y = 0;


    while (x < A_array_row)
    {


        string location_row = (x == 0) ? "First" : (x == 1) ? "Second" : "Third";

        cout << "-- " << location_row + " Row --" << endl;




        y = 0;


        while (y < A_array_col)
        {

            string location_column = (y == 0) ? "First" : (y == 1) ? "Second" : (y == 2) ? "Third" : "Fourd";

            cout << location_column + " Value : ";

            cin >> A_array[x][y];




            y++;
        }





        x++;
    }
}


// Calculate a Subject Matter Implmention
void Make_Subject_Matter()
{
    int x = 0;
    int y = 0;
    int z = 0;
    double Temp_Value_1 = 0;


    while (x < A_array_row)
    {


        y = x + 1;

        while (y < A_array_col)
        {

            double Value_1 = A_array[y][x], Value_2 = A_array[x][x];

            Temp_Value_1 = Value_1 / Value_2;

            z = 0;


            while (z <= A_array_row)
            {


                double Temp_Value_2 = Temp_Value_1 * A_array[x][z];


                A_array[y][z] = A_array[y][z] - Temp_Value_2;




                z++;
            }




            y++;
        }




        x++;
    }
}


// Calculate a Equation Implmention
void Calculate_Equation()
{


    int x = A_array_row;
    int y = 0;


    double Temp_Value_1 = 0, Temp_Value_2 = 1;


    --x;
    while (x >= 0)
    {
        double Sum_Value = 0;

        X_array[x] = A_array[x][A_array_row];

        y = x + 1;


        while (y < A_array_col)
        {
            if (x != y)
            {
                Temp_Value_1 = A_array[x][y] * X_array[y];



                X_array[x] = X_array[x] - Temp_Value_1;
            }

            y++;

        }

        Temp_Value_2 = X_array[x] / A_array[x][x];

        X_array[x] = Temp_Value_2;



        x--;
    }
}


// Print Result Implmention
void Print_Result()
{

    cout << endl << endl;
    cout << "----------------------------------" << endl << endl;
    cout << "\t Final Result " << endl << endl;

    int x = 0;
    while (x < 3)
    {
        cout << "      Value " << x << " :   " << fixed << setprecision(4) << X_array[x] << endl;
        x++;
    }
    cout << endl;
    cout << "----------------------------------" << endl;
}
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double function(double);
void check(double);
double secant_method(double,double,double);

int main(){

    double begin = 3, end = 9, x , prev_x, res, esp = 10e-10;


    while(begin<end-1){
    prev_x = end;
    x= begin;

    res = secant_method(prev_x, x, esp);
    if(res>=begin && res<=end){
        cout<<"Root: "<<setprecision(10)<<res<<"\t";
        check(res);
    }

    begin+=1;

    }
    return 0;
}

double secant_method(double prev_x, double x,double esp){

    double buffer_x,res;

    do{
        buffer_x = res;
        res =  prev_x- ((prev_x-x)/(function(prev_x)-function(x)))*function(prev_x);
        prev_x = x;
        x=res;
    }while(abs(res-buffer_x)>=esp);

    return res;

}

void check(double res){
    cout<<"Y(x)= "<<function(res)<<endl<<endl;
}

double function(double x){
    return x - 5*pow(sin(x),2) - 5;
}
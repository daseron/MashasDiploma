#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>


using namespace std;


int main(int argc, char * argv[]) {
    
    
    ofstream F ("GraphicPoints.txt");
    cout.precision(8);
    
    const double U=0.5;
    
    const int N = 20;//количество точек по длинне
    const int M=100;//Количество временных слоев
    const double D=0.05;
    const double T=0.5;
    
    
    const double l = 1;//  длинна стержня в см
    
    const double h = l/(N-1);
    cout<<"H = "<<h<<"\n";
    
    double Tau=T/(M-1);
    cout<<"Tau = "<<Tau<<"\n";
    
    const double x1=0.4,x2=0.6,mo=1;


    double gamma;
    gamma = (D*Tau)/h;
    cout<<"Gamma= "<<gamma<<"\n";
   
    
    double Time = M * Tau;// общее время нагрева
    cout<<"Time= "<<Time<<"\n";
    
    double *X = NULL;
    double *C = NULL;
    double *C2 = NULL;
    
    X = new double [N];
    C = new double [N];
    C2 = new double [N];
    
    X[0]=0; // Заполнение массива иксов (точек на стержне
    
    for (int i=0;i<N;i++)
    {
        X[i]=i*h;
        
        //cout<<"X["<<i<<"]="<<X[i]<<"\n";
    }
    
   
    // Цикл заполнения массива
    
    
    
    for (int i = 0 ; i < N ; ++i){ //начальные условия
        
        if ( X[i] < x1 || X[i] > x2 )
        {C[i]=0;}
        
        if ( X[i] > x1 && X[i] < x2)
        { C[i] = mo / (x2-x1);}
        
            }
    
    for (int i = 0 ; i < N ; ++i){ //начальные условия
        cout<<"\nC["<<i<<"] = "<<C[i];
        
    }
    
    //double check=(D*Tau)/(2*h*h);
   // cout <<"Check = "<<check<<"\n\n";
    
     
    
    for (int j = 0 ; j < M ; ++j ) {
        
        
        
        for (int i = 0 ; i < N  ; ++i){
            
            
            if (i != 0 & i != N-1)
                C2[i]= C[i] + Tau * (   ((-U) * ((C[i+1]-C[i])/h))    +    (   D * ((C[i-1] - (2*C[i]) + C[i+1])/(h*h))  )    ) ;
            if (i == 0)
                C2[i]=0;
            if (i == N - 1)
                C2[i]=0;
            
        }
        
        for (int i = 0 ; i < N ; ++i){
            C[i] = C2[i];
        }
        
        
    }

    
    for (int i = 0 ; i < N ; ++i){ //начальные условия
       // F<<"\n["<<X[i]<<";"<<C[i]<<"]";
        //if( i != N-1)
        //    F<<",";
        F<<"\n"<<C[i];
        
    }
    
    
    
    delete [] C;
    delete [] C2;
    
    
    
    
    
    F.close();
    cout<<"\n";
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main(int argc , char **argv){

if (argc>1)
{
    float tempratureCelcius = 0;
    if(tempratureCelcius == 0){
        printf("please provide valid temprature");
    }
    else{
 tempratureCelcius = atof(argv[1]);
    float farhnheit = (tempratureCelcius * 9/5) +32;
    printf("celcius : %f  to farhnheit : %f",tempratureCelcius,farhnheit);
    }
}
else{
    printf("error , please provide us  temprature");
}

    
    
}
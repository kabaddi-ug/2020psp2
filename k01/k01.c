#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 double ave_online(double val,double ave,double n){
     return (((n-1)/n)*ave)+(val/n);
}
 double var_online(double val,double ave,double square_ave,double n){
    return (((n-1)*square_ave/n)+(val*val/n))-(((n-1)*ave/n)+(val/n))*(((n-1)*ave/n)+(val/n));
}





int main(void)
{
    double val,ave,n=1,square_ave=0, a,b,c;
    char fname[FILENAME_MAX];
    char buf[256];
    square_ave=0;
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        
        a=ave_online( val,ave,n);
        b=var_online( val, ave, square_ave,n);
         c=n*b/(n-1);
        square_ave=ave_online(val*val,square_ave,n);
        n=n+1;
        ave=a;
        
    }


    



    

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

printf("average:%f\n",a);
printf("variance:%f\n",b);
printf("est.average:%f\n",a);
printf("est.variance:%f\n",c);
    return 0;


}


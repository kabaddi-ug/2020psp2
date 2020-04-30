#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double y);

int main(void)
{
    double val,yA=0,yB=0,pA=0,pB=0,L_A=1,L_B=1,muA=170.8,sigmaA=5.43,muB=169.7,sigmaB=5.5;
    char fname[FILENAME_MAX];
    char buf[256];
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
        yA=(val-muA)/sigmaA;
        pA=p_stdnorm(yA);
        L_A=L_A*pA;

        yB=(val-muB)/sigmaB;
        pB=p_stdnorm(yB);
        L_B=L_B*pB;



    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L_A);
    printf("L_B: %f\n",L_B);

    return 0;


}

double p_stdnorm(double y)
{
    return 1/sqrt(2*M_PI) * exp(-y*y/2);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Hdata
{
    int Id;
    int Gender;
    double Height;
};

int main(void)
{   
    int id,i=1,ID;
    int gender;
    double height;
    struct Hdata data1[14];

  char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample height: %s\n",fname);

     fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d %lf",&gender,&height);
        
    
        data1[i].Gender=gender;
        data1[i].Height=height;
        i++;
    }

         if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
         }

       printf("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

     fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    i=1;
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d",&id);


        data1[i].Id=id;
        i++;
    }
        

         if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
         }

    printf("Which ID's data do you want?\n");
    scanf("%d", &ID);
    if(ID==data1[i].Id)
    {
        printf("ID : %d\n",ID);
        if(gender==1)
        {
            printf("gender : Male\n");
        }
        else
        {
            printf("gender : Female\n");
        }
        printf("height : %lf\n",height);
    }
    else
    {
        printf("NO data\n");
    }

    return 0;

}






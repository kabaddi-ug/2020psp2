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
    int id,i=0,ID;
    int gender;
    double height;
    struct Hdata data1[14];

  char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample : %s\n",fname);

     fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    fgets(buf, sizeof(buf),fp);
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d ,%lf",&gender,&height);
        
    
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
    i=0;
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
    for(i=0; i<14; ++i){
    if(data1[i].Id==ID){
        
    
    
        printf("---\n");
    
        printf("ID : %d\n",ID);
        if(data1[i].Gender==1)
        {
            printf("gender : Male\n");
        }
        else{
        
            printf("gender : Female\n");
        }
        printf("height : %4.1lf\n", data1[i].Height);
        return 0;
    }}
    {
        printf("---\n");
        printf("No data\n");
    }
    
    
    
    

    

}






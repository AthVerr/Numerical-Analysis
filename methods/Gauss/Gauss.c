#include <stdio.h>
#include <stdlib.h>
#define N 100
int main(int argc, char *argv[])
{  
  FILE *sys1, *sys2, *sys3;
  char c, arxeio1[N], arxeio2[N], arxeio3[N];
  int i=0, n, j, k, l;  
  //anoigma arxeiwn kai elegxos gia yparksi
  sys1 = fopen("system1.txt","r"); 
  sys2 = fopen("system2.txt","r");
  sys3 = fopen("system3.txt","r");  
  if (sys1 == NULL) 
     printf("File doesn't exist\n");  
  if (sys2 == NULL) 
     printf("File doesn't exist\n");     
  if (sys3 == NULL) 
     printf("File doesn't exist\n");  
     //apothikeusi twn stoixeiwn tou arxeiou se pinaka xaraktirwn 
   do
  {
    c = getc(sys1);  
    arxeio1[i] = c;  
    i++;
  }
  while (c!= EOF); 
 //kanw ton 1 xaraktira tou arxeiou se int gia na m dwsei tis diastaseis tou epauksimenou pinaka
  n = atoi(&arxeio1[0]);                       
  double Aep[n][n+1], Aeph[n][n+1];  //epauksimenos pinakas + voithitikos pinakas
  double b[n+1];       //gia prakseis metaksi twn grammwn tou epauksimenou pinaka
  double constant[n];  //pinakas gia tous statherous orous tou systimatos
  double lyseis[n];    //gia tis lyseis mas 
    // dimiourgia epauksimenou pinaka apo to arxeio1
  l = 1;
  for(j=0; j<n; j++)
  {
     for(k=0; k<n+1; k++)
     {
         if(arxeio1[l]=='\n')
         {
             Aep[j][k] = atof(&arxeio1[l+1]);
             l= l+2;
         }
         else
         {
             while(isdigit(arxeio1[l]))
               l++;
             Aep[j][k] = atof(&arxeio1[l+1]);
             l=l+2;
         }
     }
  }  
  fclose(sys1); //kleisimo  arxeiou  
  for(i=0; i<n; i++)
  {
        for(j=i+1; j<n; j++)
        {
           for(k=0; k<n+1; k++)
           {
             b[k] = -(Aep[i][i]/Aep[j][i])*Aep[j][k]; //o arithmos me ton opoio 8a pollaplasiastei i kathe grammi tou pinaka
             Aeph[j][k] = b[k] + Aep[i][k]; //oi prakseis metaxi twn grammwn tou pinaka 
           }
           for(k=0; k<n+1; k++)
             Aep[j][k] = Aeph[j][k];  //o neos epauksitikos pinakas
        }
        constant[i] = Aep[i][n]; //i teleutaia stilh tou epauksimenou einai to dianisma twn statherwn orwn
  }  
  if((Aep[n-1][n]!=0)&&(Aep[n-1][n-1]==0))
     printf("To systhma einai adynato!\n"); //ean exw 0*x = b
 
  else if((Aep[n-1][n]==0)&&(Aep[n-1][n-1]==0))
     printf("To systhma exei apeires lyseis!\n"); //ean exw 0*x = 0  
  else
  {
     printf("H lysh toy systhmatos einai : (");
     lyseis[n-1] = Aep[n-1][n]/Aep[n-1][n-1];
     for(k=0;k<n-1;k++)
     {
        i=n-k-2;
        for(j=i+1;j<n;j++)
       {
         constant[i]=constant[i]-(Aep[i][j]*lyseis[j]);
         lyseis[i]=constant[i]/Aep[i][i];
       }        
     }
     
     for(k=0; k<n-1; k++)
         printf("%f, ",lyseis[k]);    
     printf("%f)\n", lyseis[n-1]);
 }  
  //arxeio2
  printf("\n");  
  i=0;
  do
  {
    c = getc(sys2);  
    arxeio2[i] = c;   
    i++;
  }
  while (c!= EOF); 
  //kanw ton 1 xaraktira tou arxeiou se int gia na m dwsei tis diastaseis tou epauksimenou pinaka
  n = atoi(&arxeio2[0]);   
   // dimiourgia epauksimenou pinaka apo to arxeio2
  l = 1;  
  for(j=0; j<n; j++)
  {
     for(k=0; k<n+1; k++)
     {
         if(arxeio2[l]=='\n')
         {
             Aep[j][k] = atof(&arxeio2[l+1]);
             l= l+2;
         }
         else
         {
             while(isdigit(arxeio2[l]))
               l++;
             Aep[j][k] = atof(&arxeio2[l+1]);
             l=l+2;
         }
     }
  }
  
  fclose(sys2);  
  for(i=0; i<n; i++)
  {    
         for(j=i+1; j<n; j++)
         {
            for(k=0; k<n+1; k++)
            {
                b[k] = -(Aep[i][i]/Aep[j][i])*Aep[j][k];//o arithmos me ton opoio 8a pollaplasiastei i kathe grammi tou pinaka
                Aeph[j][k] = b[k] + Aep[i][k];
            }
         for(k=0; k<n+1; k++)
             Aep[j][k] = Aeph[j][k];
         }
        constant[i] = Aep[i][n];
  }  
  if((Aep[n-1][n]!=0)&&(Aep[n-1][n-1]==0))
     printf("To systhma einai adynato!\n");
     
  else if((Aep[n-1][n]==0)&&(Aep[n-1][n-1]==0))
     printf("To systhma exei apeires lyseis!\n");     
  else
  {
     printf("H lysh toy systhmatos einai : (");
     lyseis[n-1] = Aep[n-1][n]/Aep[n-1][n-1];
     for(k=0;k<n-1;k++)
     {
        i=n-k-2;
        for(j=i+1;j<n;j++)
        {
              constant[i]=constant[i]-(Aep[i][j]*lyseis[j]);
              lyseis[i]=constant[i]/Aep[i][i];
        }        
     }     
     for(k=0; k<n-1; k++)
        printf("%f, ",lyseis[k]);    
     printf("%f)\n", lyseis[n-1]);
  }  
  //arxeio3
  printf("\n");
  i=0;
  do
  {
    c = getc(sys3);  
    arxeio3[i] = c;   
    i++;
  }
  while (c!= EOF); 
  n = atoi(&arxeio3[0]); 
 
  l = 1;
  
  for(j=0; j<n; j++)
  {
     for(k=0; k<n+1; k++)
     {
         if(arxeio3[l]=='\n')
         {
             Aep[j][k] = atof(&arxeio3[l+1]);
             l= l+2;
         }
         else
         {
             while(isdigit(arxeio3[l]))
               l++;
             Aep[j][k] = atof(&arxeio3[l+1]);
             l=l+2;
         }        
     }
  }
    fclose(sys3);  
  for(i=0; i<n; i++)
  {  
      for(j=i+1; j<n; j++)
      {
         for(k=0; k<n+1; k++)
         {
             b[k] = -(Aep[i][i]/Aep[j][i])*Aep[j][k];
             Aeph[j][k] = b[k] + Aep[i][k];
         }
         for(k=0; k<n+1; k++)
             Aep[j][k] = Aeph[j][k];
       }
      constant[i] = Aep[i][n];
  }
  if((Aep[n-1][n]!=0)&&(Aep[n-1][n-1]==0))
     printf("To systhma einai adynato!\n");
  else if((Aep[n-1][n]==0)&&(Aep[n-1][n-1]==0))
     printf("To systhma exei apeires lyseis!\n");
  else
  {  
     printf("H lysh toy systhmatos einai : (");
     lyseis[n-1] = Aep[n-1][n]/Aep[n-1][n-1];
     for(k=0;k<n-1;k++)
     {
        i=n-k-2;
        for(j=i+1;j<n;j++)
        {
              constant[i]=constant[i]-(Aep[i][j]*lyseis[j]);
              lyseis[i]=constant[i]/Aep[i][i];
        }        
     }     
     for(k=0; k<n-1; k++)
        printf("%f, ",lyseis[k]);    
     printf("%f)\n", lyseis[n-1]);
  }  
  system("PAUSE");	
  return 0;
}


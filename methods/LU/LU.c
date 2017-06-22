#include <stdio.h>
#include <stdlib.h>
#define N 100
int main(int argc, char *argv[])
{
  FILE *sys1, *sys2, *sys3;
  char c, arxeio1[N], arxeio2[N], arxeio3[N];
  int i=0, n, j, k, l, m;  
  sys1 = fopen("system1.txt","r"); //anoigma arxeiou
  sys2 = fopen("system2.txt","r");
  sys3 = fopen("system3.txt","r");  
  if (sys1 == NULL) 
     printf("File doesn't exist\n");  
  if (sys2 == NULL) 
     printf("File doesn't exist\n");     
  if (sys3 == NULL) 
     printf("File doesn't exist\n");  
  //1o arxeio
  do
  {
    c = getc(sys1);  //apo8hkevsh tvn stoixeiwn tou arxeio
    arxeio1[i] = c;   // se pinaka xarakthrwn
    i++;
  }
  while (c!= EOF);  
  n = atoi(&arxeio1[0]); //metatrepw ton 1o xarakthra tou arxeio se int 
                        //gia na mou dwsei tis diastaseis toy epayxhmenou pinaka
   double Aep[n][n+1], Aeph[n][n+1];  //o epayxhmenos pinakas kai enas voh8htikos pinakas
  double b[n+1];       //gia tis pra3eis meta3y twn grammwn tou epayxhmenou
  double constant[n];         //pinakas gia tous sta8erous orous tou systhmatos
  double lyseis1[n], lyseis2[n] ;    //gia tis lyseis mas
  double low[n][n];
  double upper[n][n];
  double sum =0;
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
  fclose(sys1);  
  for(i=0; i<n; i++)
  {
     constant[i] = Aep[i][n];
  }  
  for(k=0; k<n+1; k++)
  {
     low[k][k] = 1;
     for(i=k+1; i<n ; i++)
     {
         low[i][k] = Aep[i][k]/Aep[k][k];
         for(j=k+1; j<n; j++)
            Aep[i][j] = Aep[i][j]-low[i][k]*Aep[k][j];
     }
         for(j=k; j<n; j++)
           upper[k][j] = Aep[k][j];
         for(j=k+1; j<n; j++)
         {
            low[k][j] = 0;
            upper[j][k] = 0;
            }
  }  
    lyseis1[0] = constant[0];
     for(i=1;i<n;i++)
     {
                     sum =0;
        for(j=0;j<i;j++)
        {
                        sum = sum + low[i][j]*lyseis1[j];             
                      lyseis1[i]=(constant[i]-sum)/low[i][i];
        }        
     }
     lyseis2[n-1] = lyseis1[n-1]/upper[n-1][n-1];
     for(i=n-1; i>=0; i--)
     {
              sum=0;
              for(j=n-1; j>i; j--)
              {
                       sum = sum + upper[i][j]*lyseis2[j];
                       lyseis2[i] = (lyseis1[i]-sum)/upper[i][i];
                       }
              }              
      printf("H lysh toy systhmatos einai : (");
     for(k=0; k<n-1; k++)
        printf("%f, ",lyseis2[k]);    
     printf("%f)\n", lyseis2[n-1]);  
  //2o arxeio
  i=0;
  do
  {
    c = getc(sys2);  //apo8hkevsh tvn stoixeiwn tou arxeio
    arxeio2[i] = c;   // se pinaka xarakthrwn
    i++;
  }
  while (c!= EOF);  
  n = atoi(&arxeio2[0]);
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
         }     }  }  
           fclose(sys2);  
  for(i=0; i<n; i++)
  {
     constant[i] = Aep[i][n];

  }  
  for(k=0; k<n+1; k++)
  {
     low[k][k] = 1;
     for(i=k+1; i<n ; i++)
     {
         low[i][k] = Aep[i][k]/Aep[k][k];
         for(j=k+1; j<n; j++)
            Aep[i][j] = Aep[i][j]-low[i][k]*Aep[k][j];
     }
     for(j=k; j<n; j++)
           upper[k][j] = Aep[k][j];
     for(j=k+1; j<n; j++)
     {
            low[k][j] = 0;
            upper[j][k] = 0;
     }
  }  
  lyseis1[0] = constant[0];
  for(i=1;i<n;i++)  //gia thn pros ta mpros epilysh
  {
        sum =0;
        for(j=0;j<i;j++)
        {
             sum = sum + low[i][j]*lyseis1[j];
             lyseis1[i]=(constant[i]-sum)/low[i][i];
        }        
  }  
  lyseis2[n-1] = lyseis1[n-1]/upper[n-1][n-1];
  for(i=n-1; i>=0; i--) //gia thn pros ta pisw epilysh
  {
       sum=0;
       for(j=n-1; j>i; j--)
       {
             sum = sum + upper[i][j]*lyseis2[j];
             lyseis2[i] = (lyseis1[i]-sum)/upper[i][i];
       }  }              
  printf("H lysh toy systhmatos einai : (");
  for(k=0; k<n-1; k++)
        printf("%f, ",lyseis2[k]);    
  printf("%f)\n", lyseis2[n-1]);     
  //3o arxeio
  i=0;
  do
  {
    c = getc(sys3);  //apo8hkevsh tvn stoixeiwn tou arxeio
    arxeio3[i] = c;   // se pinaka xarakthrwn
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
     constant[i] = Aep[i][n];

  }  
  for(k=0; k<n+1; k++)
  {
     low[k][k] = 1;
     for(i=k+1; i<n ; i++)
     {
         low[i][k] = Aep[i][k]/Aep[k][k];
         for(j=k+1; j<n; j++)
            Aep[i][j] = Aep[i][j]-low[i][k]*Aep[k][j];
     }
     for(j=k; j<n; j++)
           upper[k][j] = Aep[k][j];
     for(j=k+1; j<n; j++)
     {
            low[k][j] = 0;
            upper[j][k] = 0;
     }
  }
  
  lyseis1[0] = constant[0];
  for(i=1;i<n;i++)
  {
        sum =0;
        for(j=0;j<i;j++)
        {
             sum = sum + low[i][j]*lyseis1[j];
             lyseis1[i]=(constant[i]-sum)/low[i][i];
        }        
  }
  
  lyseis2[n-1] = lyseis1[n-1]/upper[n-1][n-1];
  for(i=n-1; i>=0; i--)
  {
       sum=0;
       for(j=n-1; j>i; j--)
       {
            sum = sum + upper[i][j]*lyseis2[j];
            lyseis2[i] = (lyseis1[i]-sum)/upper[i][i];
       }
  }              
  printf("H lysh toy systhmatos einai : (");
  for(k=0; k<n-1; k++)
        printf("%f, ",lyseis2[k]);    
  printf("%f)\n", lyseis2[n-1]);     
  system("PAUSE");	
  return 0;
}

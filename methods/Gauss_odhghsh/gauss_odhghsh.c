#include <stdio.h>
#include <stdlib.h>
#define N 200

int main(int argc, char *argv[])
{
  FILE *sys1, *sys2, *sys3;
  char c, arxeio1[N], arxeio2[N], arxeio3[N];
  int i=0, n, j, k, l, q;
  double max, temp, sum;
  //anoigei to arxeio
  sys1 = fopen("system1.txt","r"); 
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
    c = getc(sys1);  
    arxeio1[i] = c;   
    i++;
  }
  while (c!= EOF);  
  n = atoi(&arxeio1[0]);                     
  double Aep[n][n+1], Aeph[n];  //o epauksimenos pinakas kai enas voh8htikos pinakas
  double b[n+1];       //gia tis pra3eis meta3y twn grammwn tou epayxhmenou
  double constant[n];         //pinakas gia tous sta8erous orous tou systhmatos
  double lyseis[n];    //gia tis lyseis mas 
    //gia th dhmiourgia tou epayxhmenou pinaka apo to arxeio1
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
  for(j=0;j<n-1;j++)
  {
     max = fabs(Aep[j][j]);
     l=j;
     
     for(k=j+1; k<n; k++)
     {
         if(fabs(Aep[k][j]) > max)
         {
                max = Aep[k][j];    //evresh tou megistou ari8mou se ka8e sthlh tou pinaka
                l = k;
         }
     }     
     if(l != j)
     {
         for(q=j; q<n+1; q++)
         {
                temp = Aep[j][q];
                Aep[j][q] = Aep[l][q]; //enallages metaxy grammwn
                Aep[l][q] = temp;
         }
     }        
     for(i=j+1;i<n;i++)
     {
          temp = Aep[i][j] / Aep[j][j];
          for(k=j;k<=n;k++)
                Aep[i][k] = Aep[i][k] - (temp * Aep[j][k]); //neos epafxhtikos
     }
  }
  lyseis[n-1] = Aep[n-1][n] / Aep[n-1][n-1];
  if((Aep[n-1][n]!=0)&&(Aep[n-1][n-1]==0))
     printf("To systhma einai adynato!\n");     
  else if((Aep[n-1][n]==0)&&(Aep[n-1][n-1]==0))
     printf("To systhma exei apeires lyseis!\n");     
  else
  {  
     printf("H lysh toy systhmatos einai : (");
     lyseis[n-1] = Aep[n-1][n]/Aep[n-1][n-1];
     for(i=n-2; i>=0; i--)
     {
        sum = 0;
        for(j=i+1;j<n;j++)
        {
            sum = sum + (Aep[i][j] * lyseis[j]);
        }
        lyseis[i] = (Aep[i][n] - sum)/Aep[i][i];
     }
 
     for(k=0; k<n-1; k++)
        printf("%f, ",lyseis[k]);    
     printf("%f)\n", lyseis[n-1]);
  } 
 //arxeio2
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
         }
     }
  }  
  fclose(sys2); 
  for(j=0;j<n-1;j++)
  {
     max = fabs(Aep[j][j]);
     l=j;
     
     for(k=j+1; k<n; k++)
     {
         if(fabs(Aep[k][j]) > max)
         {
                max = Aep[k][j];
                l = k;
         }
     }
     if(l != j)
     {
         for(q=j; q<n+1; q++)
         {
                temp = Aep[j][q];
                Aep[j][q] = Aep[l][q];
                Aep[l][q] = temp;
         }
     }        
     for(i=j+1;i<n;i++)
     {
        temp = Aep[i][j] / Aep[j][j];
        for(k=j;k<=n;k++)
            Aep[i][k] = Aep[i][k] - (temp * Aep[j][k]);
     }
  }
  lyseis[n-1] = Aep[n-1][n] / Aep[n-1][n-1]; 
  if((Aep[n-1][n]!=0)&&(Aep[n-1][n-1]==0))
     printf("To systhma einai adynato!\n");
  else if((Aep[n-1][n]==0)&&(Aep[n-1][n-1]==0))
     printf("To systhma exei apeires lyseis!\n");
  else
  {  
     printf("H lysh toy systhmatos einai : (");
     lyseis[n-1] = Aep[n-1][n]/Aep[n-1][n-1];
     for(i=n-2; i>=0; i--)
    {
        sum = 0;
        for(j=i+1;j<n;j++)
        {
            sum = sum + (Aep[i][j] * lyseis[j]);
        }
        lyseis[i] = (Aep[i][n] - sum)/Aep[i][i];
    }
 
    for(k=0; k<n-1; k++)
        printf("%f, ",lyseis[k]);    
     printf("%f)\n", lyseis[n-1]);
  }  
 //arxeio3
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
  for(j=0;j<n-1;j++)
  {
     max = fabs(Aep[j][j]);
     l=j;
     
     for(k=j+1; k<n; k++)
     {
         if(fabs(Aep[k][j]) > max)
         {
                max = Aep[k][j];
                l = k;
         }
     }
     if(l != j)
     {
         for(q=j; q<n+1; q++)
         {
                temp = Aep[j][q];
                Aep[j][q] = Aep[l][q];
                Aep[l][q] = temp;
         }
     }        
     for(i=j+1;i<n;i++)
     {
        temp = Aep[i][j] / Aep[j][j];
        for(k=j;k<=n;k++)
            Aep[i][k] = Aep[i][k] - (temp * Aep[j][k]);
     }
  }

  lyseis[n-1] = Aep[n-1][n] / Aep[n-1][n-1]; 
  if((Aep[n-1][n]!=0)&&(Aep[n-1][n-1]==0))
     printf("To systhma einai adynato!\n");
  else if((Aep[n-1][n]==0)&&(Aep[n-1][n-1]==0))
     printf("To systhma exei apeires lyseis!\n");
  else
  {  
     printf("H lysh toy systhmatos einai : (");
     lyseis[n-1] = Aep[n-1][n]/Aep[n-1][n-1];
     for(i=n-2; i>=0; i--)
    {
        sum = 0;
        for(j=i+1;j<n;j++)
        {
            sum = sum + (Aep[i][j] * lyseis[j]);
        }
        lyseis[i] = (Aep[i][n] - sum)/Aep[i][i];
    }
 
    for(k=0; k<n-1; k++)
        printf("%f, ",lyseis[k]);    
     printf("%f)\n", lyseis[n-1]);
  }  
  system("PAUSE");	
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define N 100
int main(int argc, char *argv[])
{
  FILE *sys1, *sys2, *sys3;
  char c, arxeio1[N], arxeio2[N], arxeio3[N];
  int i=0, n, l, j, k, iterations=5;  
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
  n = atoi(&arxeio1[0]);   
  double Aep[n][n+1], Aeph[n][n+1];  //o epayxhmenos pinakas kai enas voh8htikos pinakas
  double b[n+1];       //gia tis pra3eis meta3y twn grammwn tou epayxhmenou
  double constant[n];         //pinakas gia tous sta8erous orous tou systhmatos
  double L[n][n], U[n][n], D[n][n], Dinv[n][n], sum[n][n];
  double lyseis[n], m[n], temp[n]; 
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
  fclose(sys1); //kleisimo tou arxeiou  
  for(i=0; i<n; i++)
  {
     constant[i] = Aep[i][n];

  }  
  //dhmiourgia twn pinakwn L,U,D
  for(i=0; i<n; i++)
  {
     L[i][i] = 0;
     U[i][i] = 0;
     D[i][i] = Aep[i][i];
     
     for(k=i+1; k<n; k++)
     {
        L[i][k] = 0;
        U[i][k] = Aep[i][k];
        D[i][k] = 0;
     }
     
     for(k=0; k<i; k++)
     {
        L[i][k] = Aep[i][k];
        U[i][k] = 0;
        D[i][k] = 0;
     }
  }  
  //arxikh proseggish twn lysewn
  for(i=0; i<n; i++)
     lyseis[i] = 0;      
  //o antistrofos tou pinaka D
  for(i=0; i<n; i++)
  {
     for(j=0; j<n; j++)
    {    
        if(i==j)
           Dinv[i][j]=1/D[i][j];
        else
           Dinv[i][j]=0;
    } 
  }      
  //o pinakas sum einai to a8roisma L+U
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {    
        if(i==j)
           sum[i][j]=0;
        else
        {
           if(i != j)
              sum[i][j]= L[i][j] + U[i][j];
        }
    }
  m[i] = 0;
}
  i=1;  
  while(i<=iterations)
  {
     for(j=0; j<n; j++)
     {
        for(k=0; k<n; k++)
        {
           m[k] = m[k] + sum[j][k]*lyseis[k];
           temp[k]=constant[k]-m[k];
           lyseis[k] = lyseis[k] + Dinv[j][k]*temp[k]; 
        }     
    }
    for(k=0;k<n;k++)
        printf("%f\n",lyseis[k]); 
      i++;
  }  
  printf("\n"); 
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
         }
     }
  }
  fclose(sys2); //kleisimo tou arxeiou  
  for(i=0; i<n; i++)
  {
     constant[i] = Aep[i][n];

  }  
  //dhmiourgia twn pinakwn L,U,D
  for(i=0; i<n; i++)
  {
     L[i][i] = 0;
     U[i][i] = 0;
     D[i][i] = Aep[i][i];
     
     for(k=i+1; k<n; k++)
     {
        L[i][k] = 0;
        U[i][k] = Aep[i][k];
        D[i][k] = 0;
     }
     
     for(k=0; k<i; k++)
     {
        L[i][k] = Aep[i][k];
        U[i][k] = 0;
        D[i][k] = 0;
     }
  }  
  //arxikh proseggish twn lysewn
  for(i=0; i<n; i++)
     lyseis[i] = 0;      
  //o antistrofos tou pinaka D
  for(i=0; i<n; i++)
  {
     for(j=0; j<n; j++)
    {    
        if(i==j)
           Dinv[i][j]=1/D[i][j];
        else
           Dinv[i][j]=0;
    } 
  }      
  //o pinakas sum einai to a8roisma L+U
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {    
        if(i==j)
           sum[i][j]=0;
        else
        {
           if(i != j)
              sum[i][j]= L[i][j] + U[i][j];
        }
    }
  m[i] = 0;
}
  i=1;  
  while(i<=iterations)
  {
     for(j=0; j<n; j++)
     {
        for(k=0; k<n; k++)
        {
           m[k] = m[k] + sum[j][k]*lyseis[k];
           temp[k]=constant[k]-m[k];
           lyseis[k] = lyseis[k] + Dinv[j][k]*temp[k]; 
        }     
    }
    for(k=0;k<n;k++)
        printf("%f\n",lyseis[k]); 
      i++;
  }
  printf("\n");   
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
  fclose(sys3); //kleisimo tou arxeiou
    for(i=0; i<n; i++)
  {
     constant[i] = Aep[i][n];
  }  
  //dhmiourgia twn pinakwn L,U,D
  for(i=0; i<n; i++)
  {
     L[i][i] = 0;
     U[i][i] = 0;
     D[i][i] = Aep[i][i];
     
     for(k=i+1; k<n; k++)
     {
        L[i][k] = 0;
        U[i][k] = Aep[i][k];
        D[i][k] = 0;
     }
     
     for(k=0; k<i; k++)
     {
        L[i][k] = Aep[i][k];
        U[i][k] = 0;
        D[i][k] = 0;
     }
  }  
  //arxikh proseggish twn lysewn
  for(i=0; i<n; i++)
     lyseis[i] = 0;    
    //o antistrofos tou pinaka D
  for(i=0; i<n; i++)
  {
     for(j=0; j<n; j++)
    {    
        if(i==j)
           Dinv[i][j]=1/D[i][j];
        else
           Dinv[i][j]=0;
    } 
  }      
  //o pinakas sum einai to a8roisma L+U
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {    
        if(i==j)
           sum[i][j]=0;
        else
        {
           if(i != j)
              sum[i][j]= L[i][j] + U[i][j];
        }
    }
  m[i] = 0;
}
  i=1;  
  while(i<=iterations)
  {
     for(j=0; j<n; j++)
     {
        for(k=0; k<n; k++)
        {
           m[k] = m[k] + sum[j][k]*lyseis[k];
           temp[k]=constant[k]-m[k];
           lyseis[k] = lyseis[k] + Dinv[j][k]*temp[k]; 
        }     
    }
    for(k=0;k<n;k++)
        printf("%f\n",lyseis[k]); 
      i++;
  }
  printf("\n");
  system("PAUSE");	
  return 0;
}

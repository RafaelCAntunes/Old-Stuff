//Rafael de Camargo Antunes    RA 122110

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

main ()
{
 char especial[5] , v [4][4];
 int i,j,vi,jo,e;
 inicio:
 e=0;
  printf ("\n                                  Jogo da Velha \n\n\n");
 
 printf ("                                |               |                \n");
 printf ("                                |               |                \n");
 printf ("                 _______________|_______________|_______________ \n");
 printf ("                                |               |                \n");
 printf ("                                |               |                \n");
 printf ("                 _______________|_______________|_______________ \n");
 printf ("                                |               |                \n");
 printf ("                                |               |                \n");
 printf ("                                |               |                \n");
 
 vi = 0;
 jo = 1;
 
  for (i=1;i<=3;i++)
 {
     for (j=1;j<=3;j++)
     v[i][j] = ' ';
 }
 while (vi == 0)
 {
 if (jo==1)
 {
  linha:
  printf ("\n Jogador 1 (X) , digite a linha que voce deseja jogar \n");
  scanf ("%i",&i);
 if (i < 1 || i > 3)
 {
       puts ("O valor da linha deve estar entre 1 e 3");
    goto linha;
 }
 coluna: 
  printf ("\n agora digite a coluna que você deseja jogar \n");
  scanf ("%i",&j);
    if (j < 1 || j > 3)
 {
       puts ("O valor da coluna deve estar entre 1 e 3");
    goto coluna;
 }       
           while (v[i][j] == 'X' || v[i][j] == 'O')
            {
            printf ("\n Coordenadas digitadas coincidem com uma casa já ocupada... \n");
            printf ("\n Jogador 1, digite uma nova linha. \n");
            scanf ("%i",&i);
            printf ("\n Agora digite uma nova coluna. \n");
            scanf ("%i",&j);
            }
  
  v[i][j] = 'X';
 }
 
 
if ((v[1][1] == 'X' && v[1][2] == 'X' && v [1][3] == 'X') || (v[2][1] == 'X' && v[2][2] == 'X' && v [2][3] == 'X') || (v[3][1] == 'X' && v[3][2] == 'X' && v [3][3] == 'X'))
vi = 1;

if ((v[1][1] == 'X' && v[2][1] == 'X' && v [3][1] == 'X') || (v[1][2] == 'X' && v[2][2] == 'X' && v [3][2] == 'X') || (v[1][3] == 'X' && v[2][3] == 'X' && v [3][3] == 'X'))
vi = 1;

if (v[1][1] == 'X' && v [2][2] == 'X' && v [3][3] == 'X')
vi = 1;


if(v[3][1] == 'X' && v[2][2] == 'X' && v[1][3] == 'X')
vi = 1 ;                   

if (vi==0)
{
 jo = 2; 
}
else
jo = 1;

if (e==9)
vi=jo=9;
system ("cls");
if (jo ==2)
{
       printf ("\n\n\n\nJogada do computador: \n\n\n\n");
       
       if (v[1][1] == 'O' && v[2][2] == 'O' && v[3][3] == ' ')
       v [3][3] = 'O';
       
       else if (v[1][1] == 'O' && v[3][3] == 'O' && v[2][2] == ' ')
       v [2][2] = 'O';
       
       else if (v[2][2] == 'O' && v[3][3] == 'O' && v[1][1] == ' ')
       v [1][1] = 'O';
       
       
       else if (v[1][1] == 'O' && v[1][2] == 'O' && v[1][3] == ' ')
       v [1][3] = 'O';
       
       else if (v[1][1] == 'O' && v[1][3] == 'O' && v[1][2] == ' ')
       v [1][2] = 'O';
       
       else if (v[1][2] == 'O' && v[1][3] == 'O' && v[1][3] == ' ')
       v [1][3] = 'O';
   
       
       else if (v[2][1] == 'O' && v[2][2] == 'O' && v[2][3] == ' ')
       v [2][3] = 'O';
       
       else if (v[2][1] == 'O' && v[2][3] == 'O' && v[2][2] == ' ')
       v [2][2] = 'O';
       
       else if (v[2][2] == 'O' && v[2][3] == 'O' && v[2][3] == ' ')
       v [2][3] = 'O';
   
   
       else if (v[3][1] == 'O' && v[3][2] == 'O' && v[3][3] == ' ')
       v [3][3] = 'O';
       
       else if (v[3][1] == 'O' && v[3][3] == 'O' && v[3][2] == ' ')
       v [3][2] = 'O';
       
       else if (v[3][2] == 'O' && v[3][3] == 'O' && v[3][1] == ' ')
       v [3][1] = 'O';
   
       else if (v[1][1] == 'O' && v[2][1] == 'O' && v[3][1] == ' ' )
       v [3][1] = 'O';
       
       else if (v[1][1] == 'O' && v [3][1] == 'O' && v[2][3] == ' ')
       v [2][1] = 'O';
       
       else if (v[2][1] == 'O' && v [3][1] == 'O' && v[1][1] == ' ')
       v [1][1] = 'O';
       
       
       else if (v[1][2] == 'O' && v[2][2] == 'O' && v[3][2] == ' ')
       v [3][2] = 'O';
       
       else if (v[1][2] == 'O' && v [3][2] == 'O' && v[2][2] == ' ')
       v [2][2] = 'O';
       
       else if (v[2][2] == 'O' && v [3][2] == 'O' && v[1][2] == ' ')
       v [1][2] = 'O';
   
   
       else if (v[1][3] == 'O' && v[2][3] == 'O' && v[3][3] == ' ')
       v [3][3] = 'O';
       
       else if (v[1][3] == 'O' && v [3][3] == 'O' && v[2][3] == ' ')
       v [2][3] = 'O';
       
       else if (v[2][3] == 'O' && v [3][3] == 'O' && v[1][3] == ' ')
       v [1][3] = 'O'; 
       
       // Terminada a decisão de onde colocar CASO haja uma opção para vencer, proximo passo é colocar condição caso nao haja 
       
       
       
       else if (v[1][1] == 'X' && v[2][2] == 'X' && v[3][3] == ' ')
       v [3][3] = 'O';
       
       else if (v[1][1] == 'X' && v[3][3] == 'X' && v[2][2] == ' ')
       v [2][2] = 'O';
       
       else if (v[2][2] == 'X' && v[3][3] == 'X' && v[1][1] == ' ')
       v [1][1] = 'O';
       
       
       else if (v[1][1] == 'X' && v[1][2] == 'X' && v[1][3] == ' ')
       v [1][3] = 'O';
       
       else if (v[1][1] == 'X' && v[1][3] == 'X' && v[1][2] == ' ')
       v [1][2] = 'O';
       
       else if (v[1][2] == 'X' && v[1][3] == 'X' && v[1][3] == ' ')
       v [1][3] = 'O';
   
       
       else if (v[2][1] == 'X' && v[2][2] == 'X' && v[2][3] == ' ')
       v [2][3] = 'O';
       
       else if (v[2][1] == 'X' && v[2][3] == 'X' && v[2][2] == ' ')
       v [2][2] = 'O';
       
       else if (v[2][2] == 'X' && v[2][3] == 'X' && v[2][3] == ' ')
       v [2][3] = 'O';
   
   
       else if (v[3][1] == 'X' && v[3][2] == 'X' && v[3][3] == ' ')
       v [3][3] = 'O';
       
       else if (v[3][1] == 'X' && v[3][3] == 'X' && v[3][2] == ' ')
       v [3][2] = 'O';
       
       else if (v[3][2] == 'X' && v[3][3] == 'X' && v[3][1] == ' ')
       v [3][1] = 'O';
   
       else if (v[1][1] == 'X' && v[2][1] == 'X' && v[3][1] == ' ' )
       v [3][1] = 'O';
       
       else if (v[1][1] == 'X' && v [3][1] == 'X' && v[2][3] == ' ')
       v [2][1] = 'O';
       
       else if (v[2][1] == 'X' && v [3][1] == 'X' && v[1][1] == ' ')
       v [1][1] = 'O';
       
       
       else if (v[1][2] == 'X' && v[2][2] == 'X' && v[3][2] == ' ')
       v [3][2] = 'O';
       
       else if (v[1][2] == 'X' && v [3][2] == 'X' && v[2][2] == ' ')
       v [2][2] = 'O';
       
       else if (v[2][2] == 'X' && v [3][2] == 'X' && v[1][2] == ' ')
       v [1][2] = 'O';
   
   
       else if (v[1][3] == 'X' && v[2][3] == 'X' && v[3][3] == ' ')
       v [3][3] = 'O';
       
       else if (v[1][3] == 'X' && v [3][3] == 'X' && v[2][3] == ' ')
       v [2][3] = 'O';
       
       else if (v[2][3] == 'X' && v [3][3] == 'X' && v[1][3] == ' ')
       v [1][3] = 'O'; 
       
       
       
       // terminada decisão para não perder
       
       else
       {
            for (i=1;i<4;i++)
            {
                for (j=1;j<4;j++)
                {
                    if (v[i][j] == ' ')
                    {
                    v[i][j] = 'O';
                    i=j=4;
                    }
                }
            }
       }
       
       
       if ((v[1][1] == 'O' && v[1][2] == 'O' && v [1][3] == 'O') || (v[2][1] == 'O'&& v[2][2] == 'O' && v [2][3] == 'O') || (v[3][1] == 'O' && v[3][2] == 'O' && v [3][3] == 'O'))
       vi = 2;

       if ((v[1][1] == 'O' && v[2][1] == 'O' && v [3][1] == 'O') || (v[1][2] == 'O'&& v[2][2] == 'O' && v [3][2] == 'O') || (v[1][3] == 'O' && v[2][3] == 'O' && v [3][3] == 'O'))
       vi = 2;

       if (v[1][1] == 'O' && v [2][2] == 'O' && v [3][3] == 'O')
       vi = 2;


       if(v[3][1] == 'O' && v[2][2] == 'O' && v[1][3] == 'O')
       vi = 2;                         
       
       if (vi==0)
       jo = 1; 
        
       else
       jo = 2;
       
             
} // fechamento if
     
if (jo!=9)
{
       printf ("                                |               |               \n");
       printf ("                         %c      |        %c      |       %c        \n", v[1][1],v[1][2],v[1][3]);
       printf ("                 _______________|_______________|_______________\n");
       printf ("                                |               |               \n");
       printf ("                         %c      |        %c      |       %c        \n", v[2][1],v[2][2],v[2][3]);
       printf ("                 _______________|_______________|_______________\n");
       printf ("                                |               |               \n");
       printf ("                         %c      |        %c      |       %c        \n", v[3][1],v[3][2],v[3][3]);
       printf ("                                |               |               \n");  
}

e=0;
  
  for (i=1;i<4;i++)
            {
                for (j=1;j<4;j++)
                {
                    if (v[i][j] == 'X' || v[i][j] == 'O')
                    {
                    e++;                   
                    }
                
                }
            } 
             
  if (e == 9)
  jo = e;                        
}
  if (jo == 9)
  printf ("\n\n Jogo empatado...\n\n");
  
  else if (jo == 1)
  printf ("Parabens jogador, voce venceu! \n");

  else
  printf ("Que pena... voce perdeu! tente novamente... a pratica leva a perfeição!\n");  
        
for (i=0;i<5;i++)
{
especial [i] = getch();
putch ('*');
}
if (especial[0]=='R' && especial[1]=='E' && especial[2]=='S' && especial[3]=='E'&& especial[4]=='T')
{
puts ("Código aceito, aguarde um instante...");
_sleep (1000);
goto inicio;
}
}




#include "miniwin.h"
using namespace miniwin;

const int XTAM = 80, YTAM= 40;
const int sz =12;

void cuadrado (int x, int y, int c){
    color(c);
    rectangulo_lleno(x*sz, y*sz, (x+1)*sz-1,(y+1)*sz-1);
}

int main() {
    /**DECLARACIONES DE DATOS DEL JUEGO*/
    vredimensiona(XTAM*sz,YTAM*sz);
    int t=tecla();
    int x=30, y=20; //CABEZA
    int vx=0, vy=0; //VELOCIDAD
    int retraso =0;

    while(t!=ESCAPE){

        /**CONTROL DE MANDO*/
             if (t==ARRIBA)     {cuadrado(x,y,VERDE); vx=0; vy=-1;  }
        else if (t==ABAJO)      {cuadrado(x,y,VERDE); vx=0; vy=1;   }
        else if (t==IZQUIERDA)  {cuadrado(x,y,VERDE); vx=-1; vy=0;  }
        else if (t==DERECHA)    {cuadrado(x,y,VERDE); vx=1; vy=0;   }

        /**TEMPORIZADOR */
        retraso++;
        if (retraso==10){
        x+=vx;
        y+=vy;
        retraso=0;
        }

        /**CONTROL DE SPRITE*/
        borra();
        cuadrado(x,y,VERDE);
        refresca();

        /**TIEMPO EN MILISEGUNDOS*/
        espera(10);

        /**CAPTAR INSTRUCCION DEL MANDO*/
        t = tecla();

    }/** FIN DEL WHILE*/
    vcierra();
   return 0;
}


#include "raylib.h"
#include "Particula.h"
#include <cmath>
#include <iostream>

const int screenWidth = 1200;
const int screenHeight = 800;


using namespace std;

void pintarParticula(const Particula & p, Color c) {
    DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
}


void pintaLinea(const Particula & p1, const Particula & p2, Color c){
    DrawLine(p1.GetX(), p1.GetY(), p2.GetX(), p2.GetY(), c);
    
}


int main(void) {
    // activación de ventana gráfica
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Modulo de prueba");

    // creación de objetos
    float centroY = screenHeight / 2.0;
    float centroX = screenWidth / 2.0;
    //---------------------------------------------------------
    Particula bola1(centroX - 50, centroY,  -13.0,  -13.0, 5);
    Particula bola2(centroX, centroY + 50 , -10.0,  13.0, 5);
    
    Particula *fija = &bola1;
    Particula *movil = &bola2;
    Particula *aux;
    
    SetTargetFPS(45); // velocidad de la simulación
    //----------------------------------------------------------

    int grados = 3;
    
    double rads = grados * (M_PI/180.0);
    bool continuar = true;
    char dir;

    // bucle principal
    //---------------------------------------------------------
    int tick = 0;
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        
          movil->Rotar(fija->GetX(), fija->GetY(), rads);
          
          if (tick > (360 / 5)){
              
              //fija->Mover(screenWidth, screenHeight);
              aux = movil;
              movil = fija;
              fija = aux;
              tick = 0;
          }

        //-----------------------------------------------------
        // pintar los objetos
        //-----------------------------------------------------
        BeginDrawing();

         ClearBackground(RAYWHITE);
 
         pintaLinea(*fija, *movil, BLACK);
         pintarParticula(*fija, RED);
         pintarParticula(*movil, BLUE);
         string s = "ticks: " + to_string(tick);
         DrawText(s.c_str(), 10, 10, 10, BLACK);
         DrawText("ESC para salir", 60, 10, 20, BLACK);
        
        
        EndDrawing();
        
        tick++;
        //-----------------------------------------------------
    }

    // cerrar ventana
    //---------------------------------------------------------
    CloseWindow(); 
    //----------------------------------------------------------

    
    return 0;
}

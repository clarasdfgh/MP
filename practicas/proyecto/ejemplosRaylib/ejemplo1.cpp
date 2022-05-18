
#include "raylib.h"
#include "Particula.h"
#include <cstdlib>
#include <cmath>

const int screenWidth = 800;
const int screenHeight = 600;
const float DESP = 4.0;

void pintarParticula(const Particula & p, Color c) {
    DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
}

int main(void) {
    // activación de ventana gráfica
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Modulo de prueba");

    // creación de objetos
    //---------------------------------------------------------
    Particula bola1(screenWidth / 2.0, screenHeight / 2.0,  3.0,  3.0, 20);
    Particula bola2(screenWidth / 2.0, screenHeight / 2.0, -3.0,  3.0, 20);
    Particula bola3(screenWidth / 2.0, screenHeight / 2.0,  3.0, -3.0, 20);
    Particula bola4(screenWidth / 2.0, screenHeight / 2.0, -3.0, -3.0, 20);
    
    SetTargetFPS(50); // velocidad de la simulación
    //----------------------------------------------------------

    
    bool continuar = true;
    char dir;

    // bucle principal
    //---------------------------------------------------------

	// Mientras no se cierra la ventana o se pulse ESC 
    while (!WindowShouldClose()) 
    {   
	// actualizar estado de los objetos
          bola1.Mover(screenWidth, screenHeight);
          bola1.RebotaBordes(screenWidth, screenHeight);

          bola2.Mover(screenWidth, screenHeight);
          bola2.RebotaBordes(screenWidth, screenHeight);

          bola3.Mover(screenWidth, screenHeight);
          bola3.RebotaBordes(screenWidth, screenHeight);

          bola4.Mover(screenWidth, screenHeight);
          bola4.RebotaBordes(screenWidth, screenHeight);
          
        

        //-----------------------------------------------------
        // pintar los objetos
        //-----------------------------------------------------
        BeginDrawing();

         ClearBackground(RAYWHITE);
 
         pintarParticula(bola1, RED);
         pintarParticula(bola2, BLUE);
         pintarParticula(bola3, BLACK);
         pintarParticula(bola4, GREEN);
         

 
        DrawText("ESC para salir", 10, 10, 20, BLACK);
        EndDrawing();
        //-----------------------------------------------------
    }

    // cerrar ventana
    //---------------------------------------------------------
    CloseWindow(); 
    //----------------------------------------------------------

    
    // liberar memoria si la hubiera
    return 0;
}

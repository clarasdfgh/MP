
#include "raylib.h"
#include "particula.h"

const int screenWidth = 800;
const int screenHeight = 450;
const float  DESP = 4.0;


void pintarParticula(const  Particula & p, Color c){
    Vector2 pos = {p.GetX(), p.GetY()};
    DrawCircleV(pos, p.GetRadio(), c);
}

char Direccion(){
    char dir = ' ';
       if (IsKeyDown(KEY_UP))
            dir = 'U';
        
        if (IsKeyDown(KEY_DOWN))
            dir = 'D';
        
        if (IsKeyDown(KEY_LEFT))
            dir = 'L';
        
        if (IsKeyDown(KEY_RIGHT))
            dir = 'R';

        return dir;
}

int main(void)
{
    // Initializar ventana y objetos
    //---------------------------------------------------------
    

    InitWindow(screenWidth, screenHeight, "Modulo de prueba");

    Particula bola(GetScreenWidth()/3.0f, GetScreenHeight()/2.0f , 5.0, 4.0, 20);
 
    Particula manual(GetScreenWidth()/2.0f, GetScreenHeight()/2.0f, DESP, DESP, 15);
    
    SetTargetFPS(50);
    //----------------------------------------------------------

    char dir;
    // bucle principal
    while (!WindowShouldClose())    
    {
        // actualizar objetos
        //-----------------------------------------------------
            dir = Direccion();
            
            manual.MoverGrid(dir, screenWidth, screenHeight);
            
            bola.Mover(screenWidth, screenHeight);
            bola.RebotaBordes(screenWidth, screenHeight);
            
        //-----------------------------------------------------
        // Dibujar
        //-----------------------------------------------------
        BeginDrawing();

          ClearBackground(RAYWHITE);
          pintarParticula(bola, RED);
          pintarParticula(manual, BLACK);
	  DrawText("Mueve la bola negra con las flechas", 10, 10 , 20, BLACK);                
          DrawText("ESC para salir", 10, 30 , 20, BLACK);                
                
            
        EndDrawing();
        //-----------------------------------------------------
    }

    
    //---------------------------------------------------------
    CloseWindow();        
    //----------------------------------------------------------

    return 0;
}

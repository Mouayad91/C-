#include "raylib.h"

int main() {

int height {1000};
int width {900};
// popup a window (width, height , title)
InitWindow (height, width , "BORING GAME");


int c_x {20};
int c_y {450};
int c_radius {20};
// Edges
 int l_c_x {c_x - c_radius};
 int r_c_x {c_x + c_radius};
 int u_c_y {c_y - c_radius};
 int b_c_y {c_y + c_radius};


//box 1 coords 
int b_xo {100};
int b_yo {0};
int b_leno {20};
//Box 1 Edges 
int lo_x {b_xo};
int ro_x {b_xo + b_leno};
int uo_y {b_yo};
int bo_y {b_yo + b_leno};

//Box 2 coords
int b_x1 {300};
int b_y1 {0};
int b_len1 {30};
//Box 2 Edges
int l1_x {b_x1};
int r1_x {b_x1 + b_len1};
int u1_y {b_y1};
int b1_y {b_y1 + b_len1};
//Box 3 coords
int b_x2{500};
int b_y2 {0};
int b_len2 {40};
//Box 3 Edges
int l2_x {b_x2};
int r2_x {b_x2 + b_len2};
int u2_y {b_y2};
int b2_y {b_y2 + b_len2};
//box 4 coords
int b_x3{700};
int b_y3 {0};
int b_len3 {50};
//Box 4 Edges
int l3_x {b_x3};
int r3_x {b_x3 + b_len3};
int u3_y {b_y3};
int b3_y {b_y3 + b_len3};
// direction change the directions to make it hard or easy.
int diro {10};
int dir1 {15}; 
int dir2 {20}; 
int dir3 {25}; 


int L_SPosX{900};
int L_SposY{0};
int L_EposX{900};
int L_Eposy {900};

// collision
bool coll_boo = (bo_y >= u_c_y)&&
                (uo_y <= b_c_y) &&
                (ro_x >= l_c_x) &&
                (lo_x <= r_c_x);

bool coll_boo1 = (b1_y >= u_c_y)&&
                (u1_y <= b_c_y) &&
                (r1_x >= l_c_x) &&
                (l1_x <= r_c_x);

bool coll_boo2 = (b2_y >= u_c_y)&&
                (u2_y <= b_c_y) &&
                (r2_x >= l_c_x) &&
                (l2_x <= r_c_x);

bool coll_boo3 = (b3_y >= u_c_y)&&
                (u3_y <= b_c_y) &&
                (r3_x >= l_c_x) &&
                (l3_x <= r_c_x);

bool coll_Line = (L_SPosX >= u_c_y)&&
                 (L_SposY <= b_c_y) &&
                 (L_EposX >= l_c_x)&&
                 (L_Eposy <= r_c_x);

SetTargetFPS (60);

// keep the window open
while ( WindowShouldClose() == false){


// Start Logic



BeginDrawing();
ClearBackground (GRAY);


if (coll_boo || coll_boo1 || coll_boo2 || coll_boo3){

  DrawText ("Game Over!, please do not be sad and try again, cause i know it is boring game ^_^", 70, 200, 20, RED);
}
else{
  
  // UPDATE 

  l_c_x = c_x - c_radius;
  r_c_x = c_x + c_radius;
  u_c_y = c_y - c_radius;
  b_c_y = c_y + c_radius;

  // UPDATE  B1

  lo_x = b_xo;
  ro_x = b_xo + b_leno;
  uo_y = b_yo;
  bo_y = b_yo + b_leno;
 
  // UPDATE B2

  l1_x = b_x1;
  r1_x = b_x1 + b_len1;
  u1_y = b_y1;
  b1_y = b_y1 + b_len1;

  // UPDATE B3


  l2_x = b_x2;
  r2_x = b_x2 + b_len2;
  u2_y = b_y2;
  b2_y = b_y2 + b_len2;

  // UPDATE B4

  l3_x = b_x3;
  r3_x = b_x3 + b_len3;
  u3_y = b_y3;
  b3_y = b_y3 + b_len3;

  coll_boo =    (bo_y >= u_c_y)&&
                (uo_y <= b_c_y) &&
                (ro_x >= l_c_x) &&
                (lo_x <= r_c_x);


coll_boo1 = (b1_y >= u_c_y)&&
                (u1_y <= b_c_y) &&
                (r1_x >= l_c_x) &&
                (l1_x <= r_c_x);

coll_boo2 = (b2_y >= u_c_y)&&
                (u2_y <= b_c_y) &&
                (r2_x >= l_c_x) &&
                (l2_x <= r_c_x);


coll_boo3 = (b3_y >= u_c_y)&&
                (u3_y <= b_c_y) &&
                (r3_x >= l_c_x) &&
                (l3_x <= r_c_x);






//Game Logic
// Circle (width, hight, radius, color)
DrawCircle(c_x, c_y, c_radius, YELLOW);
//Rectangle (posx, posy , width, height, color)
DrawRectangle(b_xo, b_yo, b_leno, b_leno , GREEN);
DrawRectangle(b_x1, b_y1 , b_len1 , b_len1 , RED);
DrawRectangle(b_x2, b_y2 , b_len2 , b_len2 , ORANGE);
DrawRectangle (b_x3, b_y3 , b_len3 , b_len3 , PURPLE);
DrawLine(L_SPosX, L_SposY,L_EposX,L_Eposy,YELLOW);



//Box movement
b_yo += diro;
b_y1 += dir1;
b_y2 += dir2;
b_y3 += dir3;

if (b_yo > height - 120 || b_yo < 0){

diro = - diro;

}

if (b_y1 > height - 120 || b_y1 < 0){

dir1 = - dir1;

}
if (b_y2 > height - 120 || b_y2 < 0){

dir2 = - dir2;

}
if (b_y3 > height - 120 || b_y3 < 0){

dir3 = - dir3;

}


if(IsKeyDown(KEY_D) && c_x < width){

  c_x += 4;
}
if(IsKeyDown(KEY_A) && c_x < width){
  c_x -= 4;
}
if(IsKeyDown(KEY_W) && c_y < width){
  c_y -= 4;
}
if(IsKeyDown(KEY_S) && c_y < width){
  c_y += 4;
}


}


// player win the game, if he reach the yellow line

if(coll_Line){


  DrawText (" Congrats You Win!", 250, 200, 50 , PINK);

}else{



  l_c_x = c_x - c_radius;
  r_c_x = c_x + c_radius;
  u_c_y = c_y - c_radius;
  b_c_y = c_y + c_radius;


coll_Line = (L_SPosX >= u_c_y)&&
                 (L_SposY <= b_c_y) &&
                 (L_EposX >= l_c_x)&&
                 (L_Eposy <= r_c_x);


}


//logic Ends
EndDrawing();
    
}

}
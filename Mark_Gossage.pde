int x=0,y=0,z=0;
int keyReset=0;
int arr[]=new int[64];
//int arr[]=new int[]{1,0,0,1, 0,0,1,1, 0,0,0,0, 1,1,1,1, 
//                    0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 
//                    0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 
//                    1,1,1,1, 0,0,0,0, 0,0,0,0, 0,0,0,0, };

void draw_cube64(int arr[]){
  float cx=width/2-150, cy=height/2-150, cz=-200;
  float rx=-0.17, ry=-0.15;
  
  // grid
  noFill();
  stroke(255);
  for(float i=0;i<3;i++) {
    for(float j=0;j<3;j++) {
      for(float k=0;k<3;k++) {
        float x=cx + 150 * i;
        float y=cy + 150 * j;
        float z=cz + 150 * k;
        pushMatrix();
        rotateX(rx);
        rotateY(ry);
        translate(x,y,z);
        box(150);
        popMatrix();
      }
    }
  }
  // dots:
  fill(255);
  noStroke();
  for(int i=0;i<arr.length;i++) {
    if (arr[i]!=0) {
      float x=cx + 150 * (i%4-0.5);
      float y=cy + 150 * (i/4%4-0.5);
      float z=cz + 150 * (i/16-0.5);
      fill(155+(i/16)*25);  // darker if further away
      pushMatrix();
      rotateX(rx);
      rotateY(ry);
      translate(x,y,z);
      box(50);
      popMatrix();
    }
  }
}

void setup() {
  size(800,800,P3D);
  for(int i=0;i<64;i++){
    arr[i]=0;
  }
  arr[0]=1;
}

void draw() {
  background(0);
  lights();
  
  if (keyPressed==true && keyReset<=0){
    keyReset=20;
    if (key=='a') x=(x+3)%4;
    if (key=='d') x=(x+1)%4;
    if (key=='w') z=(z+3)%4;
    if (key=='s') z=(z+1)%4;
    if (key=='r') y=(y+3)%4;
    if (key=='f') y=(y+1)%4;
    // update arr
    for(int i=0;i<64;i++){
      arr[i]=0;
    }
    arr[x+y*4+z*16]=1;
  }
  keyReset--;
  
  
  draw_cube64(arr);
  // text display of the array
  String s="";
  for(int i=0;i<64;i++){
    s+=arr[i];
  }  
  text(s,20,20);
}
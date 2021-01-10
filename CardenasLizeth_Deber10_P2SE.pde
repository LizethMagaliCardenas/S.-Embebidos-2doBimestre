float x=0;
float y=0;

void setup (){
  size(640,480);
  background(0);
}
void draw(){
background(0);
ellipse((width/2)+x,(height/2)+y,30,30);
if(keyPressed && key==CODED){
  if(keyCode==LEFT){
    x=x-10;
  }
  else if(keyCode==RIGHT){
    x=x+10;
  }
  else if(keyCode==UP){
    y=y-10;
  }
  else if(keyCode==DOWN){
    y=y+10;
  }
  if ((x+320)<=0){
    x=x+10;
  }
  if((x+320)>=width){
    x=x-10;
  }
  if((y+240)<=0){
    y=y+10;
  }
  if((y+240)>=height){
    y=y-10;
  }
 }    
}

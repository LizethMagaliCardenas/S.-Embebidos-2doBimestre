/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS 
 * APRENDIZAJE DE MAQUINA -REGRESION LOGARÍTMICA
 * Nombre: Magali Cárdenas
 * Fecha:20/01/2021
 */
// matriz de datos
int matriz[14][2]={
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
};

int col=0; //moverse en columnas
int fil=0; //moverse en filas
int Ex=0; //sumatoria x
int Ey=0; //sumatoria y
float Exy=0; //sumatoria x*y
long int Ex2=0; //sumatoria x^2
long int Ex_2=0; //sumatoria Ex^2
int n= 14; //tama;o de muestras
float Bo; //ordenada en el origen
float Pendlog; //pendiente
String dato; //recibir estatura
int estatura; //convertir dato
float p;
float m1=0;// auxiliar de desbordamiento
float peso;//variable de peso
float ylog=0; //consta logaritmica

void setup() {
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Ey=Ey+matriz[fil][1];
    ylog=ylog+log(matriz[fil][1]);
    Exy=Exy+(matriz[fil][0]*log(matriz[fil][1]));
    Ex2=Ex2+pow(matriz[fil][0],2);
  }
  Ex_2=pow(Ex,2);
  Bo=((float(n*Exy)-float(Ex*ylog))/(float(n*Ex2)-float(Ex_2)));
  m1=float(Bo*(Ex/n));
  Pendlog=(float(ylog/n))-m1;
  p=float(exp(Pendlog));
  Serial.println("El modelo es: ");
  Serial.println(String("y= ")+String(p)+String("e^(")+String(Bo)+String("*x)"));
  Serial.println("Ingrese su estatura: ");
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    estatura=dato.toInt();
    peso=p*exp(Bo*estatura);
    Serial.println("");
    Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura: ");
  }
}

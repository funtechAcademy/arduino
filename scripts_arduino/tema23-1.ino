// Fun Tech Academy 2022

void setup()
{ 
   for ( int i=2 ; i<10 ; i++)
   pinMode( i, OUTPUT);
}

void loop()
{ 
   for (int j=2; j<10 ; j++)  
   {
      digitalWrite( j, HIGH);
      delay(300);
      digitalWrite( j, LOW) ;
      delay(300);
   }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT); //Fabbro movimento
  pinMode(7,OUTPUT); // Fuoco fabbro
  pinMode(10,OUTPUT); // Falegname
  pinMode(6,OUTPUT); // Luci falegname
  pinMode(8,OUTPUT); // Panettiere
  pinMode(4,OUTPUT); // Movimento arrotino
  pinMode(9,OUTPUT); // Luce montagna e mestieri
  pinMode(5,OUTPUT); // Luci paese
  // inizializzo tutti i pin per tenere il circuito aperto
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //LOW chiude il relè e quindi il circuito
  //HIGH lo tiene aperto
  int panettiere = 8, arrotino = 4, fabbro = 11, fabbrof = 7, falegname = 10, falegnameluci = 6;
  int lucim = 9, lucip = 5;
  unsigned long mattino = 120000;
  unsigned long pranzo = 30000;
  unsigned long pomeriggio = 120000;
  unsigned long sera = 30000;
  unsigned long notte = 120000;
  int warmup = 5000;
  // il giorno parte dal mattino
  digitalWrite(lucip, LOW); //accensione luci paese
  delay(warmup);
  digitalWrite(lucim, LOW); //accensione luci montanga e mestieri
  digitalWrite(panettiere, LOW); //il paniettiere continua a lavorare dalla notte
  delay(1000);
  digitalWrite(fabbrof, LOW); //accendo il fuoco del fabbro
  digitalWrite(falegnameluci, LOW); //accensione luci falegname
  delay(warmup*2); //attendo 5 secondi
  digitalWrite(fabbro, LOW); //il fabbro inizia a lavorare
  digitalWrite(falegname, LOW); //il falegname inizia a lavorare
  digitalWrite(arrotino, LOW); //arrotino inizia a lavorare
  delay(mattino);
  digitalWrite(fabbro, HIGH); //pausa pranzo fabbro
  digitalWrite(falegname, HIGH); //pausa pranzo falegname
  digitalWrite(arrotino, HIGH); //pausa pranzo arrotino
  delay(pranzo);
  digitalWrite(panettiere, HIGH); //panettiere va a dormire
  digitalWrite(arrotino, LOW);
  digitalWrite(falegname, LOW);
  digitalWrite(fabbro, LOW);
  delay(pomeriggio);
  digitalWrite(arrotino, HIGH);
  digitalWrite(falegname, HIGH);
  digitalWrite(fabbro, HIGH);
  delay(sera);
  digitalWrite(falegnameluci, HIGH);
  delay(1000);
  digitalWrite(fabbrof, HIGH);
  delay(1000);
  digitalWrite(panettiere, LOW);
  delay(2000);
  digitalWrite(lucim, HIGH);
  delay(2000);
  digitalWrite(lucip, HIGH);
  delay(notte);
}

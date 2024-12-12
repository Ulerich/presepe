# Codice configurazione Arduino/Raspberry luci presepe

Codice per la gestione di una scheda Relè collegata ad un presepe per simulare il ciclo notte giorno attraverso l'accensione e lo spegnimento temporizzato di luci e motori per la gestione dei lavori.

## Materiale utilizzato

Scheda "Yizhet 8 Canali Relay Modulo DC 5V" Relè con accoppiatore ottico per Arduino Raspberry Pi (acquistabile su Amazon a circa € 12).

## File

Presente il codice .ino per Arduino e codice py per Rasberry.

## Prese di corrente totali 13, Utilizzate 11

- 1 Presa dirette - Capanna
- 8 Prese gestite da Relè

## Oggetti gestiti da Relè

- Fabbro (2 prese - Luce e Movimento)
- Panettiere 1 presa
- Falegname 2 prese (Luce e Movimento)
- Arrotino 1 presa
- Luci (2 file gestite da una presa)
- Mulino 1 presa

## Oggetti non gestiti (corrente diretta)

- Capanna

# Arduino Pin utilizzati

Dal Pin 4-11 gestione Relè

# Python
 Directory script

/home/ulerich/presepe.py

Aggiungi un shebang all’inizio del file per specificare l’interprete Python:

#!/usr/bin/env python3

Rendi lo script eseguibile:

chmod +x /home/pi/presepe.py

2. Creare un File di Servizio

Crea un nuovo file di configurazione per il servizio in:

/etc/systemd/system/presepe.service

Usa un editor di testo per crearlo:

sudo nano /etc/systemd/system/presepe.service

Inserisci il seguente contenuto:

[Unit]
Description=Script per il controllo dei relè del presepe
After=network.target

[Service]
ExecStart=/usr/bin/python3 /home/pi/presepe.py
WorkingDirectory=/home/pi
StandardOutput=inherit
StandardError=inherit
Restart=always
User=pi

[Install]
WantedBy=multi-user.target

Dettagli del File di Servizio
	•	Description: Una breve descrizione del servizio.
	•	After: Specifica che il servizio parte dopo che la rete è pronta (opzionale, utile se usi rete o WiFi).
	•	ExecStart: Comando per eseguire il tuo script. Modifica il percorso se necessario.
	•	WorkingDirectory: La directory in cui lo script viene eseguito.
	•	Restart: Assicura che il servizio venga riavviato in caso di crash.
	•	User: L’utente che eseguirà lo script (di solito pi sul Raspberry Pi).

3. Abilitare e Avviare il Servizio

Dopo aver creato il file, abilita il servizio per avviarlo automaticamente all’accensione:

sudo systemctl enable presepe.service

Avvia il servizio immediatamente:

sudo systemctl start presepe.service

Verifica lo stato del servizio:

sudo systemctl status presepe.service

Gestire il Servizio con systemctl
	•	Controllare lo stato:

sudo systemctl status presepe.service


	•	Riavviare il servizio:

sudo systemctl restart presepe.service


	•	Interrompere il servizio:

sudo systemctl stop presepe.service


	•	Disabilitare l’avvio automatico:

sudo systemctl disable presepe.service

Test e Debug
	1.	Se il servizio non funziona, verifica i log con:

sudo journalctl -u presepe.service


	2.	Assicurati che il percorso dello script e di Python siano corretti.
	3.	Se il tuo script usa GPIO, assicurati che venga eseguito con i permessi corretti (di solito come utente pi).

Con questa configurazione, il tuo script Python verrà avviato automaticamente all’accensione del Raspberry Pi e sarà gestibile tramite systemctl.
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

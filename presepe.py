import RPi.GPIO as GPIO
import time

# Imposta la modalità di numerazione dei pin
GPIO.setmode(GPIO.BCM)

# Definisci i pin GPIO collegati ai relè
pin_relè = [29, 31, 32, 33, 35, 36, 37, 38]
fabbro_luce = 29
fabbro_mov = 31
falegname_luce = 32
falegname_mov = 33
panettiere = 35
arrotino = 36
mulino = 37
luci = 38

# Imposta i pin come output
GPIO.setup(pin_relè, GPIO.OUT)

def accendi_luci():
    print("Accensione luci")
    GPIO.output(pin_relè, GPIO.HIGH)

def spegni_luci():
    print("Spegnimento luci")
    GPIO.output(pin_relè, GPIO.LOW)

try:
    while True:
        # Simulazione del ciclo giorno/notte (modifica secondo le tue esigenze)
        accendi_luci()
        time.sleep(10)  # Accendi le luci per 10 secondi
        spegni_luci()
        time.sleep(10)  # Spegni le luci per 10 secondi

except KeyboardInterrupt:
    pass

finally:
    # Ripristina i pin GPIO allo stato iniziale
    GPIO.cleanup()

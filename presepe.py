import RPi.GPIO as GPIO
import time

# Configurazione GPIO
RELAY_PINS = [17, 27, 22, 23, 24, 25, 16, 26]  # GPIO dei relè

panettiere = 1
lavoro1 = 2
falegname = 3
vuoto = 4
luci_paese = 5
luci_grotta = 7
fabbro = 0
GPIO.setmode(GPIO.BCM)
for pin in RELAY_PINS:
    GPIO.setup(pin, GPIO.OUT)  # Configura ogni pin come OUTPUT

def spegni_rele(index):
    GPIO.output(RELAY_PINS[index], GPIO.HIGH)

def accendi_rele(index):
    GPIO.output(RELAY_PINS[index], GPIO.LOW)

def accendi_rele_unico(index):
    """Spegne tutti i relè, quindi accende solo quello specificato."""
    spegni_tutti()
    GPIO.output(RELAY_PINS[index], GPIO.LOW)  # Accende il relè specificato

def spegni_tutti():
    """Spegne tutti i relè."""
    for pin in RELAY_PINS:
        GPIO.output(pin, GPIO.HIGH)

try:
    spegni_tutti()
    accendi_rele(7)
    time.sleep(5)
    while True:
        accendi_rele(1)
        time.sleep(10)
        accendi_rele(5)
        time.sleep(10)
        accendi_rele(2)
        accendi_rele(3)
        accendi_rele(0)
        time.sleep(20)
        spegni_rele(2)
        spegni_rele(3)
        spegni_rele(0)
        time.sleep(10)
        spegni_rele(1)
        accendi_rele(2)
        accendi_rele(3)
        accendi_rele(0)
        time.sleep(20)
        spegni_rele(2)
        time.sleep(2)
        spegni_rele(0)
        spegni_rele(3)
        time.sleep(5)
        spegni_rele(5)
        time.sleep(15)
except KeyboardInterrupt:
    print("Pulizia GPIO")
    GPIO.cleanup()

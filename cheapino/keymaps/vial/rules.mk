VIAL_ENABLE = yes
COMBO_ENABLE = yes
VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
ENCODER_ENABLE = yes
QMK_SETTINGS = yes

# Seed the six user-requested Vial combos into EEPROM on first boot.
OPT_DEFS += -DCHEAPINO_VIAL_DEFAULT_COMBOS
